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
    QDate getStartDate();
private:
    QString name;
    QDate startDate;
};

#endif // TASK_H
