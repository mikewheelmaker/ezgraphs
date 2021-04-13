#include <QDebug>

#include "buttonfunctionsupplier.h"

ButtonFunctionSupplier::ButtonFunctionSupplier(QObject *parent) : QObject(parent)
{

}

ButtonFunctionSupplier::~ButtonFunctionSupplier()
{

}

void ButtonFunctionSupplier::onClickedSelectFunction(ButtonFunctions choice)
{
    switch(choice)
    {
    case NewFunction:
        //call method to create new function
        break;
    case SaveFunction:
        //call method to save current function
        break;
    case LoadFunction:
        //call method to load current function
        break;
    case ClearFunction:
        //call method to clear current function(s)
        break;
    case DrawFunction:
        //call method to draw current function
        break;
    }
}
