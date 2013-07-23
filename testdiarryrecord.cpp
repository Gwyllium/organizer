#include "testdiarryrecord.h"

TestDiarryRecord::TestDiarryRecord(QObject *parent) :
    QObject(parent)
{
}

void TestDiarryRecord::getName()
{
    DiarryRecord rec = DiarryRecord("Simple record");
    QCOMPARE(rec.getName(), QString("Simple record"));
}

void TestDiarryRecord::getAnotherName()
{
    DiarryRecord rec = DiarryRecord("Second record");
    QCOMPARE(rec.getName(), QString("Second record"));
}

void TestDiarryRecord::getText()
{
    QString actual="Hello! I'm John. This is my test";
    DiarryRecord rec = DiarryRecord("Test text record");
    rec.setText("Hello! I'm John. This is my test");
    QString expected=rec.getText();

    QCOMPARE(actual,  expected);
}

void TestDiarryRecord::getAnotherText()
{
    QString actual="Hello! I'm not John. This is not my test";
    DiarryRecord rec = DiarryRecord("Test text record");
    rec.setText("Hello! I'm not John. This is not my test");
    QString expected=rec.getText();

    QCOMPARE(actual,  expected);
}

void TestDiarryRecord::getDate()
{
    QDate actual=QDate(2010, 8,6);
    DiarryRecord rec=DiarryRecord("Date test record");

    rec.setDate(QDate(2010, 8,6));
    QDate expected=rec.getDate();

    QCOMPARE(actual, expected);
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

