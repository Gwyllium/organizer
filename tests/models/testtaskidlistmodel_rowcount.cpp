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
