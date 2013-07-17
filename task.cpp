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

void Task::setStartDate(const QDate start)
{
    this->startDate = start;
}

QDate Task::getStartDate()
{
    return startDate;
}