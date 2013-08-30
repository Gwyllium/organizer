#ifndef TEST_AFTER_H
#define TEST_AFTER_H

#include <QObject>
#include <QTest>
#include "taskidtree.h"

class Test_after : public QObject
{
    Q_OBJECT
public:
    explicit Test_after(QObject *parent = 0);
signals:
    
public slots:
private slots:
    void treeIsEmpty();
    
};

#endif // TEST_AFTER_H
