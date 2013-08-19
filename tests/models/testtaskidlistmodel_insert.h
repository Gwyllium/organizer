#ifndef TESTTASKIDLISTMODEL_INSERT_H
#define TESTTASKIDLISTMODEL_INSERT_H

#include <QObject>
#include <QTest>
#include "taskidlistmodel.h"

class TestTaskIdListModel_insert : public QObject
{
    Q_OBJECT
public:
    explicit TestTaskIdListModel_insert(QObject *parent = 0);
    
signals:
    
public slots:
private slots:
    void insertIntoEmptyModel();
    void insertIntoTheEndOfTheNonEmptyModel();
    
};

#endif // TESTTASKIDLISTMODEL_INSERT_H
