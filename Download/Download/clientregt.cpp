#include "clientregt.h"
#include "ui_clientregt.h"

clientregt::clientregt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientregt)
{
    ui->setupUi(this);

    setWindowTitle("注册界面");

}

clientregt::~clientregt()
{
    delete ui;
}

void clientregt::setTcpSocket(QTcpSocket *Socket)
{
    tcpSocket = Socket;
}

void clientregt::on_pushButton_clicked()
{
    CUser user;
    user.setUserName(ui->lineEdit->text().toUtf8().data());
    user.setPassWord(ui->lineEdit_2->text().toUtf8().data());
    user.setProp('r');
    if(strlen(user.getUserName())==0)
    {
        QMessageBox::information(NULL,"提示","请输入用户名");
        return;
    }
    if(strlen(user.getPassWord())==0)
    {
        QMessageBox::information(NULL,"提示","请输入密码");
        return;
    }

    tcpSocket->write((char*)&user,sizeof(CUser));
}
