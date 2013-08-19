#ifndef TESTTASKIDLISTMODEL_TOPLAINLIST_H
#define TESTTASKIDLISTMODEL_TOPLAINLIST_H

#include <QObject>
#include <QTest>
#include "taskidlistmodel.h"

class TestTaskIdListModel_toPlainList : public QObject
{
    Q_OBJECT
public:
    explicit TestTaskIdListModel_toPlainList(QObject *parent = 0);
    
signals:
    
public slots:
private slots:
    void modelIsEmpty();
    void oneId();
    void twoIds();
};

#endif // TESTTASKIDLISTMODEL_TOPLAINLIST_H
