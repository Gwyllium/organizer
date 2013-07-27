#ifndef TESTTREE_H
#define TESTTREE_H

#include <QObject>
#include <QDebug>
#include <QStandardItemModel>

class TestTree : public QObject
{
    Q_OBJECT
public:
    explicit TestTree(QObject *parent = 0);
    
signals:
    
public slots:
private slots:
    void oneItemTree();
    
};

#endif // TESTTREE_H
