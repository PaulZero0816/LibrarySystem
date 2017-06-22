#include "addnewbook.h"
#include "ui_addnewbook.h"
#include <QDateTime>
#include<QMessageBox>
#include <QDebug>
#include <QFIle>
#include <QDebug>
#include <global.h>
#include <QDataStream>
#include <book.h>
AddnewBook::AddnewBook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddnewBook)
{
    ui->setupUi(this);

}

AddnewBook::~AddnewBook()
{
    delete ui;
}

void AddnewBook::on_pushButton_clicked()
{
    emit signalclose();
    this->close();
}



void AddnewBook::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text()!=NULL&&ui->lineEdit_2->text()!=NULL)
    {
        QString a=ui->lineEdit->text();
        int b=ui->lineEdit_2->text().toInt();
        bool c1=true, c2=true;
        QDateTime currenttime=QDateTime::currentDateTime();
        QString d1=currenttime.toString("yyyyMMdd");
        QString d=currenttime.toString("yyyyMMdd");
        QString e=currenttime.toString("yyyyMMdd");
        int f=0;
        int h=0;
       // QFile rootfile(":/doc/rootfile.txt");
        QFile rootfile(constants::rootfile);
       // QFile bookfile(constants::Bookinformationfile);
        QFile IDfile(constants::BookIDfile);
        if(!rootfile.open(QIODevice::ReadWrite))
        {
            QMessageBox::information(NULL, "error", "打不开root文件.");

        }
      /*  if(!bookfile.open(QIODevice::ReadWrite|QIODevice::Append))
        {
            QMessageBox::information(NULL, "error", "打不开bookfile文件.");

        }
        */
        if(!IDfile.open(QIODevice::ReadWrite))
        {
            QMessageBox::information(NULL, "error", "打不开root文件.");

        }
        QDataStream instream(&rootfile);
        QDataStream outstream(&rootfile);
       // QDataStream bookinstream(&bookfile);
        QDataStream idinstream(&IDfile);
         int g;
        instream>>g;
        int med;
        bool same=false;
        for(int j=0;j<g;j++)
        {
            idinstream>>med;
            if(med==b)
            {
                same=true;
                break;
            }
        }
        if(!same)
        {
            rootfile.seek(0);
            int k=g+1;
            outstream<<k;
            rootfile.close();
            IDfile.seek(IDfile.size());
            idinstream<<b;
            IDfile.close();
            Book* newbook=new Book();
            newbook->addbook(a,b,c1,c2,d1,d,e,f,g,h);
            newbook->store(false);
        }
        else
        {
            QMessageBox::information(NULL, tr("Warn"), tr("书ID重复."));
        }
        // g=med1.toInt();
    /*    qDebug()<<a;
        qDebug()<<b;
        qDebug()<<c1;
        qDebug()<<c2;
        qDebug()<<d1;
        qDebug()<<d;
        qDebug()<<e;
        qDebug()<<f;
       // qDebug()<<med1;
        qDebug()<<g;
*/

    }
    else
    {
        QMessageBox::information(NULL, tr("Warn"), tr("你没有填完信息."));
    }
}
