//#ifndef CLIENTREGT_H
//#define CLIENTREGT_H
#pragma once

#include "userwindow.h"
#include "cuser.h"

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class clientregt;
}

class clientregt : public QWidget
{
    Q_OBJECT

public:
    explicit clientregt(QWidget *parent = 0);
    ~clientregt();
    void setTcpSocket(QTcpSocket *Socket);

private slots:
    void on_pushButton_clicked();

private:
    Ui::clientregt *ui;
    QTcpSocket *tcpSocket;
};

//#endif // CLIENTREGT_H
