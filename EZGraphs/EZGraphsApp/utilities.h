#ifndef UTILITIES_H
#define UTILITIES_H

#include <QDebug>
#include <QLoggingCategory>
#include <QObject>
#include <QString>

struct FunctionData {
    QString alias;
    QVector<double> values;
    QByteArray graph;
    bool isInjective;
    bool isSurjective;
    bool isBijective;
    QString latexExpression;
};

struct ConfigData {
    qreal stepSize;
    bool isAutoSaveON;
    int autoSaveInterval;
};

static ConfigData configurationData { 1, true, 10};

#endif // UTILITIES_H
