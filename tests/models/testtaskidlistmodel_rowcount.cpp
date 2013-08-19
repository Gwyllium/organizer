#include "testtaskidlistmodel_rowcount.h"

TestTaskIdListModel_rowCount::TestTaskIdListModel_rowCount(QObject *parent) :
    QObject(parent)
{
}

void TestTaskIdListModel_rowCount::modelIsEmpty()
{
    int expected = 0;

    TaskIdListModel emptyModel;
    int actual = emptyModel.rowCount();

    QCOMPARE(actual, actual);
}

void TestTaskIdListModel_rowCount::oneId()
{
    int expected = 1;

    TaskIdListModel model;
    model.add("task one");
    int actual = model.rowCount();

    QCOMPARE(actual, expected);
}

void TestTaskIdListModel_rowCount::twoIds()
{
    int expected = 2;

    TaskIdListModel model;
    model.add("task one");
    model.add("task two");
    int actual = model.rowCount();

    QCOMPARE(actual, expected);
}
