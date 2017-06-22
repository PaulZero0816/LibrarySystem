#include "bookinout.h"
#include "ui_bookinout.h"
#include<QTimer>
#include<QTime>
#include <QDateTime>
#include<QMessageBox>
#include <QDebug>
#include <QFIle>
#include <QDebug>
#include <global.h>
#include <QDataStream>
#include <book.h>
Bookinout::Bookinout(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bookinout)
{
    ui->setupUi(this);
    QTimer* timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(updatetime()));
    timer->start(1000);
}

Bookinout::~Bookinout()
{
    delete ui;
}

void Bookinout::on_pushButton_clicked()
{
    emit sendclosesignal();
    this->close();
   // sendclosesignal("stop");
}

void Bookinout::updatetime()
{

    QDateTime currenttime=QDateTime::currentDateTime();
    QString str = currenttime.toString("yyyy-MM-dd hh:mm:ss ddd");
    //QString str = currenttime.toString("yyyyMMdd");
    this->ui->time->setText(str);
}



void Bookinout::on_pushButton_2_clicked()
{
    if(this->ui->lineEdit->text()!=NULL&&ui->lineEdit_2->text()!=NULL)
    {
    int bookid,studentid;
    bookid=ui->lineEdit->text().toInt();
    studentid=ui->lineEdit_2->text().toInt();
    QFile bookfile(constants::Bookinformationfile);
    QFile rootfile(constants::rootfile);
    bookfile.open(QIODevice::ReadWrite);
    rootfile.open(QIODevice::ReadOnly);
    QDataStream bookin(&bookfile);
    QDataStream rootin(&rootfile);
    int totalnumber;
    rootin>>totalnumber;
    rootfile.close();
    bool flag1=false;
    QString a;
    int b;
    bool c1, c2;
    QString d1,d, e;
    int f, g,h;
    for(int i=0;i<totalnumber;i++)
    {
        bookin>>a>>b>>c1>>c2>>d1>>d>>e>>f>>g>>h;
        if(b==bookid)
        {
            flag1=true;
            if(c2=false)
            {
               QMessageBox::information(NULL, tr("Warn"), tr("已被借出"));
               break;
            }
            else
            {
                Book* changebook=new Book();
                bookfile.close();
                changebook->addbook(a,b,c1,c2,d1,d,e,f,g,h);
                changebook->state=false;
                changebook->studentID=studentid;
                if(this->ui->lineEdit_3->text()!=NULL)
                {
                    changebook->outday=ui->lineEdit_3->text();
                }
                else
                {
                    QDateTime currenttime=QDateTime::currentDateTime();
                    QString d1=currenttime.toString("yyyyMMdd");
                    changebook->outday=d1;
                }
                changebook->backday="NotReturn";
                changebook->rentday=0;
                changebook->store(true);
                QMessageBox::information(NULL, tr("Succeed"), tr("借出成功！"));
                delete changebook;
                break;
            }
        }
    }
    if(flag1==false)
    {
        QMessageBox::information(NULL, tr("Warn"), tr("没有该书"));
    }
    }
    else
    {
        QMessageBox::information(NULL, tr("Warn"), tr("没有填完"));
    }
}
