#ifndef TESTTASK_H
#define TESTTASK_H

#include <QObject>
#include <QTest>
#include <QDebug>
#include <QException>
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
};

#endif // TESTTASK_H


