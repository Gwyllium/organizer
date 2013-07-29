#include "task.h"

Task::Task(const QString name)
{
   if (name=="") {
       throw QException();
   }

   this->name=name;
}

QString Task::getName()
{
    return name;
}

void Task::setName(QString name)
{
    this->name=name;
}

void Task::setStartDate(const QDate start)
{
    this->startDate = start;
}

QDate Task::getStartDate()
{
    return startDate;
}

QDate Task::getEndDate()
{
    return endDate;
}

void Task::setEndDate(const QDate end)
{
    endDate=end;
}
