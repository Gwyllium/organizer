#ifndef TEST_TASKIDTREE_NESTINGLEVEL_H
#define TEST_TASKIDTREE_NESTINGLEVEL_H

#include <QObject>
#include "tests/test.h"

#include "taskidtree.h"

class Test_TaskIdTree_nestingLevel : public QObject
{
    Q_OBJECT
public:
    explicit Test_TaskIdTree_nestingLevel(QObject *parent = 0);

signals:

public slots:
private slots:
    void treeIsEmpty();
    void treeContainsOneItem();
    void treeContainsOneItemButGivenIdIsNotFound();
    void treeContainsSeveralItemsInOneLevel();
    void treeContainsSeveralItemsInOneLevelButGivenIdIsNotFound();
    void treeContainsSeveralItemsInTwoLevels();
    void treeContainsSeveralItemsInTwoLevelsButGivenIdIsNotFound();
    void threeLevels();
    void threeLevelsButGivenIdIsNotFound();

};

#endif // TEST_TASKIDTREE_NESTINGLEVEL_H