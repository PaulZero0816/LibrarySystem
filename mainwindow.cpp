#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDir>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // QString path = QDir::currentPath();//当前路径
   // qDebug() << path;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Bookinout* booksystem=new Bookinout();
    connect(booksystem,SIGNAL(sendclosesignal()),this,SLOT(reshow()));
    booksystem->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
     Search* searchsystem=new Search();
     connect(searchsystem,SIGNAL(sendclosesignal()),this,SLOT(reshow()));
     searchsystem->show();
     this->hide();
}

void MainWindow::reshow()
{
     this->show();

}

void MainWindow::on_pushButton_3_clicked()
{
    AddnewBook* addnewbooksystem=new AddnewBook();
    connect(addnewbooksystem,SIGNAL(signalclose()),this,SLOT(reshow()));
    addnewbooksystem->show();
    this->hide();
}
