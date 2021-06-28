#ifndef FUNCTIONMANAGER_H
#define FUNCTIONMANAGER_H

#include <QtCharts>

#include "utilities.h"

Q_DECLARE_LOGGING_CATEGORY(functionManager)

class FunctionManager : public QObject
{
    Q_OBJECT
public:
    explicit FunctionManager(QObject *parent = nullptr);

    QPointF getNewValue() const { return m_newValue; };
    void calculateFunction();

signals:
    void newValueChanged();

private:
    QList<QList<QPointF>> m_listOfFunctions;
    QPointF m_newValue;
};

#endif // FUNCTIONMANAGER_H
