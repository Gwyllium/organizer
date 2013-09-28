#ifndef TESTTASK_ALL_H
#define TESTTASK_ALL_H

#include <QObject>
#include <QTest>
#include <QDebug>

#include "task.h"

class TestTask_all : public QObject
{
    Q_OBJECT
public:
    explicit TestTask_all(QObject *parent = 0);

signals:

public slots:

private slots:
    void nameIsEmpty();

    void getName();
    void getName_data();


    void getStartDate();
    void getStartDate_data();

    void getEndDate();
    void getEndDate_data();

};

#endif // TESTTASK_ALL_H


