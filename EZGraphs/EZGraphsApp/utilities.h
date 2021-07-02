#ifndef UTILITIES_H
#define UTILITIES_H

#include <QDebug>
#include <QLoggingCategory>
#include <QObject>
#include <QString>

struct FunctionData {
    QString alias;
    QList<QPointF> values;
    QString latexExpression;
    QString lineColor;
    QByteArray graph;
    bool isInjective;
    bool isSurjective;
};

struct ConfigData {
    bool isAutoSaveON;
    int autoSaveInterval;
};

struct FunctionModelItem {
    QString alias;
    QString expression;
    double step;
};

#endif // UTILITIES_H
