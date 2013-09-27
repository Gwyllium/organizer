#ifndef TESTTASK_ALL_H
#define TESTTASK_ALL_H

#include <QObject>
#include <QTest>

class TestTask_all : public QObject
{
    Q_OBJECT
public:
    explicit TestTask_all(QObject *parent = 0);

signals:

public slots:
private slots:
    void sampleTest();

};

#endif // TESTTASK_ALL_H
