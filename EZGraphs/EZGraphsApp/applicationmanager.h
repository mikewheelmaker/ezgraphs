#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "functioncalculator.h"
#include "functionmodel.h"

Q_DECLARE_LOGGING_CATEGORY(applicationManager)

class ApplicationManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel *functionModel READ model CONSTANT)
    Q_PROPERTY(QList<QPointF> currentFunctionValues READ currentFunctionValues CONSTANT)
public:

public:
    explicit ApplicationManager(QObject *parent = nullptr);
    virtual ~ApplicationManager();

    FunctionModel *model() const { return m_functionModel; };

    Q_INVOKABLE void addFunction(QString alias, int functionOption, QString rangeMin, QString rangeMax, QString step);
    Q_INVOKABLE void removeFunction();
    Q_INVOKABLE void setCurrentFunctionIndex(int index);
    Q_INVOKABLE void clearGraph();

    QList<QPointF> currentFunctionValues() const { return m_currentFunctionData.values; };

signals:
    void functionAdded(QString alias, QString expression, QString color, int numberOfValues);
    void functionRemoved(int index);
    void functionListCleared();

public slots:
    void onNewFunctionAdded();

private:
    FunctionCalculator *m_functionCalculator;
    FunctionModel *m_functionModel;

    FunctionData m_currentFunctionData {};
    int m_currentFunctionIndex = -1;
};

#endif // APPLICATIONMANAGER_H
