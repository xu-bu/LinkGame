#ifndef WIDGET_H
#define WIDGET_H
#include "cuser.h"
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QSqlDatabase db;
};

#endif // WIDGET_H
