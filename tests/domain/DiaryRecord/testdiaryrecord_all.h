#ifndef TESTDIARYRECORD_ALL_H
#define TESTDIARYRECORD_ALL_H

#include <QObject>
#include <QTest>

#include "diarryrecord.h"

class TestDiaryRecord_all : public QObject
{
    Q_OBJECT
public:
    explicit TestDiaryRecord_all(QObject *parent = 0);

signals:

public slots:
private slots:

    void getName();
    void getName_data();



    void getText();
    void getText_data();

    void getDate();
    void getDate_data();

    void getTags();


};

#endif // TESTDIARYRECORD_ALL_H
