#include "downloadwindow.h"
#include "ui_downloadwindow.h"
#include <QMenuBar>

#include<QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QSqlQuery>
#include<QSqlRecord>
#include <QTableView>
#include <QTcpSocket>
#include <QStandardItemModel>
#include "cuser.h"
DownLoadWindow::DownLoadWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DownLoadWindow)
{

    ui->setupUi(this);
    InitUI();
}

DownLoadWindow::~DownLoadWindow()
{
    delete ui;
}



void DownLoadWindow::on_pushButton_clicked()//新建下载任务
{
    new_win = new NewLoadWindow;
    new_win->show();
}

void DownLoadWindow::InitUI()
{  //添加Mysql数据库
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    //连接数据库
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("testa.db");

    //打开数据库
    if(!db.open())
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }



    model = new QSqlTableModel(this, db);

    model->setTable("file_info");  //指定模型要关联的表(employee)
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //条件（等价于SQL语句的where）
    // model->setFilter(QObject::tr("create_time=#%1#").arg(create_time));

    model->select();  //查询表格数据
    model->setHeaderData(0, Qt::Horizontal, tr("ip"));
    model->setHeaderData(1, Qt::Horizontal, tr("port"));
    model->setHeaderData(2, Qt::Horizontal, tr("username"));
    model->setHeaderData(3, Qt::Horizontal, tr("password"));
    model->setHeaderData(4, Qt::Horizontal, tr("abspath"));

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格宽度
    ui->tableView->show();
    db.close();

    // 初始化窗体其他属性
    InitOther();
}

void DownLoadWindow::InitOther()
{
  setWindowTitle(tr("Welcome to DownLoad Window"));
}


void DownLoadWindow::on_pushButton_2_clicked()
{
    this->close();
}


void DownLoadWindow::on_pushButton_6_clicked()
{
    if(strlen(ui->lineEdit->text().toUtf8().data())==0)
    {
        QMessageBox::information(NULL,"提示","请输入用户名");
        return;
    }
    if(strlen(ui->lineEdit_3->text().toUtf8().data())==0)
    {
        QMessageBox::information(NULL,"提示","请输入新密码");
        return;
    }
    if(strlen(ui->lineEdit_4->text().toUtf8().data())==0)
    {
        QMessageBox::information(NULL,"提示","请输入再次确认的新密码");
        return;
    }
    if(strcmp(ui->lineEdit_4->text().toUtf8().data(),ui->lineEdit_3->text().toUtf8().data())!=0)
    {
        QMessageBox::information(NULL,"提示","新密码与再次确认不一致");
        return;
    }
    CUser user;
    user.setUserName(ui->lineEdit->text().toUtf8().data());
    user.setPassWord(ui->lineEdit_3->text().toUtf8().data());
    user.setProp('m');


    tcpSocket->write((char*)&user,sizeof(CUser));
}



void DownLoadWindow::on_pushButton_3_clicked()
{
    ftpDownload *ftpDoanloader=new ftpDownload();
    ftpDoanloader->FtpSetHostPort(ip,port);
    ftpDoanloader->FtpSetUserInfor(user,pwd);
    QString absPath="c:/download/"+path;
    ftpDoanloader->FtpGet(path,absPath);
    QMessageBox::information(this,"下载成功","下载成功");
}

void DownLoadWindow::on_tableView_clicked(const QModelIndex &index)
{

    ip = model->data(model->index(index.row(),0)).toString();
    port=model->data(model->index(index.row(),1)).toInt();
    user=model->data(model->index(index.row(),2)).toString();
    pwd=model->data(model->index(index.row(),3)).toString();
    path=model->data(model->index(index.row(),4)).toString();
}

void DownLoadWindow::on_pushButton_7_clicked()
{
    userWindow=new UserWindow();
    userWindow->show();
}
