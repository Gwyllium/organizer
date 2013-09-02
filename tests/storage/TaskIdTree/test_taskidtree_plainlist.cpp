#include "test_taskidtree_plainlist.h"

Test_TaskIdTree_plainList::Test_TaskIdTree_plainList(QObject *parent) :
    QObject(parent)
{
}

void Test_TaskIdTree_plainList::treeIsEmpty()
{
    QStringList expected;

    TaskIdTree tree;
    QStringList actual = tree.plainList();

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_plainList::oneItemInTree()
{
    QStringList expected;
    expected << "Task one";

    TaskIdTree tree;
    tree.add("Task one");
    QStringList actual = tree.plainList();

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_plainList::severalItemsOneLevel()
{
    QStringList expected;
    expected << "A";
    expected << "B";
    expected << "C";

    TaskIdTree tree;
    tree.add("A");
    tree.add("B");
    tree.add("C");
    QStringList actual = tree.plainList();

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_plainList::severalItemsTwoLevels()
{
    QStringList expected;
    expected << "A";
    expected << "nested one";
    expected << "nested two";
    expected << "B";
    expected << "nested three";

    TaskIdTree tree;
    tree.add("A");
    tree.add("B");
    tree.after(0)->add("nested one");
    tree.after(0)->add("nested two");
    tree.after(1)->add("nested three");
    QStringList actual = tree.plainList();

    QCOMPARE(actual, expected);
}
