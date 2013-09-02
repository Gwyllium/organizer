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

void Test_TaskIdTree_plainList::severalItemsThreeLevels()
{
    QStringList expected;
    expected << "A";
    expected << "B";
    expected << "nested A";
    expected << "nested B";
    expected << "nested C";
    expected << "nested D";
    expected << "C";

    TaskIdTree tree;
    tree.add("A");
    tree.add("B");
    tree.add("C");
    tree.after(1)->add("nested A");
    tree.after(1)->add("nested B");
    tree.after(1)->after(1)->add("nested C");
    tree.after(1)->after(1)->add("nested D");
    QStringList actual = tree.plainList();

    QCOMPARE(actual, expected);
}
