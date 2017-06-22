#ifndef ADDNEWBOOK_H
#define ADDNEWBOOK_H

#include <QMainWindow>

namespace Ui {
class AddnewBook;
}

class AddnewBook : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddnewBook(QWidget *parent = 0);
    ~AddnewBook();
signals:
    void signalclose();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::AddnewBook *ui;
};

#endif // ADDNEWBOOK_H
