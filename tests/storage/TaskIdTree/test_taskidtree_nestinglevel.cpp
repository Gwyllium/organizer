#include "test_taskidtree_nestinglevel.h"

Test_TaskIdTree_nestingLevel::Test_TaskIdTree_nestingLevel(QObject *parent) :
    QObject(parent)
{
}

void Test_TaskIdTree_nestingLevel::treeIsEmpty()
{
    int expected = -1;

    TaskIdTree emptyTree;
    QString taskId = "taskOne";
    int actual = emptyTree.nestingLevel(taskId);

    QCOMPARE(actual, expected);
}
