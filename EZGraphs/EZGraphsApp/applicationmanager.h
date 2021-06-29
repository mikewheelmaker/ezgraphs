#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "cachemanager.h"
#include "functioncalculator.h"
#include "functionmodel.h"
#include "iomanager.h"
#include "networkhandler.h"

Q_DECLARE_LOGGING_CATEGORY(applicationManager)

enum ButtonFunctions
{
    NewCanvas = 0,
    ImportFunctions,
    ExportFunctions,
    SaveGraph,
    Sync,
    Help,
    ExitApplication
};

class ApplicationManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel *functionModel READ model CONSTANT)
    Q_PROPERTY(QList<QPointF> currentFunctionValues READ currentFunctionValues CONSTANT)
public:
    explicit ApplicationManager(QObject *parent = nullptr);

    FunctionModel *model() const { return m_functionModel; };

    Q_INVOKABLE void buttonClicked(ButtonFunctions choice);
    Q_INVOKABLE void addFunction(QString option, QString rangeMin, QString rangeMax, QString step);
    Q_INVOKABLE void removeFunction(int index);

    QList<QPointF> currentFunctionValues() const { return m_currentFunctionData.values; };

signals:
    void functionAdded(QString alias, QString expression, QString color, int numberOfValues);
    void functionRemoved(int index);
    void listCleared();

public slots:
    void onNewFunctionAdded();

private:
    CacheManager *m_cacheManager;
    FunctionCalculator *m_functionCalculator;
    FunctionModel *m_functionModel;
    IOManager *m_ioManager;
    NetworkHandler *m_networkHandler;
    FunctionData m_currentFunctionData;
    int m_currentFunctionIndex = -1;
};

#endif // APPLICATIONMANAGER_H
