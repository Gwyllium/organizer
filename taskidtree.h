#ifndef TASKIDTREE_H
#define TASKIDTREE_H

#include <QObject>

class TaskIdTree : public QObject
{
    Q_OBJECT
public:
    explicit TaskIdTree(QObject *parent = 0);
    QString plainText();
    QList<QString> plainList();
    void add(const QString& taskId);
    TaskIdTree* after(int index);
    Q_INVOKABLE int nestingLevel(const QString& taskId);
signals:
    
public slots:
private:
    QString m_value;
    QList<TaskIdTree*> m_children;

    QString plainText(int nestingLevel);
    void plainList(QList<QString> &allIds);
    int nestingLevel(TaskIdTree* subtree, int subtreeLevel, const QString &taskId);

};

#endif // TASKIDTREE_H
