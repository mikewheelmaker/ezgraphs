#include <QCoreApplication>

#include "applicationmanager.h"

Q_LOGGING_CATEGORY(applicationManager, "[ApplicationManager]")

QMap <int, QString> Colors {
    {0, "red"},
    {1, "blue"},
    {2, "green"},
    {3, "yellow"},
    {4, "black"},
    {5, "purple"},
    {6, "cyan"},
    {7, "magenta"},
    {8, "grey"}
};

QMap <int, QString> Expressions {
    {0, "sin(x)"},
    {1, "cos(x)"},
    {2, "tg(x)"},
    {3, "exp(x)"},
    {4, "log(x)"},
    {5, "x"},
    {6, "x^2"},
    {7, "x^3"},
    {8, "1/x"}
};

ApplicationManager::ApplicationManager(QObject *parent) : QObject(parent),
    m_functionCalculator(new FunctionCalculator(this)),
    m_functionModel(new FunctionModel(this))
{
    qCDebug(applicationManager) << "Constructor called.\n";
    connect(m_functionCalculator, &FunctionCalculator::newFunctionAdded, this, &ApplicationManager::onNewFunctionAdded);
}

ApplicationManager::~ApplicationManager()
{
    qCDebug(applicationManager) << "Destructor called.\n";

    if(m_functionCalculator != nullptr)
    {
        delete m_functionCalculator;
    }

    if(m_functionModel != nullptr)
    {
        m_functionModel->clearList();
        delete m_functionModel;
    }
}

void ApplicationManager::addFunction(QString alias, int functionOption, QString rangeMin, QString rangeMax, QString step)
{
    double tempRangeMin = -5.0;
    if(!rangeMin.isEmpty())
        tempRangeMin = rangeMin.toDouble();

    double tempRangeMax = 5.0;
    if(!rangeMax.isEmpty())
        tempRangeMax = rangeMax.toDouble();

    double tempStep = 0.1;
    if(!step.isEmpty())
        tempStep = step.toDouble();

    m_currentFunctionData.alias = alias;
    m_currentFunctionData.expression = Expressions[functionOption];
    m_currentFunctionData.color = Colors[functionOption];
    m_functionModel->addItem({m_currentFunctionData.alias, m_currentFunctionData.expression, tempStep});
    m_functionCalculator->calculateFunction(functionOption, tempRangeMin, tempRangeMax, tempStep);
    qCDebug(applicationManager) << "addFunction: Successfully calculated function.\n";
}

void ApplicationManager::removeFunction()
{
    emit functionRemoved(m_currentFunctionIndex);
    m_functionCalculator->removeFunctionFromList(m_currentFunctionIndex);
    m_functionModel->removeItem(m_currentFunctionIndex);
    qCDebug(applicationManager) << "removeFunction: Successfully removed function number " << m_currentFunctionIndex << ".\n";
}

void ApplicationManager::setCurrentFunctionIndex(int index)
{
    if(m_currentFunctionIndex != index)
        m_currentFunctionIndex = index;
    qCDebug(applicationManager) << "setCurrentFunctionIndex: Successfully saved current function index.\n";
}

void ApplicationManager::clearGraph()
{
    m_functionModel->clearList();
    m_functionCalculator->clearList();
    qCDebug(applicationManager) << "clearGraph: Internal reset done.\n";
    emit functionListCleared();
}

void ApplicationManager::onNewFunctionAdded()
{
    m_currentFunctionData.values = m_functionCalculator->getNewFunctionValues();
    emit functionAdded(m_currentFunctionData.alias, m_currentFunctionData.expression, m_currentFunctionData.color, m_currentFunctionData.values.size());
    m_currentFunctionData = {};
    qCDebug(applicationManager) << "onNewFunctionAdded: Finished adding function to QML.\n";
}
