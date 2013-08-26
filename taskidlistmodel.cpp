#include "taskidlistmodel.h"

TaskIdListModel::TaskIdListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

void TaskIdListModel::add(const QString &taskId)
{
    m_taskIdsList.append(taskId);
}

void TaskIdListModel::insert(int where, const QString &taskId)
{
    beginInsertRows(QModelIndex(), where, where);
    m_taskIdsList.insert(where, taskId);
    endInsertRows();
}

QStringList TaskIdListModel::toPlainList()
{
    QStringList plainList(m_taskIdsList);
    return plainList;
}

int TaskIdListModel::rowCount(const QModelIndex &parent) const
{
    return m_taskIdsList.count();
}

QVariant TaskIdListModel::data(const QModelIndex &index, int role) const
{
    int plainIndex = index.row();
    if (plainIndex <0 || plainIndex > m_taskIdsList.count()) {
        return QVariant();
    }
    return m_taskIdsList[index.row()];
}
