#include "userwindow.h"
#include "ui_userwindow.h"

UserWindow::UserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    //setWindowTitle(tr("Welcome to LoadWindown"));
    //账号密码数目最大不超过16
    ui->lineEdit->setMaxLength(16);
    ui->lineEdit_2->setMaxLength(16);
    //
    //ui->setupUi(this);

    setWindowTitle("客户端");

    tcpSocket = new QTcpSocket(this);

    tcpSocket->connectToHost(QHostAddress(tr("127.0.0.1")),6666);

    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
    {
        char state;
        tcpSocket->read((char*)&state,sizeof(char));
        if(state=='a')
        {
            QMessageBox::information(NULL,"提示","用户名不存在");
        }
        else if(state=='b')
        {
            QMessageBox::information(NULL,"提示","密码错误");
        }
        else if(state=='c')
        {
            QMessageBox::information(NULL,"提示","登录成功");
            this->hide();
        }
        else if(state=='h')
        {
            QMessageBox::information(NULL,"提示","用户名已存在");
        }
        else if(state=='i')
        {
            QMessageBox::information(NULL,"提示","注册成功");

        }
        else if(state=='o')
        {
            QMessageBox::information(NULL,"提示","用户名不存在");

        }
        else if(state=='p')
        {
            QMessageBox::information(NULL,"提示","密码未改变");

        }
        else if(state=='q')
        {
            QMessageBox::information(NULL,"提示","修改成功");

        }
        else
        {
            QMessageBox::information(NULL,"提示","出错");
        }
    }
    );

}

UserWindow::~UserWindow()
{
    delete ui;
}
//登录功能
void UserWindow::on_pushButton_clicked()//登陆
{
    CUser user;
    user.setUserName(ui->lineEdit->text().toUtf8().data());
    user.setPassWord(ui->lineEdit_2->text().toUtf8().data());
    user.setProp('l');
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

void UserWindow::on_pushButton_2_clicked()//注册
{
    clientregt *w1 = new clientregt();
    w1->setTcpSocket(tcpSocket);
    w1->show();
    this->hide();
}

