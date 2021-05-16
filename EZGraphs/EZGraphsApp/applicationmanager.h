#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include <QObject>

#include "cachemanager.h"
#include "functionmanager.h"
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
public:
    explicit ApplicationManager(QObject *parent = nullptr);

    Q_INVOKABLE void buttonClicked(ButtonFunctions choice);

signals:

private:
    CacheManager *m_cacheManager;
    FunctionManager *m_functionManager;
    IOManager *m_ioManager;
    NetworkHandler *m_networkHandler;

};

#endif // APPLICATIONMANAGER_H
