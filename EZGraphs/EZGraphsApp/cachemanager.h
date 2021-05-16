#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H

#include <QObject>

#include "utilities.h"

Q_DECLARE_LOGGING_CATEGORY(cacheManager)

class CacheManager : public QObject
{
    Q_OBJECT
public:
    explicit CacheManager(QObject *parent = nullptr);

signals:

};

#endif // CACHEMANAGER_H
