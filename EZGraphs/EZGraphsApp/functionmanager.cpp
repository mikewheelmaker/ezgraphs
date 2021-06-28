#include "functionmanager.h"

FunctionManager::FunctionManager(QObject *parent) : QObject(parent)
{

}

void FunctionManager::calculateFunction()
{
    for(int i = 0; i < 50; ++i)
    {
        qreal tempX = i/5.0;
        qreal tempY = sin(tempX);
        m_newValue = {tempX, tempY};
        emit newValueChanged();
    }
}
