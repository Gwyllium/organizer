#include "test_taskidtree_after.h"

Test_TaskIdTree_after::Test_TaskIdTree_after(QObject *parent) :
    QObject(parent)
{
}

void Test_TaskIdTree_after::treeIsEmpty()
{
    TaskIdTree *expected = NULL;

    TaskIdTree tree;
    TaskIdTree *actual = tree.after(0);

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_after::plainTextOfEndingItemFromFirstLevel()
{
    QString expected = "";

    TaskIdTree tree;
    tree.add("a");
    QString actual = tree.after(0)->plainText();

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_after::plainTextOfEndingItemFromFirstMultipleItemsLevel()
{
    QString expected = "";

    TaskIdTree tree;
    tree.add("one");
    tree.add("two");
    tree.add("three");
    QString actual = tree.after(1)->plainText();

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_after::constructThreeItemsInTwoLevels()
{
    QString expected = "[a->0][c->1][b->0]";

    TaskIdTree tree;
    tree.add("a");
    tree.add("b");
    tree.after(0)->add("c");
    QString actual = tree.plainText();

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_after::constructSeveralItemsInTwoLevels()
{
    QString expected = "[task one->0][task one A->1][task one B->1][task two->0][task three->0][task three A->1]";

    TaskIdTree tree;
    tree.add("task one");
    tree.add("task two");
    tree.add("task three");
    tree.after(0)->add("task one A");
    tree.after(0)->add("task one B");
    tree.after(2)->add("task three A");
    QString actual = tree.plainText();

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_after::constructSeveralItemsInThreeLevels()
{
    QString expected = "[A->0][A C->1][A C D->2][A E->1][B->0][B G->1][B G H->2][B J->1][B J K->2][F->0]";

    TaskIdTree tree;
    tree.add("A");
    tree.after(0)->add("A C");
    tree.after(0)->after(0)->add("A C D");
    tree.after(0)->add("A E");
    tree.add("B");
    tree.after(1)->add("B G");
    tree.after(1)->after(0)->add("B G H");
    tree.after(1)->add("B J");
    tree.after(1)->after(1)->add("B J K");
    tree.add("F");
    QString actual = tree.plainText();

    QCOMPARE(actual, expected);
}

