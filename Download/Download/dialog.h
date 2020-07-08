//#ifndef DIALOG_H
//#define DIALOG_H
#pragma once
#include <QDialog>

#include "newloadwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    //void showmyWin();

    void on_pushButton_2_clicked();
    //NewLoadWindow * newwin;

private:
    Ui::Dialog *ui;
};

//#endif // DIALOG_H
