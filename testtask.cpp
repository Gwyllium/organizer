#include "testtask.h"

TestTask::TestTask(QObject *parent) :
    QObject(parent)
{
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
      qDebug() << "Empty name";
      //QCOMPARE(ex.what(), "Name should not be empty.");
  }
  catch (...) {
      QFAIL("Unexpected exception is thrown.");
  }
}

void TestTask::getName()
{
    QFETCH(QString, expected);
    QFETCH(QString, actual);
    QCOMPARE(expected, actual);
}

void TestTask::getName_data()
{
        QTest::addColumn<QString>("expected");
        QTest::addColumn<QString>("actual");

        Task task=Task("first task");
        QTest::newRow("first name") << "first task" << task.getName();

        task.setName("SeConD nAmE task");
        QTest::newRow("second name")     << "SeConD nAmE task" << task.getName();

        QString third_name="third";
        task.setName(third_name);
        QTest::newRow("third name")     << "third" << task.getName();


}



void TestTask::getStartDate() {
    QFETCH(QDate, expected);
    QFETCH(QDate, actual);
    QCOMPARE(expected, actual);
}

void TestTask::getStartDate_data()
{
    QTest::addColumn<QDate>("expected");
    QTest::addColumn<QDate>("actual");

    Task task=Task("first task");
    task.setStartDate(QDate(2010, 06, 20));
    QTest::newRow("first date") << QDate(2010, 06, 20) << task.getStartDate();

    task.setStartDate(QDate(2011, 8, 17));
    QTest::newRow("second date")     << QDate(2011, 8, 17) << task.getStartDate();

    QDate third_date=QDate(2012, 12, 24);
    task.setStartDate(third_date);
    QTest::newRow("third date")     << third_date << task.getStartDate();

}



void TestTask::getEndDate()
{
    QFETCH(QDate, input);
    QFETCH(QDate, expected);
    Task task = Task("Task");
    task.setEndDate(input);
    QDate actual = task.getEndDate();
    qDebug() << "input " << input << " expected " << expected << " actual " << actual;
    QCOMPARE(actual, expected);
}

void TestTask::getEndDate_data()
{
    QTest::addColumn<QDate>("input");
    QTest::addColumn<QDate>("expected");
    QTest::newRow("first date") << QDate(2010, 9, 25) << QDate(2010, 9, 25);
    QTest::newRow("second date") << QDate(2011, 8, 17) << QDate(2011, 8, 17);
    QTest::newRow("third date")     << QDate(2013, 11, 25) << QDate(2013, 11, 25);
}



