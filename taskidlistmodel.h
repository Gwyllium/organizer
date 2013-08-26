#ifndef TASKIDLISTMODEL_H
#define TASKIDLISTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QString>
#include <QStringList>

class TaskIdListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TaskIdListModel(QObject *parent = 0);
    void add(const QString& taskId);
    Q_INVOKABLE void insert(int where, const QString& taskId);
    Q_INVOKABLE QStringList toPlainList();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    
signals:
    
public slots:

private:
    QStringList m_taskIdsList;
};

#endif // TASKIDLISTMODEL_H
