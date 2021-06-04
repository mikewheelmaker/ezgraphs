#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H

#include <QSqlDatabase>

#include "utilities.h"

Q_DECLARE_LOGGING_CATEGORY(cacheManager)

const QString CREATE_TABLE("CREATE TABLE IF NOT EXISTS %1 (%2)");

class CacheManager
{
public:
    enum SearchCategories {
        Alias = 0,
        IsInjective,
        IsSurjective,
        IsBijective
    };
public:
    CacheManager(const QString &path);
    ~CacheManager();

    bool createTable();
    bool insertFunction(const FunctionData &f);
    bool retrieveFunction(const FunctionData &f, SearchCategories category);
    bool deleteFunction(const FunctionData &f, SearchCategories category);
    bool truncateTable(const QString &tableName);
    bool dropTable(const QString &tableName);

private:
    QSqlDatabase m_db;
};

#endif // CACHEMANAGER_H
