#include "taskidlistmodel.h"

TaskIdListModel::TaskIdListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

void TaskIdListModel::add(const QString &taskId)
{
}

int TaskIdListModel::rowCount(const QModelIndex &parent) const
{
}

QVariant TaskIdListModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}
