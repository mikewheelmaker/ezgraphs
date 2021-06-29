#ifndef FUNCTIONMODEL_H
#define FUNCTIONMODEL_H

#include <QAbstractListModel>

#include "utilities.h"

Q_DECLARE_LOGGING_CATEGORY(functionModel)

class FunctionModel : public QAbstractListModel
{
public:
    explicit FunctionModel(QObject *parent = nullptr);

    enum Roles {
        RoleAlias = Qt::UserRole + 1,
        RoleExpression,
        RoleStep
    };

    void addItem(const FunctionModelItem &itemInfo);
    void removeItem(int index);
    void clearList();

    //QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<FunctionModelItem> m_functions;
};

#endif // FUNCTIONMODEL_H
