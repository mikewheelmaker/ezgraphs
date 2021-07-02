#include "functioncalculator.h"

Q_LOGGING_CATEGORY(functionCalculator, "[FunctionCalculator]")

FunctionCalculator::FunctionCalculator(QObject *parent) : QObject(parent)
{
    qCDebug(functionCalculator) << "Constructor called.\n";
}

FunctionCalculator::~FunctionCalculator()
{
    clearList();
    qCDebug(functionCalculator) << "Destructor called.\n";
}

void FunctionCalculator::calculateFunction(int option, double rangeMin, double rangeMax, double step)
{
    QList<QPointF> tempList {};
    int numberOfValues = (rangeMax-rangeMin)/step;
    switch(option) {
    case 0:
        for(int i = 0; i <= numberOfValues; ++i)
            tempList.append({rangeMin + i*step, sin(rangeMin + i*step)});
        break;
    case 1:
        for(int i = 0; i <= numberOfValues; ++i)
            tempList.append({rangeMin + i*step, cos(rangeMin + i*step)});
        break;
    case 2:
        for(int i = 0; i <= numberOfValues; ++i)
            tempList.append({rangeMin + i*step, tan(rangeMin + i*step)});
        break;
    case 3:
        for(int i = 0; i <= numberOfValues; ++i)
            tempList.append({rangeMin + i*step, exp(rangeMin + i*step)});
        break;
    case 4:
        for(int i = 0; i <= numberOfValues; ++i)
            tempList.append({rangeMin + i*step, log(rangeMin + i*step)});
        break;
    case 5:
        for(int i = 0; i <= numberOfValues; ++i)
            tempList.append({rangeMin + i*step, rangeMin + i*step});
        break;
    case 6:
        for(int i = 0; i <= numberOfValues; ++i)
            tempList.append({rangeMin + i*step, pow(rangeMin + i*step, 2)});
        break;
    case 7:
        for(int i = 0; i <= numberOfValues; ++i)
            tempList.append({rangeMin + i*step, pow(rangeMin + i*step, 3)});
        break;
    case 8:
        for(int i = 0; i <= numberOfValues; ++i)
            tempList.append({rangeMin + i*step, 1/(rangeMin + i*step)});
        break;
    default:
        for(int i = 0; i <= numberOfValues; ++i)
            tempList.append({rangeMin + i*step, sin(rangeMin + i*step)});
        break;
    }
    m_listOfFunctions.append(tempList);
    qCDebug(functionCalculator) << "calculateFunction: Finished calculation.\n";
    emit newFunctionAdded();
}

void FunctionCalculator::clearList()
{
    m_listOfFunctions.clear();
    qCDebug(functionCalculator) << "clearList: Cleared internal list of values.\n";
}

void FunctionCalculator::removeFunctionFromList(int index)
{
    m_listOfFunctions.removeAt(index);
    qCDebug(functionCalculator) << "removeFunctionFromList: Removed function number " << index << " from internal list of values.\n";
}
