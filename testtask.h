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

    void nameIsEmpty();

    void getName();
    void getName_data();


    void getStartDate();
    void getStartDate_data();

    void getEndDate();
    void getEndDate_data();

};

#endif // TESTTASK_H


