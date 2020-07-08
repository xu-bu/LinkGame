//#ifndef NEWLOADWINDOW_H
//#define NEWLOADWINDOW_H
#pragma once
#include "dialog.h"
#include "dialogerror.h"
#include "downloader.h"

#include <QMainWindow>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
namespace Ui {
class NewLoadWindow;
}

class NewLoadWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewLoadWindow(QWidget *parent = nullptr);
    ~NewLoadWindow();
   //DownLoadWindow * downWin;

private slots:
    void onDownloadProcess();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

    //void on_pushButton_2_toggled(bool checked);

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::NewLoadWindow *ui;
    int taskCount;
     QDialog * dialog;
     QDialog * dialogerror;
     void  OpenFilePath();
     void ReadLine();
     Downloader *downloader_1;
     Downloader *downloader_2;
     Downloader *downloader_3;
     QTimer *timer;
};

//#endif // NEWLOADWINDOW_H
