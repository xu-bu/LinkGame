#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
/*void Dialog::showmyWin()
{
    dialog = new Dialog(this);

    dialog->show();
}*/

void Dialog::on_pushButton_clicked()
{
    this->close();
    //退出下载

}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
    //继续下载
   NewLoadWindow * newwin;
   newwin = new NewLoadWindow();
   newwin->show();

}
