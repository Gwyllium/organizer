#ifndef TASKTREE_H
#define TASKTREE_H

#include <QObject>

class TaskTree : public QObject
{
    Q_OBJECT
public:
    explicit TaskTree(QObject *parent = 0);
    Q_INVOKABLE int sampleFunction();
    
signals:

public slots:

};

#endif // TASKTREE_H
