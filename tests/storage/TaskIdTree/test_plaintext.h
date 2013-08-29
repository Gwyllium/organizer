#ifndef TEST__PLAINTEXT_H
#define TEST__PLAINTEXT_H

#include <QObject>
#include <QTest>
#include "taskidtree.h"

class Test_plainText : public QObject
{
    Q_OBJECT
public:
    explicit Test_plainText(QObject *parent = 0);

signals:

public slots:
private slots:
    void treeIsEmpty();
    void oneItemInTree();
    void severalItemsButOnlyInFirstLevel();
};

#endif // TEST__PLAINTEXT_H
