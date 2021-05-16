#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <QObject>

#include "utilities.h"

Q_DECLARE_LOGGING_CATEGORY(ioManager)

class IOManager : public QObject
{
    Q_OBJECT
public:
    explicit IOManager(QObject *parent = nullptr);

signals:

};

#endif // IOMANAGER_H
