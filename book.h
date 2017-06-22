#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QFile>
#include <global.h>
class Book
{
public:
    Book();

    QString Name;
    int ID;
    bool exist;  //书是否丢失或删除,true存在，false不存在
    bool state;  //书是否借出，true未借出，false借出
    QString checkday;
    QString outday;
    QString backday;
    int rentday;
    int number;
    int studentID;
    void addbook(QString a,int b,bool c1,bool c2,QString d1,QString d,QString e,int f,int g,int h);
    void deletebook();
    void store(bool changed);


};

#endif // BOOK_H
