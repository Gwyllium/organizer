#ifndef TESTTASKIDLISTMODEL_H
#define TESTTASKIDLISTMODEL_H

#include <QObject>
#include <QTest>
#include "taskidlistmodel.h"

class TestTaskIdListModel_data : public QObject
{
    Q_OBJECT
public:
    explicit TestTaskIdListModel_data(QObject *parent = 0);
    
signals:
    
public slots:
private slots:
    void modelIsEmpty();
    
};

#endif // TESTTASKIDLISTMODEL_H
