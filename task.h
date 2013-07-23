#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QException>
#include <QDate>

class Task
{
public:
    Task(const QString name);
    QString getName();
    void setStartDate(const QDate start);
    void setEndDate(const QDate end);

    QDate getStartDate();
    QDate getEndDate();
private:
    QString name;
    QDate startDate;
    QDate endDate;
};

#endif // TASK_H
