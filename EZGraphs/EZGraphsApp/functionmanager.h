#ifndef FUNCTIONMANAGER_H
#define FUNCTIONMANAGER_H

#include <QObject>

#include "utilities.h"

Q_DECLARE_LOGGING_CATEGORY(functionManager)

class FunctionManager : public QObject
{
    Q_OBJECT
public:
    explicit FunctionManager(QObject *parent = nullptr);

signals:

};

#endif // FUNCTIONMANAGER_H
