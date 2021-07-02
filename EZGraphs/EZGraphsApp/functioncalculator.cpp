#include "functioncalculator.h"

FunctionCalculator::FunctionCalculator(QObject *parent) : QObject(parent)
{

}

FunctionCalculator::~FunctionCalculator()
{
    clearList();
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
    default:
        for(int i = 0; i <= numberOfValues; ++i)
            tempList.append({rangeMin + i*step, rangeMin + i*step});
        break;
    }
    m_listOfFunctions.append(tempList);
    emit newFunctionAdded();
}

void FunctionCalculator::clearList()
{
    m_listOfFunctions.clear();
}

void FunctionCalculator::removeFunctionFromList(int index)
{
    m_listOfFunctions.removeAt(index);
}
