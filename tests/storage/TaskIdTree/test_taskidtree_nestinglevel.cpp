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

void Test_TaskIdTree_nestingLevel::treeContainsOneItem()
{
    int expected = 0;

    TaskIdTree tree;
    tree.add("A");
    int actual = tree.nestingLevel("A");

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_nestingLevel::treeContainsOneItemButGivenIdIsNotFound()
{
    int expected = -1;

    TaskIdTree tree;
    tree.add("taskA");
    int actual = tree.nestingLevel("taskB");

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_nestingLevel::oneLevel()
{
    int expected = 0;

    TaskIdTree tree;
    tree.add("taskA");
    tree.add("taskB");
    tree.add("taskC");
    int actual = tree.nestingLevel("taskC");

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_nestingLevel::oneLevelButGivenIdIsNotFound()
{
    int expected = -1;

    TaskIdTree tree;
    tree.add("taskA");
    tree.add("taskB");
    tree.add("taskC");
    int actual = tree.nestingLevel("first task");

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_nestingLevel::twoLevels()
{
    int expected = 1;

    TaskIdTree tree;
    tree.add("A");
    tree.add("B");
    tree.add("C");
    tree.after(0)->add("D");
    tree.after(1)->add("E");
    int actual = tree.nestingLevel("E");

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_nestingLevel::twoLevelsButGivenIdIsNotFound()
{
    int expected = -1;

    TaskIdTree tree;
    tree.add("A");
    tree.add("B");
    tree.after(0)->add("C");
    tree.after(0)->add("D");
    int actual = tree.nestingLevel("N");

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_nestingLevel::threeLevels()
{
    int expected = 2;

    TaskIdTree tree;
    tree.add("A");
    tree.add("B");
    tree.add("C");
    tree.after(1)->add("D");
    tree.after(1)->add("E");
    tree.after(1)->after(0)->add("F");
    tree.after(1)->after(0)->add("G");
    tree.after(2)->add("H");
    int actual = tree.nestingLevel("G");

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_nestingLevel::threeLevelsButGivenIdIsNotFound()
{
    int expected = -1;

    TaskIdTree tree;
    tree.add("A");
    tree.add("B");
    tree.add("C");
    tree.after(0)->add("D");
    tree.after(0)->after(0)->add("E");
    int actual = tree.nestingLevel("H");

    QCOMPARE(actual, expected);
}
