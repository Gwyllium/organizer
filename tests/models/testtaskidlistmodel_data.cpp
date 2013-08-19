#include "testtaskidlistmodel_data.h"

TestTaskIdListModel_data::TestTaskIdListModel_data(QObject *parent) :
    QObject(parent)
{
}

void TestTaskIdListModel_data::modelIsEmpty()
{
    QString expected = "";

    TaskIdListModel emptyModel;
    QModelIndex firstId = emptyModel.index(0);
    QString actual = emptyModel.data(firstId).toString();

    QCOMPARE(actual, expected);
}

void TestTaskIdListModel_data::oneId()
{
    QString expected = "first task";

    TaskIdListModel model;
    model.add("first task");
    QModelIndex firstIdIndex = model.index(0);
    QString actual = model.data(firstIdIndex).toString();

    QCOMPARE(actual, expected);
}

void TestTaskIdListModel_data::twoIds()
{
    QStringList expected;
    expected << "first task";
    expected << "second task";

    TaskIdListModel model;
    model.add("first task");
    model.add("second task");
    QModelIndex firstIdIndex = model.index(0);
    QModelIndex secondIdIndex = model.index(1);
    QString actualFirstId = model.data(firstIdIndex).toString();
    QString actualSecondId = model.data(secondIdIndex).toString();

    QCOMPARE(actualFirstId, expected[0]);
    QCOMPARE(actualSecondId, expected[1]);
}
