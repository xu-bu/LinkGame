//#ifndef DOWNLOADWINDOW_H
//#define DOWNLOADWINDOW_H
#pragma once
#include "newloadwindow.h"
#include "cuser.h"
#include "userwindow.h"
#include"ftpdownload.h"

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class DownLoadWindow; }
QT_END_NAMESPACE

class DownLoadWindow : public QMainWindow
{
    Q_OBJECT

public:
    DownLoadWindow(QWidget *parent = nullptr);
    ~DownLoadWindow();
    NewLoadWindow *new_win;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::DownLoadWindow *ui;
    QSqlTableModel *model;
    void InitUI();
    void InitOther();
    QTcpSocket *tcpSocket;
    UserWindow *userWindow;
    QString ip,user,pwd,path;
    int port;
};
//#endif // DOWNLOADWINDOW_H
