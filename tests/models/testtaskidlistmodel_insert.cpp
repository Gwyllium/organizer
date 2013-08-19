#include "testtaskidlistmodel_insert.h"

TestTaskIdListModel_insert::TestTaskIdListModel_insert(QObject *parent) :
    QObject(parent)
{
}

void TestTaskIdListModel_insert::insertIntoEmptyModel()
{
    QStringList expected;
    expected << "one";

    TaskIdListModel model;
    model.insert(0, "one");
    QStringList actual = model.toPlainList();

    QCOMPARE(actual, expected);
}

void TestTaskIdListModel_insert::insertIntoTheEndOfTheNonEmptyModel()
{
    QStringList expected;
    expected << "one";
    expected << "two";

    TaskIdListModel model;
    model.add("one");
    model.insert(1, "two");
    QStringList actual = model.toPlainList();

    QCOMPARE(actual, expected);
}
