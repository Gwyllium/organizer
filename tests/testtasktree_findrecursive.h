#ifndef TESTTASKTREE_FINDRECURSIVE_H
#define TESTTASKTREE_FINDRECURSIVE_H

#include <QObject>
#include <QTest>

class TestTaskTree_findRecursive : public QObject
{
    Q_OBJECT
public:
    explicit TestTaskTree_findRecursive(QObject *parent = 0);
    
signals:
    
public slots:
private slots:
    void treeIsEmpty();
    void targetItemIsAtTheFirstLevel();
    void targetItemIsAtTheSecondLevel();
    void targetItemIsAtTheThirdLevel();
    
};

#endif // TESTTASKTREE_FINDRECURSIVE_H
