#ifndef TEST_TASKIDTREE_PLAINLIST_H
#define TEST_TASKIDTREE_PLAINLIST_H

#include <QObject>
#include <QTest>
#include "taskidtree.h"

class Test_TaskIdTree_plainList : public QObject
{
    Q_OBJECT
public:
    explicit Test_TaskIdTree_plainList(QObject *parent = 0);
    
signals:
    
public slots:
private slots:
    void treeIsEmpty();
    void oneItemInTree();
    void severalItemsOneLevel();
    void severalItemsTwoLevels();
    
};

#endif // TEST_TASKIDTREE_PLAINLIST_H
