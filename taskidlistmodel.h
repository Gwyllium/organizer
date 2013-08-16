#ifndef TASKIDLISTMODEL_H
#define TASKIDLISTMODEL_H

#include <QAbstractListModel>

class TaskIdListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TaskIdListModel(QObject *parent = 0);
    void add(const QString& taskId);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    
signals:
    
public slots:
    
};

#endif // TASKIDLISTMODEL_H
