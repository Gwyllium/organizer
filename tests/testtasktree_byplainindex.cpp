#include "testtasktree_byplainindex.h"

TestTaskTree_byPlainIndex::TestTaskTree_byPlainIndex(QObject *parent) :
    QObject(parent)
{
}

void TestTaskTree_byPlainIndex::oneLevelTree()
{
    QString expected = "task two";

    QStandardItemModel tree;
    QList<QStandardItem*> firstLevel;
    firstLevel << new QStandardItem("task one");
    firstLevel << new QStandardItem("task two");
    firstLevel << new QStandardItem("task three");
    tree.appendColumn(firstLevel);

    QString actual = TaskTree(&tree).byPlainIndex(1);
    QCOMPARE(actual, expected);
}
