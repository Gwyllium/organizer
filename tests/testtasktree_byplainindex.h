#ifndef TESTTASKTREE_BYPLAININDEX_H
#define TESTTASKTREE_BYPLAININDEX_H

#include <QObject>
#include <QTest>
#include "tasktree.h"

class TestTaskTree_byPlainIndex : public QObject
{
    Q_OBJECT
public:
    explicit TestTaskTree_byPlainIndex(QObject *parent = 0);
    
signals:
    
public slots:
private slots:
    void oneLevelTree();
    
};

#endif // TESTTASKTREE_BYPLAININDEX_H
