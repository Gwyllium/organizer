#ifndef DIARRYRECORD_H
#define DIARRYRECORD_H

#include <QObject>
#include <QString>
#include <QDate>
class DiarryRecord
{

private:
    QString name;// name of record
    QString text;//text of record. using html tags for design
    QDate date;
public:

    DiarryRecord(QString name);

    QString getName();

    QString getText();
    void setText(QString text);

    void setDate(QDate date);
    QDate getDate();
    

    
};

#endif // DIARRYRECORD_H
