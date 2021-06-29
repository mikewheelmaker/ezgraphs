#include "functionmodel.h"

Q_LOGGING_CATEGORY(functionModel, "functionModel.log");

FunctionModel::FunctionModel(QObject *parent) : QAbstractListModel(parent)
{

}

void FunctionModel::addItem(const FunctionModelItem &itemInfo)
{
    beginResetModel();
    m_functions.append(itemInfo);
    endResetModel();
    qDebug()<<"Added function to list\n";
}

void FunctionModel::removeItem(int index)
{
    beginResetModel();
    m_functions.removeAt(index);
    endResetModel();
    qDebug()<<"Removed function from list.\n";
}

void FunctionModel::clearList()
{
    beginResetModel();
    m_functions.clear();
    endResetModel();
    qDebug()<<"Cleared functions list.\n";
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
            qDebug()<<"Invalid index or no data to get.\n";
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
            qDebug()<<"Invalid case data FunctionModel.\n";
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
    return roles;
}
