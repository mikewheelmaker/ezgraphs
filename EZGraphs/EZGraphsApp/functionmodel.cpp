#include "functionmodel.h"

Q_LOGGING_CATEGORY(functionModel, "[FunctionModel]")

FunctionModel::FunctionModel(QObject *parent) : QAbstractListModel(parent)
{
    qCDebug(functionModel) << "Constructor called.\n";
}

void FunctionModel::addItem(const FunctionModelItem &itemInfo)
{
    beginResetModel();
    m_functions.append(itemInfo);
    endResetModel();
    qCDebug(functionModel) << "addItem: Added function to model list\n";
}

void FunctionModel::removeItem(int index)
{
    beginResetModel();
    m_functions.removeAt(index);
    endResetModel();
    qCDebug(functionModel) << "removeItem: Removed function from model list.\n";
}

void FunctionModel::clearList()
{
    beginResetModel();
    m_functions.clear();
    endResetModel();
    qCDebug(functionModel) << "clearList: Cleared functions from model list.\n";
}

int FunctionModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_functions.size();
}

QVariant FunctionModel::data(const QModelIndex &index, int role) const
{
    if(m_functions.size() < index.row() && index.row() <= 0)
    {
        qCDebug(functionModel) << "data: Invalid index or no data to get.\n";
        return QVariant();
    }

    switch(role)
    {
    case RoleAlias:
        return m_functions[index.row()].alias;
        break;
    case RoleExpression:
        return m_functions[index.row()].expression;
        break;
    case RoleStep:
        return m_functions[index.row()].step;
        break;
    default:
        qCDebug(functionModel) << "data: Invalid case data FunctionModel.\n";
        return QVariant();
        break;
    }
}

QHash<int, QByteArray> FunctionModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(RoleAlias, "functionAlias");
    roles.insert(RoleExpression, "functionExpression");
    roles.insert(RoleStep, "functionStep");
    qCDebug(functionModel) << "roleNames: Exposed roles to QML.\n";
    return roles;
}
