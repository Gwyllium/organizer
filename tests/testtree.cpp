#include "testtree.h"
#include <QStandardItemModel>
#include <QStandardItem>

TestTree::TestTree(QObject *parent) :
    QObject(parent)
{
}

void TestTree::oneItemTree()
{
    qDebug() << "oneItemTree test stub";

    QStandardItemModel* tree = new QStandardItemModel;

    QList<QStandardItem*> rootRow;
    rootRow << new QStandardItem("1");
    rootRow << new QStandardItem("4");
    rootRow << new QStandardItem("5");

    QList<QStandardItem*> childRow;
    childRow << new QStandardItem("2") << new QStandardItem("3");

    rootRow.first()->appendRow(childRow);

    tree->appendRow(rootRow);

    qDebug() << "tree: " << "\n" <<
                tree->item(0)->text() << "\n" <<
                "\t" << tree->item(0)->child(0)->text() << "\n" <<
                "\t" << tree->item(0)->child(0,1)->text() << "\n";
    //tree->item(1)->text();



    QStandardItem* item = new QStandardItem();
    item->setData(true);
    QVERIFY(item->data() == true);
}
