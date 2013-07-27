#ifndef TESTTASKTREE_TOPLAINLIST_H
#define TESTTASKTREE_TOPLAINLIST_H

#include <QObject>
#include <QTest>
#include "tasktree.h"

class TestTaskTree_toPlainList : public QObject
{
    Q_OBJECT
public:
    explicit TestTaskTree_toPlainList(QObject *parent = 0);
    
signals:
    
public slots:
private slots:
    void treeIsEmpty();
    void treeContainsOneLevel();
    void treeContainsTwoLevels();
    void treeContainsThreeLevels();
};

#endif // TESTTASKTREE_TOPLAINLIST_H
