#include "testtaskidlistmodel_toplainlist.h"

TestTaskIdListModel_toPlainList::TestTaskIdListModel_toPlainList(QObject *parent) :
    QObject(parent)
{
}

void TestTaskIdListModel_toPlainList::modelIsEmpty()
{
    QStringList expected;

    TaskIdListModel emptyModel;
    QStringList actual = emptyModel.toPlainList();

    QCOMPARE(actual, expected);
}

void TestTaskIdListModel_toPlainList::oneId()
{
    QStringList expected;
    expected << "task one";

    TaskIdListModel model;
    model.add("task one");
    QStringList actual = model.toPlainList();

    QCOMPARE(actual, expected);
}

void TestTaskIdListModel_toPlainList::twoIds()
{
    QStringList expected;
    expected << "first task";
    expected << "second task";

    TaskIdListModel model;
    model.add("first task");
    model.add("second task");
    QStringList actual = model.toPlainList();

    QCOMPARE(actual, expected);
}
