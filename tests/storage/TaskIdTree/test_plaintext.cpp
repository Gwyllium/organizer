#include "test_plaintext.h"

Test_plainText::Test_plainText(QObject *parent) :
    QObject(parent)
{
}

void Test_plainText::treeIsEmpty()
{
    QString expected = "";

    TaskIdTree tree;
    QString actual = tree.plainText();

    QCOMPARE(actual, expected);
}

void Test_plainText::oneItemInTree()
{
    QString expected = "[first item-0]";
    TaskIdTree tree;
    tree.add("first item");
    QString actual = tree.plainText();

    QCOMPARE(actual, expected);
}

void Test_plainText::severalItemsButOnlyInFirstLevel()
{
    QString expected = "[first item-0][second item-0][third item-0]";

    TaskIdTree tree;
    tree.add("first item");
    tree.add("second item");
    tree.add("third item");
    QString actual = tree.plainText();

    QCOMPARE(actual, expected);
}
