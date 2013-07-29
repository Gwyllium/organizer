#include "testdiarryrecord.h"

TestDiarryRecord::TestDiarryRecord(QObject *parent) :
    QObject(parent)
{
}

void TestDiarryRecord::getName()
{
    QFETCH(QString, expected);
    QFETCH(QString, actual);
    QCOMPARE(expected, actual);
}

void TestDiarryRecord::getName_data()
{
    QTest::addColumn<QString>("expected");
        QTest::addColumn<QString>("actual");

        DiarryRecord rec=DiarryRecord("first record");
        QTest::newRow("first name") << "first record" << rec.getName();

        rec.setName("Hello");
        QTest::newRow("second name")     << "Hello" << rec.getName();

        QString third_name="third";
        rec.setName(third_name);
        QTest::newRow("third name")     << "third" << rec.getName();

}



void TestDiarryRecord::getText()
{
    QFETCH(QString, expected);
    QFETCH(QString, actual);
    QCOMPARE(expected, actual);
}

void TestDiarryRecord::getText_data()
{
    QTest::addColumn<QString>("expected");
    QTest::addColumn<QString>("actual");

    DiarryRecord rec=DiarryRecord("first record");

    rec.setText("First text record");
    QTest::newRow("First record") << "First text record" << rec.getText();

    rec.setText("Second fucking text record");
    QTest::newRow("Second record")     << "Second fucking text record" << rec.getText();

    QString third_name="This is text";
    rec.setText(third_name);
    QTest::newRow("third record")     << "This is text" << rec.getText();

}



void TestDiarryRecord::getDate()
{
    QFETCH(QDate, expected);
    QFETCH(QDate, actual);
    QCOMPARE(expected, actual);
}

void TestDiarryRecord::getDate_data()
{
    QTest::addColumn<QDate>("expected");
    QTest::addColumn<QDate>("actual");

    DiarryRecord rec=DiarryRecord("first record");

    rec.setDate(QDate(2009, 10, 12));
    QTest::newRow("First record") << QDate(2009, 10, 12) << rec.getDate();

    rec.setDate(QDate(2007, 11, 9));
    QTest::newRow("Second record")     << QDate(2007, 11, 9)<< rec.getDate();

    QDate date=QDate(2013, 7, 22);
    rec.setDate(date);
    QTest::newRow("third record")     << QDate(2013, 7, 22) << rec.getDate();
}

void TestDiarryRecord::getTags()
{
//    QStringList actual;
//    actual<<"private"<<"my diarry"<<"me";
//    DiarryRecord rec = DiarryRecord("Test text record");
//    rec.setText("Hello! I'm not John. This is not my test");
//    QString expected=rec.getText();

//    QCOMPARE(actual,  expected);

}

