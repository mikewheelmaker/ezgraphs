#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "cachemanager.h"
#include "functionmanager.h"
#include "iomanager.h"
#include "networkhandler.h"

Q_DECLARE_LOGGING_CATEGORY(applicationManager)

enum ButtonFunctions
{
    NewCanvas = 0,
    AddFunction,
    RemoveFunction,
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
    Q_PROPERTY(QPointF value READ value NOTIFY valueAdded)
public:
    explicit ApplicationManager(QObject *parent = nullptr);

    Q_INVOKABLE void buttonClicked(ButtonFunctions choice);

    QPointF value() const { return m_value; };

signals:
    void valueAdded();

public slots:
    void onValueCalculated();

private:
    CacheManager *m_cacheManager;
    FunctionManager *m_functionManager;
    IOManager *m_ioManager;
    NetworkHandler *m_networkHandler;
    QPointF m_value;
};

#endif // APPLICATIONMANAGER_H
