#ifndef TESTDIARRYRECORD_H
#define TESTDIARRYRECORD_H

#include <QObject>
#include "test.h"
#include "diarryrecord.h"

class TestDiarryRecord : public QObject
{
    Q_OBJECT
public:
    explicit TestDiarryRecord(QObject *parent = 0);
    
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

#endif // TESTDIARRYRECORD_H
