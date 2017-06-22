#include "search.h"
#include "ui_search.h"
#include <QString>
#include <QFile>
#include <QDataStream>
#include <global.h>
#include <QDebug>
#include<QMessageBox>
Search::Search(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}

void Search::on_pushButton_clicked()
{
    emit sendclosesignal();
    this->close();
}

void Search::on_pushButton_2_clicked()
{
   QString IDnum=this->ui->lineEdit->text();
   int ID=IDnum.toInt();
   QFile bookinformationfile(constants::Bookinformationfile) ;
   bookinformationfile.open(QIODevice::ReadOnly);
   QDataStream bookinstream(&bookinformationfile);
   QFile rootfile(constants::rootfile);
   rootfile.open(QIODevice::ReadOnly);
   QDataStream rootin(&rootfile);
   int totalnumber;
   rootin>>totalnumber;
   rootfile.close();

   QString a;
   int b;
   bool c1, c2;
   QString d1,d, e;
   int f, g,h;
   bool flag1=false;
   for(int i=0;i<totalnumber;i++)
   {
       bookinstream>>a>>b>>c1>>c2>>d1>>d>>e>>f>>g>>h;
                qDebug()<<a;
               qDebug()<<b;
               qDebug()<<c1;
               qDebug()<<c2;
               qDebug()<<d1;
               qDebug()<<d;
               qDebug()<<e;
               qDebug()<<f;
              // qDebug()<<med1;
               qDebug()<<g;
       if(ID==b)
       {

           flag1=true;
           this->ui->tableWidget->setItem(1,0,new QTableWidgetItem(a));
           QString IDnumb=QString::number(b);
           this->ui->tableWidget->setItem(1,1,new QTableWidgetItem(IDnumb));
           if(c1==true)
           {
               this->ui->tableWidget->setItem(1,2,new QTableWidgetItem("存在"));
           }
           else
           {
               this->ui->tableWidget->setItem(1,2,new QTableWidgetItem("已删除"));
           }

           if(c2==true)
           {
               this->ui->tableWidget->setItem(1,3,new QTableWidgetItem("未借出"));
           }
           else
           {
               this->ui->tableWidget->setItem(1,3,new QTableWidgetItem("借出"));
           }
           this->ui->tableWidget->setItem(1,4,new QTableWidgetItem(d1));
           this->ui->tableWidget->setItem(1,5,new QTableWidgetItem(d));
           this->ui->tableWidget->setItem(1,6,new QTableWidgetItem(e));
           QString Days=QString::number(f);
           this->ui->tableWidget->setItem(1,7,new QTableWidgetItem(Days));
           if(h==0)
           {
               this->ui->tableWidget->setItem(1,8,new QTableWidgetItem("无"));
           }
           else
           {
               QString studentID=QString::number(h);
               this->ui->tableWidget->setItem(1,8,new QTableWidgetItem(studentID));
           }
       }
   }
   if(flag1==false)
   {
       QMessageBox::information(NULL, tr("Warn"), tr("没有该书"));
   }
}
