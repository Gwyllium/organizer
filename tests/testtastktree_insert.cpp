#include "testtastktree_insert.h"

TestTastkTree_insert::TestTastkTree_insert(QObject *parent) :
    QObject(parent)
{
}

void TestTastkTree_insert::treeIsEmpty()
{
    QList<QString> expected;

    QStandardItemModel tree;

    QString where = "0";
    QString what = "1";

    TaskTree taskTree(&tree);
    taskTree.insert(what, where);
    QList<QString> actual = taskTree.toPlainList();

    QCOMPARE(actual, expected);
}

void TestTastkTree_insert::insertIntoSecondLevel()
{
    QList<QString> expected;
    expected << "0";
    expected << "1";
    expected << "222";
    expected << "2";

    QStandardItemModel tree;
    QList<QStandardItem*> firstLevel;
    firstLevel << new QStandardItem("0");
    firstLevel << new QStandardItem("1");
    firstLevel << new QStandardItem("2");
    tree.appendColumn(firstLevel);

    QString what = "222";
    QString where = "1";
    TaskTree taskTree(&tree);
    taskTree.insert(what, where);
    QList<QString> actual = taskTree.toPlainList();
    QCOMPARE(actual, expected);
}
