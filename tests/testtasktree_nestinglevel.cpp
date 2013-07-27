#include "testtasktree_nestinglevel.h"
#include "tasktree.h"

TestTaskTree_nestingLevel::TestTaskTree_nestingLevel(QObject *parent) :
    QObject(parent)
{
}

void TestTaskTree_nestingLevel::treeIsEmpty()
{
    int expected = -1;

    QStandardItemModel tree;

    QString taskId = "0";
    int actual = TaskTree(&tree).nestingLevel(taskId);
    QCOMPARE(actual, expected);
}

void TestTaskTree_nestingLevel::targetItemIsAtTheFirstLevel()
{
    int expected = 0;

    QStandardItemModel tree;
    QList<QStandardItem*> firstLevel;
    firstLevel << new QStandardItem("0");
    firstLevel << new QStandardItem("1");
    firstLevel << new QStandardItem("2");
    tree.appendColumn(firstLevel);

    QString taskId = "1";
    int actual = TaskTree(&tree).nestingLevel(taskId);
    QCOMPARE(actual, expected);
}

void TestTaskTree_nestingLevel::targetItemIsAtTheSecondLevel()
{
    int expected = 1;

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

    QString taskId = "3";
    int actual = TaskTree(&tree).nestingLevel(taskId);
    QCOMPARE(actual, expected);
}

void TestTaskTree_nestingLevel::targetItemIsAtTheThirdLevel()
{
    int expected = 2;

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

    QString taskId = "10";
    int actual = TaskTree(&tree).nestingLevel(taskId);
    QCOMPARE(actual, expected);
}
