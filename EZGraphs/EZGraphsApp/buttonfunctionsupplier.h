#ifndef BUTTONFUNCTIONSUPPLIER_H
#define BUTTONFUNCTIONSUPPLIER_H

#include <QObject>

#include "utilities.h"

class ButtonFunctionSupplier : public QObject
{
    Q_OBJECT
public:
    explicit ButtonFunctionSupplier(QObject *parent = nullptr);
    ~ButtonFunctionSupplier();

    Q_INVOKABLE void onClickedSelectFunction(ButtonFunctions choice);

signals:

};

#endif // BUTTONFUNCTIONSUPPLIER_H
