#include "testtree.h"

TestTree::TestTree(QObject *parent) :
    QObject(parent)
{
}

void TestTree::oneItemTree()
{
    qDebug() << "oneItemTree test stub";
}
