#include "test_taskidtree_plaintext.h"

Test_TaskIdTree_plainText::Test_TaskIdTree_plainText(QObject *parent) :
    QObject(parent)
{
}

void Test_TaskIdTree_plainText::treeIsEmpty()
{
    QString expected = "";

    TaskIdTree tree;
    QString actual = tree.plainText();

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_plainText::oneItemInTree()
{
    QString expected = "[first item->0]";
    TaskIdTree tree;
    tree.add("first item");
    QString actual = tree.plainText();

    QCOMPARE(actual, expected);
}

void Test_TaskIdTree_plainText::severalItemsButOnlyInFirstLevel()
{
    QString expected = "[first item->0][second item->0][third item->0]";

    TaskIdTree tree;
    tree.add("first item");
    tree.add("second item");
    tree.add("third item");
    QString actual = tree.plainText();

    QCOMPARE(actual, expected);
}
