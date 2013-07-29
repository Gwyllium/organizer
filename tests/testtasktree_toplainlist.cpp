#include "testtasktree_toplainlist.h"

TestTaskTree_toPlainList::TestTaskTree_toPlainList(QObject *parent) :
    QObject(parent)
{
}

void TestTaskTree_toPlainList::treeIsEmpty()
{
    QList<QString> expected;

    QStandardItemModel tree;

    QList<QString> actual = TaskTree(&tree).toPlainList();
    QCOMPARE(actual, expected);
}

void TestTaskTree_toPlainList::treeContainsOneLevel()
{
    QList<QString> expected;
    expected << "1";
    expected << "2";
    expected << "3";

    QStandardItemModel tree;
    QList<QStandardItem*> firstLevel;
    firstLevel << new QStandardItem("1");
    firstLevel << new QStandardItem("2");
    firstLevel << new QStandardItem("3");
    tree.appendColumn(firstLevel);

    QList<QString> actual = TaskTree(&tree).toPlainList();
    QCOMPARE(actual, expected);
}

void TestTaskTree_toPlainList::treeContainsTwoLevels()
{
    QList<QString> expected;
    expected << "0";
    expected << "3";
    expected << "4";
    expected << "1";
    expected << "2";

    QStandardItemModel tree;
    QList<QStandardItem*> firstLevel;
    firstLevel << new QStandardItem("0");
    firstLevel << new QStandardItem("1");
    firstLevel << new QStandardItem("2");
    QList<QStandardItem*> secondLevel;
    secondLevel << new QStandardItem("3");
    secondLevel << new QStandardItem("4");
    firstLevel.first()->appendColumn(secondLevel);
    tree.appendColumn(firstLevel);

    QList<QString> actual = TaskTree(&tree).toPlainList();
    QCOMPARE(actual, expected);
}

void TestTaskTree_toPlainList::treeContainsThreeLevels()
{
    QList<QString> expected;
    expected << "0";
    expected << "3";
    expected << "4";
    expected << "8";
    expected << "9";
    expected << "10";
    expected << "1";
    expected << "2";
    expected << "5";
    expected << "6";
    expected << "7";

    QStandardItemModel tree;
    QList<QStandardItem*> firstLevel;
    firstLevel << new QStandardItem("0");
    firstLevel << new QStandardItem("1");
    firstLevel << new QStandardItem("2");
    QList<QStandardItem*> secondLevelA;
    secondLevelA << new QStandardItem("3");
    secondLevelA << new QStandardItem("4");
    QList<QStandardItem*> secondLevelB;
    secondLevelB << new QStandardItem("5");
    secondLevelB << new QStandardItem("6");
    secondLevelB << new QStandardItem("7");
    QList<QStandardItem*> thirdLevel;
    thirdLevel << new QStandardItem("8");
    thirdLevel << new QStandardItem("9");
    thirdLevel << new QStandardItem("10");
    secondLevelA[1]->appendColumn(thirdLevel);
    firstLevel[0]->appendColumn(secondLevelA);
    firstLevel[2]->appendColumn(secondLevelB);
    tree.appendColumn(firstLevel);

    QList<QString> actual = TaskTree(&tree).toPlainList();
    QCOMPARE(actual, expected);
}
