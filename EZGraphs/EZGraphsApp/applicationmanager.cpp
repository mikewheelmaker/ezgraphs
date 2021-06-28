#include <QCoreApplication>

#include "applicationmanager.h"

ApplicationManager::ApplicationManager(QObject *parent) : QObject(parent)
{
    m_functionManager = new FunctionManager(this);
    connect(m_functionManager, &FunctionManager::newValueChanged, this, &ApplicationManager::onValueCalculated);
}

void ApplicationManager::buttonClicked(ButtonFunctions choice)
{
    switch(choice)
    {
    case NewCanvas:
        //call method to create new canvas
        qDebug() << "call new canvas method";
        break;
    case AddFunction:
        //call method to add function to graph
        qDebug() << "call add function method";
        m_functionManager->calculateFunction();
        break;
    case RemoveFunction:
        //call method to remove function from graph
        qDebug() << "call remove function method";
        break;
    case ImportFunctions:
        //call method to import LaTeX functions
        qDebug() << "call import LaTeX functions method";
        break;
    case ExportFunctions:
        //call method to export LaTeX functions
        qDebug() << "call export LaTeX functions method";
        break;
    case SaveGraph:
        //call method to save current graph
        qDebug() << "call save current graph method";
        break;
    case Sync:
        //call method to sync local and remote DB
        qDebug() << "call sync method";
        break;
    case Help:
        //call method to display help window
        qDebug() << "call help method";
        break;
    case ExitApplication:
        QCoreApplication::exit();
        break;
    }
}

void ApplicationManager::onValueCalculated()
{
    m_value = m_functionManager->getNewValue();
    emit valueAdded();
}
