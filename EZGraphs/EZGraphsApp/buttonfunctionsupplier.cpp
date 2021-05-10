#include <QCoreApplication>
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
    case NewCanvas:
        //call method to create new canvas
        qDebug() << "call new canvas method";
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
    case Help:
        //call method to display help window
        qDebug() << "call help method";
        break;
    case ExitApplication:
        QCoreApplication::exit();
        break;
    }
}
