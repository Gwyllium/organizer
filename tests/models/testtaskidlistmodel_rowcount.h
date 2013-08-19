#ifndef TESKTASKIDLISTMODEL_ROWCOUNT_H
#define TESKTASKIDLISTMODEL_ROWCOUNT_H

#include <QObject>
#include <QTest>
#include "taskidlistmodel.h"

class TestTaskIdListModel_rowCount : public QObject
{
    Q_OBJECT
public:
    explicit TestTaskIdListModel_rowCount(QObject *parent = 0);
    
signals:
    
public slots:
private slots:
    void modelIsEmpty();
    void oneId();
    void twoIds();
};

#endif // TESKTASKIDLISTMODEL_ROWCOUNT_H
