#ifndef TASKIDTREE_H
#define TASKIDTREE_H

#include <QObject>

class TaskIdTree : public QObject
{
    Q_OBJECT
public:
    explicit TaskIdTree(QObject *parent = 0);
    QString plainText();
    void add(const QString& taskId);
signals:
    
public slots:
private:
    QList<QString> m_items;

};

#endif // TASKIDTREE_H
