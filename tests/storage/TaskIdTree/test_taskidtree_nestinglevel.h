#ifndef TEST_TASKIDTREE_NESTINGLEVEL_H
#define TEST_TASKIDTREE_NESTINGLEVEL_H

#include <QObject>
#include "tests/test.h"

#include "taskidtree.h"

class Test_TaskIdTree_nestingLevel : public QObject
{
    Q_OBJECT
public:
    explicit Test_TaskIdTree_nestingLevel(QObject *parent = 0);

signals:

public slots:
private slots:
    void treeIsEmpty();

};

#endif // TEST_TASKIDTREE_NESTINGLEVEL_H
