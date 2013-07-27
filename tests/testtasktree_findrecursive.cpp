#include "testtasktree_findrecursive.h"
#include <QStandardItemModel>
#include <tasktree.h>

TestTaskTree_findRecursive::TestTaskTree_findRecursive(QObject *parent) :
    QObject(parent)
{
}

void TestTaskTree_findRecursive::treeIsEmpty()
{
    QStandardItem* expected = NULL;

    QStandardItemModel tree;

    QString taskId = "0";
    QStandardItem* actual = TaskTree().findRecursive(tree, taskId);
}

void TestTaskTree_findRecursive::targetItemIsAtTheFirstLevel()
{
    QStandardItem* expected = new QStandardItem("0");

    QStandardItemModel tree;
    QList<QStandardItem*> firstLevel;
    firstLevel << new QStandardItem("0");
    firstLevel << new QStandardItem("1");
    firstLevel << new QStandardItem("2");
    tree.appendColumn(firstLevel);

    QString taskId = "0";
    QStandardItem* actual = TaskTree().findRecursive(tree, taskId);
    QCOMPARE(actual->text(), expected->text());
}

void TestTaskTree_findRecursive::targetItemIsAtTheSecondLevel()
{
    QStandardItem* expected = new QStandardItem("4");

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

    QString taskId = "4";
    QStandardItem* actual = TaskTree().findRecursive(tree, taskId);
    QCOMPARE(actual->text(), expected->text());
}

void TestTaskTree_findRecursive::targetItemIsAtTheThirdLevel()
{
    QStandardItem* expected = new QStandardItem("9");

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

    QString taskId = "9";
    QStandardItem* actual = TaskTree().findRecursive(tree, taskId);
    QCOMPARE(actual->text(), expected->text());
}


