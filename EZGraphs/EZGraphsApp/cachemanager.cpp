#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

#include "cachemanager.h"

Q_LOGGING_CATEGORY(cacheManager, "cacheManager.log");

CacheManager::CacheManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if(!m_db.open())
    {
        qCDebug(cacheManager) << "\t[CacheManager] Constructor called --- connection with database failed\n";
    }
    qCDebug(cacheManager) << "\t[CacheManager] Constructor called --- connection with database established successfully\n";
}

CacheManager::~CacheManager()
{
    qCDebug(cacheManager) << "\t[CacheManager] Destructor called\n";
    if(m_db.isOpen())
    {
        m_db.close();
    }
}

bool CacheManager::createTable()
{
    QSqlQuery query;
    QString sql(CREATE_TABLE.arg("functions", "ids INTEGER PRIMARY KEY, alias TEXT, values BLOB, graph TEXT,"
                                              "isInjective INTEGER, isSurjective INTEGER, isBijective INTEGER, latexExpression TEXT"));

    if(!query.exec(sql))
    {
        qCDebug(cacheManager) << "\tr[CacheManager] createTable: Error on creating table.\nLast error: " << query.lastError();
        return false;
    }
    qCDebug(cacheManager) << "\t<cacheManager] createTable: Table created successfully.\n";
    return true;
}

bool CacheManager::insertFunction(const FunctionData &f)
{
    return false;
}

bool CacheManager::retrieveFunction(const FunctionData &f, CacheManager::SearchCategories category)
{
    return false;
}

bool CacheManager::deleteFunction(const FunctionData &f, CacheManager::SearchCategories category)
{
    return false;
}

bool CacheManager::truncateTable(const QString &tableName)
{
    return false;
}

bool CacheManager::dropTable(const QString &tableName)
{
    return false;
}
