#ifndef TESTTASK_H
#define TESTTASK_H

#include <QObject>
#include "test.h"
#include "task.h"

class TestTask : public QObject
{
    Q_OBJECT
public:
    explicit TestTask(QObject *parent = 0);

signals:
    
public slots:
private slots:
    void max();
    void nameIsEmpty();
    void getName();
    void getAnotherName();
    void getStartDate();
    void getAnotherStartDate();

    void getEndDate();
    void getAnotherEndDate();
};

#endif // TESTTASK_H


