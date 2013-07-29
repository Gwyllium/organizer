#ifndef TESTTASTKTREE_PLAININDEX_H
#define TESTTASTKTREE_PLAININDEX_H

#include <QObject>
#include <QTest>
#include "tasktree.h"

class TestTastkTree_insert : public QObject
{
    Q_OBJECT
public:
    explicit TestTastkTree_insert(QObject *parent = 0);

signals:
    
public slots:
private slots:
    void treeIsEmpty();
    void insertIntoSecondLevel();
    
};

#endif // TESTTASTKTREE_PLAININDEX_H
