#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    db=QSqlDatabase::addDatabase("QSQLITE");//这里隐藏了一个参数，第二个参数是连接名称，不写就代表是默认
    //sqlite需要把db文件放在build的同级目录下
    db.setDatabaseName("testa.db");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("123456");
    bool ok = db.open();
    if(!ok){
        //弹窗，第一个参数是父窗口指针，第二个参数是标题，第三个参数是内容，第四个是按钮选项
        QMessageBox::critical(0, "无法打开数据库",
        "无法创建数据库连接！ ", QMessageBox::Cancel);
    }

    QSqlQuery sqlQuery(db);


    tcpServer = new QTcpServer(this);
    tcpSocket = new QTcpSocket(this);

    setWindowTitle("服务器：6666");

    tcpServer->listen(QHostAddress::Any,6666);


    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
    {
        tcpSocket = tcpServer->nextPendingConnection();
        QString ip = tcpSocket->peerAddress().toString();
        qint16 port = tcpSocket->peerPort();
        QString temp = QString("[%1:%2]:成功连接").arg(ip).arg(port);
        ui->textEdit->append(temp);
        connect(tcpSocket,&QTcpSocket::readyRead,
                [=]()
        {
            CUser user;
            char state = 'a';
            tcpSocket->read((char*)&user,sizeof(CUser));

            if(!db.open())
            {
                qDebug()<<tr("数据库已断开连接，请重新连接数据库");
            }

            QSqlQuery sqlQuery(db);

            if(user.getProp()=='l')
            {
                QString str = tr("select name,password from user where name='%1';").arg(user.getUserName());
                sqlQuery.exec(str);

                QString name_t;
                QString password_t;
                while(sqlQuery.next())
                {
                    name_t = sqlQuery.value(0).toString();
                    password_t = sqlQuery.value(1).toString();
                    ui->textEdit->append(str);
                    ui->textEdit->append(name_t);
                    ui->textEdit->append(password_t);
                }
                if(name_t == NULL)
                {
                    qDebug()<<tr("用户名不存在").toUtf8().data();
                    state = 'a';
                }
                else
                {
                    if(user.getPassWord()!=password_t)
                    {
                        qDebug()<<tr("密码错误").toUtf8().data();
                        state = 'b';
                    }
                    else
                    {
                        qDebug()<<tr("登录成功").toUtf8().data();
                        state = 'c';
                    }
                }

                tcpSocket->write((char*)&state,sizeof(char));
            }
            else if(user.getProp()=='r')
            {
                QString str = tr("insert into user(name,password) values('%1','%2');").arg(user.getUserName()).
                        arg(user.getPassWord());

                qDebug()<<str.toUtf8().data();

                if(!sqlQuery.exec(str))
                {
                    qDebug()<<tr("用户名已存在").toUtf8().data()<<sqlQuery.lastError().text();
                    state = 'h';
                }
                else
                {
                    qDebug()<<tr("注册成功！").toUtf8().data();
                    state = 'i';
                }

                tcpSocket->write((char*)&state,sizeof(char));
            }
            else if(user.getProp()=='m')
            {
                QString str = tr("select * from user where name='%1';").arg(user.getUserName());

                qDebug()<<str.toUtf8().data();

                sqlQuery.exec(str);
                QString name_t;
                QString password_t;
                while(sqlQuery.next())
                {
                    ui->textEdit->append(name_t);
                    name_t = sqlQuery.value(1).toString();
                    password_t = sqlQuery.value(2).toString();
                }
                if(name_t == NULL)
                {
                    qDebug()<<tr("用户名不存在").toUtf8().data();
                    state = 'o';
                }
                else
                {
                    if(user.getPassWord()==password_t)
                    {
                        qDebug()<<tr("密码未改变").toUtf8().data();
                        state = 'p';
                    }
                    else
                    {
                        QString str = tr("update user set password = '%1' where name = '%2';").arg(user.getPassWord()).arg(user.getUserName());
                        sqlQuery.exec(str);
                        qDebug()<<tr("修改成功").toUtf8().data();
                        state = 'q';
                    }
                }

                tcpSocket->write((char*)&state,sizeof(char));
            }
        }
        );
    }
    );
}

Widget::~Widget()
{
    delete ui;
}
