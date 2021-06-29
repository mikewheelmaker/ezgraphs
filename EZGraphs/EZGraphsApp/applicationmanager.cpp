#include <QCoreApplication>

#include "applicationmanager.h"

QMap <int, QString> Colors {
    {0, "red"},
    {1, "blue"},
    {2, "green"},
    {3, "yellow"},
    {4, "black"}
};

QMap <int, QString> Names {
    {0, "Sinus"},
    {1, "Cosinus"},
    {2, "Tangent"},
    {3, "Exponential"},
    {4, "DEFAULT"}
};

QMap <int, QString> Expressions {
    {0, "sin(x)"},
    {1, "cos(x)"},
    {2, "tg(x)"},
    {3, "exp(x)"},
    {4, "x"}
};

ApplicationManager::ApplicationManager(QObject *parent) : QObject(parent)
{
    m_functionCalculator = new FunctionCalculator(this);
    m_functionModel = new FunctionModel(this);
    connect(m_functionCalculator, &FunctionCalculator::newFunctionAdded, this, &ApplicationManager::onNewFunctionAdded);
}

void ApplicationManager::buttonClicked(ButtonFunctions choice)
{
    switch(choice)
    {
    case NewCanvas:
        //call method to create new canvas
        qDebug() << "call new canvas method";
        m_functionModel->clearList();
        m_functionCalculator->clearList();
        emit listCleared();
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

void ApplicationManager::addFunction(QString option, QString rangeMin, QString rangeMax, QString step)
{
    int tempKey = Names.key(option, -1);
    if(Names.count(tempKey) == 0)
    {
        tempKey=4;
    }

    double tempRangeMin = -5.0;
    if(!rangeMin.isEmpty())
        tempRangeMin = rangeMin.toDouble();

    double tempRangeMax = 5.0;
    if(!rangeMax.isEmpty())
        tempRangeMax = rangeMax.toDouble();

    double tempStep = 0.1;
    if(!step.isEmpty())
        tempStep = step.toDouble();

    m_currentFunctionData.alias = Names[tempKey];
    m_currentFunctionData.latexExpression = Expressions[tempKey];
    m_currentFunctionData.lineColor = Colors[tempKey];
    m_functionModel->addItem({m_currentFunctionData.alias, m_currentFunctionData.latexExpression, tempStep});
    m_functionCalculator->calculateFunction(tempKey, tempRangeMin, tempRangeMax, tempStep);
}

void ApplicationManager::removeFunction(int index)
{
    qDebug() << "call remove function method";
    if(index >=0) {
        m_currentFunctionIndex = index;
        emit functionRemoved(m_currentFunctionIndex);
        m_functionCalculator->removeFunctionFromList(m_currentFunctionIndex);
        m_functionModel->removeItem(m_currentFunctionIndex);
    }
}

void ApplicationManager::onNewFunctionAdded()
{
    m_currentFunctionData.values = m_functionCalculator->getNewFunctionValues();
    emit functionAdded(m_currentFunctionData.alias, m_currentFunctionData.latexExpression, m_currentFunctionData.lineColor, m_currentFunctionData.values.size());
    m_currentFunctionData = {};
}
