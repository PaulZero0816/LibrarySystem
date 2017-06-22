#ifndef BOOKINOUT_H
#define BOOKINOUT_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class Bookinout;
}

class Bookinout : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bookinout(QWidget *parent = 0);
    ~Bookinout();

private slots:
    void on_pushButton_clicked();
    void updatetime();
    void on_pushButton_2_clicked();

signals:
    void sendclosesignal();

private:
    Ui::Bookinout *ui;
};

#endif // BOOKINOUT_H
