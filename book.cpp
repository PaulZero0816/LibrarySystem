#include "book.h"
#include <QFile>
#include <QDataStream>
#include<QDebug>
Book::Book()
{

}

void Book::addbook(QString a,int b,bool c1,bool c2,QString d1,QString d,QString e,int f,int g,int h)
{
    this->Name=a;
    this->ID=b;
    this->exist=c1;
    this->state=c2;
    this->checkday=d1;
    this->outday=d;
    this->backday=e;
    this->rentday=f;
    this->number=g;
    this->studentID=h;
}

void Book::deletebook()
{
    this->exist=false;
}

void Book::store(bool changed)
{
    QFile bookfile(constants::Bookinformationfile);
    if(changed)
    {
        QString a;
        int b;
        bool c1, c2;
        QString d1,d, e;
        int f, g,h;
        bookfile.open(QIODevice::ReadWrite);
         QDataStream ism(&bookfile);
        // QDataStream osm(&bookfile);
         for(int i=0;i<this->number;i++)
         {
             ism>>a>>b>>c1>>c2>>d1>>d>>e>>f>>g>>h;

         }

         ism<<this->Name<<this->ID<<this->exist<<this->state<<this->checkday<<this->outday<<this->backday<<this->rentday<<this->number<<this->studentID;

         bookfile.close();

    }
    else
    {
        bookfile.open(QIODevice::WriteOnly|QIODevice::Append);
        QDataStream osm(&bookfile);
        osm<<this->Name<<this->ID<<this->exist<<this->state<<this->checkday<<this->outday<<this->backday<<this->rentday<<this->number<<this->studentID;
     /*   qDebug()<<this->Name;
               qDebug()<<this->ID;
               qDebug()<<this->exist;
               qDebug()<<this->state;
               qDebug()<<this->checkday;
               qDebug()<<this->outday;
               qDebug()<<this->backday;
               qDebug()<<this->rentday;
               qDebug()<<this->number;
               */
        bookfile.close();
    }
}
