#ifndef SEARCH_H
#define SEARCH_H

#include <QMainWindow>
#include <QString>
namespace Ui {
class Search;
}

class Search : public QMainWindow
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();
signals:
    void sendclosesignal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
