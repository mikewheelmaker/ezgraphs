#ifndef UTILITIES_H
#define UTILITIES_H

#include <QDebug>
#include <QLoggingCategory>
#include <QObject>
#include <QString>

struct FunctionData {
    QString alias;
    QList<QPointF> values;
    QString expression;
    QString color;
    double step;
};

struct FunctionModelItem {
    QString alias;
    QString expression;
    double step;
};

#endif // UTILITIES_H
