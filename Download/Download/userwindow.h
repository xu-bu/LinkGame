//#ifndef USERWINDOW_H
//#define USERWINDOW_H
#pragma once

#include "cuser.h"
#include "clientregt.h"

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);
    ~UserWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

//    void on_pushButton_3_clicked();

private:
    Ui::UserWindow *ui;
    QTcpSocket *tcpSocket;
};

//#endif // USERWINDOW_H
