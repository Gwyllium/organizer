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
    TaskIdTree* after(int index);
signals:
    
public slots:
private:
    QString m_value;
    QList<TaskIdTree*> m_children;
    QString plainText(int nestingLevel);

};

#endif // TASKIDTREE_H
