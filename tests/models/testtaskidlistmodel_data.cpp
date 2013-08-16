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
