#include "testtask.h"

TestTask::TestTask(QObject *parent) :
    QObject(parent)
{
}

void TestTask::max()
{
    qDebug() << "This is a test: max";
}

void TestTask::nameIsEmpty()
{
  QString name = "";
  try
  {
    new Task(name);
    QFAIL("Exception should be thrown.");
  }
  catch(QException ex)
  {
      qDebug() << "Пустое имя";
      //QCOMPARE(ex.what(), "Name should not be empty.");
  }
  catch (...) {
      QFAIL("Unexpected exception is thrown.");
  }
}

void TestTask::getName()
{
    Task task = Task("Simple task");
    QCOMPARE(task.getName(), QString("Simple task"));
}

void TestTask::getAnotherName()
{
    Task task = Task("Another task name");
    QCOMPARE(task.getName(), QString("Another task name"));
}


void TestTask::getStartDate() {
    QDate expected = QDate(2008, 6,10);
    Task task = Task("Task 1");
    task.setStartDate(QDate(2008, 6,10));
    QDate actual = task.getStartDate();
    QCOMPARE(actual, expected);
}

void TestTask::getAnotherStartDate()
{
    QDate expected = QDate(2013, 07, 16);
    Task task = Task("Task");
    task.setStartDate(QDate(2013, 07, 16));
    QDate actual = task.getStartDate();
    QCOMPARE(actual, expected);
}



