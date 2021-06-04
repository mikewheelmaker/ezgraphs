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
    int numberOfSamples;
    bool isAutoSaveON;
    int autoSaveInterval;
};

#endif // UTILITIES_H
