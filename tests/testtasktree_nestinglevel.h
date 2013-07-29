#ifndef TESTTASKTREE_NESTINGLEVEL_H
#define TESTTASKTREE_NESTINGLEVEL_H

#include <QObject>
#include <QTest>

class TestTaskTree_nestingLevel : public QObject
{
    Q_OBJECT
public:
    explicit TestTaskTree_nestingLevel(QObject *parent = 0);
    
signals:
    
public slots:
private slots:
    void treeIsEmpty();
    void targetItemIsAtTheFirstLevel();
    void targetItemIsAtTheSecondLevel();
    void targetItemIsAtTheThirdLevel();
    
};

#endif // TESTTASKTREE_NESTINGLEVEL_H
