#ifndef FUNCTIONMANAGER_H
#define FUNCTIONMANAGER_H

#include <QtCharts>

#include "utilities.h"

Q_DECLARE_LOGGING_CATEGORY(functionManager)

class FunctionCalculator : public QObject
{
    Q_OBJECT
public:
    explicit FunctionCalculator(QObject *parent = nullptr);

    QList<QPointF> getNewFunctionValues() const { return m_listOfFunctions.constLast(); };
    void calculateFunction(int option, double rangeMin, double rangeMax, double step);
    void clearList();
    void removeFunctionFromList(int index);

signals:
    void newFunctionAdded();

private:
    QList<QList<QPointF>> m_listOfFunctions;
};

#endif // FUNCTIONMANAGER_H
