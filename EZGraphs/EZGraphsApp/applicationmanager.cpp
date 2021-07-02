#include <QCoreApplication>

#include "applicationmanager.h"

Q_LOGGING_CATEGORY(applicationManager, "applicationManager.log")

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

ApplicationManager::ApplicationManager(QObject *parent) : QObject(parent),
    m_cacheManager(new CacheManager("cache.db")),
    m_functionCalculator(new FunctionCalculator(this)),
    m_functionModel(new FunctionModel(this)),
    m_ioManager(new IOManager(this->findChild<QChartView *>("functionGraph"), this))
{
    connect(m_functionCalculator, &FunctionCalculator::newFunctionAdded, this, &ApplicationManager::onNewFunctionAdded);
}

ApplicationManager::~ApplicationManager()
{
    if(m_cacheManager != nullptr)
        delete m_cacheManager;

    if(m_functionCalculator != nullptr)
    {
        m_functionCalculator->clearList();
        delete m_functionCalculator;
    }

    if(m_functionModel != nullptr)
    {
        m_functionModel->clearList();
        delete m_functionModel;
    }

    if(m_ioManager != nullptr)
        delete m_ioManager;
}

void ApplicationManager::addFunction(QString alias, QString expression, QString rangeMin, QString rangeMax, QString step)
{
    int tempKey = Names.key(alias, -1);
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

    m_currentFunctionData.alias = alias;
    m_currentFunctionData.latexExpression = Expressions[tempKey];
    m_currentFunctionData.lineColor = Colors[tempKey];
    m_functionModel->addItem({m_currentFunctionData.alias, m_currentFunctionData.latexExpression, tempStep});
    m_functionCalculator->calculateFunction(tempKey, tempRangeMin, tempRangeMax, tempStep);
}

void ApplicationManager::removeFunction()
{
    qDebug() << "call remove function method";
    emit functionRemoved(m_currentFunctionIndex);
    m_functionCalculator->removeFunctionFromList(m_currentFunctionIndex);
    m_functionModel->removeItem(m_currentFunctionIndex);
}

void ApplicationManager::setCurrentFunctionIndex(int index)
{
    if(m_currentFunctionIndex != index)
        m_currentFunctionIndex = index;
}

void ApplicationManager::saveGraph(int option, QString fileName)
{
    m_ioManager->saveGraph(option, fileName);
}

void ApplicationManager::clearGraph()
{
    qDebug() << "call clear graph method";
    m_functionModel->clearList();
    m_functionCalculator->clearList();
    emit functionListCleared();
}

void ApplicationManager::openHelp()
{
    qDebug() << "call open help method";
    m_ioManager->openHelp();
}

void ApplicationManager::onNewFunctionAdded()
{
    m_currentFunctionData.values = m_functionCalculator->getNewFunctionValues();
    emit functionAdded(m_currentFunctionData.alias, m_currentFunctionData.latexExpression, m_currentFunctionData.lineColor, m_currentFunctionData.values.size());
    m_currentFunctionData = {};
}
