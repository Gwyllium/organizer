#include "diarryrecord.h"


DiarryRecord::DiarryRecord(QString name)
{
    this->name=name;
}

QString DiarryRecord::getName()
{
    return name;
}

void DiarryRecord::setName(QString name)
{
    this->name=name;
}

QString DiarryRecord::getText()
{
    return text;
}

void DiarryRecord::setText(QString text)
{
    this->text=text;
}

void DiarryRecord::setDate(QDate date)
{
    this->date=date;
}

QDate DiarryRecord::getDate()
{
    return date;
}
