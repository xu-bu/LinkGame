#include "newloadwindow.h"
#include "ui_newloadwindow.h"
#include "iostream"
#include "QFileDialog"

#include <QDesktopServices>
NewLoadWindow::NewLoadWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewLoadWindow)
{
    ui->setupUi(this);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->progressBar_2->setVisible(false);
    ui->progressBar_3->setVisible(false);
    setWindowTitle(tr("New text Found Window"));
    taskCount=0;

//    downloader_2=new Downloader();
//    connect(downloader_2,SIGNAL(signalDownloadProcess(qint64,qint64)),this,SLOT(onDownloadProcess(qint64,qint64)),Qt::QueuedConnection);
//    downloader_3=new Downloader();
//    connect(downloader_3,SIGNAL(signalDownloadProcess(qint64,qint64)),this,SLOT(onDownloadProcess(qint64,qint64)),Qt::QueuedConnection);
//    connect(downloader_2,SIGNAL(singleDownload(qint64,qint64)),this,SLOT(onDownloadProcess(qint64,qing64)));
//    connect(downloader_3,SIGNAL(singleDownload(qint64,qint64)),this,SLOT(onDownloadProcess(qint64,qing64)));
}

NewLoadWindow::~NewLoadWindow()
{
    delete ui;
}

void NewLoadWindow::on_pushButton_2_clicked()
{
    dialog = new Dialog();

    dialog->show();

    this->hide();
  //  DownLoadWindow(show());

}

void NewLoadWindow::OpenFilePath()
{
    QString directory =
            QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this,tr("Save path"),QDir::currentPath()));

    if(!directory.isEmpty())
    {
        if(ui->comboBox->findText(directory) ==-1)
            ui->comboBox->addItem(directory);
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(directory));
    }
}


void NewLoadWindow::on_pushButton_3_clicked()
{
    OpenFilePath();
}


//普通下载
void NewLoadWindow::on_pushButton_clicked()
{
    taskCount++;
    QString fileName=ui->lineEdit->text();
    QString path=ui->comboBox->currentText();
    QString absPath=path+"/"+fileName;
    absPath=QDir::fromNativeSeparators(absPath);
    qDebug()<<absPath;


    if(taskCount<=3){
        ui->label_4->setVisible(true);
        QString url = ui->lineEdit_2->text();
        qDebug() << url;
        bool i = url.startsWith("http://");
        bool j = url.startsWith("file://");
        bool k = url.startsWith("https://");
        bool z = url.startsWith("ftp://");
        if((i|j|k|z)!=true)
        {
            qDebug()<<"1";
            dialogerror = new DialogError();
            dialogerror->show();
        }
        else
        {
            if(taskCount==1)
            {
                ui->label_4->setVisible(true);
                ui->label_4->setText(fileName);
                ui->progressBar->setVisible(true);
                downloader_1=new Downloader();
//                timer=new QTimer(this);
//                connect(timer,SIGNAL(timeout()),this,SLOT(onDownloadProcess()),Qt::QueuedConnection);
//                connect(downloader_1,SIGNAL(signalDownloadProcess(qint64,qint64)),this,SLOT(onDownloadProcess(qint64,qint64)),Qt::QueuedConnection);
                downloader_1->num=taskCount;
                downloader_1->createThread(url,absPath);
//                downloader_1->singleDownload(url,absPath);
            }
            else if(taskCount==2){
                ui->label_5->setVisible(true);
                ui->label_5->setText(fileName);
                ui->progressBar_2->setVisible(true);
                downloader_2=new Downloader();
//                connect(downloader_2,SIGNAL(signalDownloadProcess(qint64,qint64)),this,SLOT(onDownloadProcess(qint64,qint64)),Qt::QueuedConnection);
                downloader_2->num=taskCount;
                downloader_2->createThread(url,absPath);
            }
            else if (taskCount==3) {
                ui->label_6->setVisible(true);
                ui->label_6->setText(fileName);
                ui->progressBar_3->setVisible(true);
                downloader_3=new Downloader();
//                connect(downloader_3,SIGNAL(signalDownloadProcess(qint64,qint64)),this,SLOT(onDownloadProcess(qint64,qint64)),Qt::QueuedConnection);
                downloader_3->num=taskCount;
                downloader_3->createThread(url,absPath);
            }
        }
    }
    else {
        QMessageBox::critical(0, "任务数量达到上限",
        "任务数量达到上限", QMessageBox::Cancel);
    }
}

//多线程下载
void NewLoadWindow::on_pushButton_4_clicked()
{
    taskCount++;
    QString fileName=ui->lineEdit->text();
    QString path=ui->comboBox->currentText();
    QString absPath=path+"/"+fileName;
    absPath=QDir::fromNativeSeparators(absPath);
    qDebug()<<absPath;


    if(taskCount<=3){
        ui->label_4->setVisible(true);
        QString url = ui->lineEdit_2->text();
        qDebug() << url;
        bool i = url.startsWith("http://");
        bool j = url.startsWith("file://");
        bool k = url.startsWith("https://");
        bool z = url.startsWith("ftp://");
        if((i|j|k|z)!=true)
        {
            qDebug()<<"1";
            dialogerror = new DialogError();
            dialogerror->show();
        }
        else
        {
            if(taskCount==1)
            {
                ui->label_4->setVisible(true);
                ui->label_4->setText(fileName);
                ui->progressBar->setVisible(true);
                downloader_1=new Downloader();
                connect(downloader_1,SIGNAL(signalDownloadProcess(qint64,qint64)),this,SLOT(onDownloadProcess(qint64,qint64)),Qt::QueuedConnection);
                downloader_1->num=taskCount;
                downloader_1->download(url,path,fileName);
            }
            else if(taskCount==2){
                ui->label_5->setVisible(true);
                ui->label_5->setText(fileName);
                ui->progressBar_2->setVisible(true);
                downloader_2=new Downloader();
                connect(downloader_2,SIGNAL(signalDownloadProcess(qint64,qint64)),this,SLOT(onDownloadProcess(qint64,qint64)),Qt::QueuedConnection);
                downloader_2->num=taskCount;
                downloader_2->download(url,path,fileName);
            }
            else if (taskCount==3) {
                ui->label_6->setVisible(true);
                ui->label_6->setText(fileName);
                ui->progressBar_3->setVisible(true);
                downloader_3=new Downloader();
                connect(downloader_3,SIGNAL(signalDownloadProcess(qint64,qint64)),this,SLOT(onDownloadProcess(qint64,qint64)),Qt::QueuedConnection);
                downloader_3->num=taskCount;
                downloader_3->download(url,path,fileName);
            }
        }
    }
}

// 更新下载进度;
void NewLoadWindow::onDownloadProcess()
{
//    qDebug()<<downloader_1->m_bytesReceived;
//    ui->progressBar->setValue(downloader_1->m_bytesReceived);
//    ui->progressBar->setRange(0,downloader_1->m_bytesTotal);
//    ui->progressBar_2->setValue(downloader_2->m_bytesReceived);
//    ui->progressBar_2->setRange(0,downloader_2->m_bytesTotal);
//    ui->progressBar_3->setValue(downloader_3->m_bytesReceived);
//    ui->progressBar_3->setRange(0,downloader_3->m_bytesTotal);
//    qDebug()<<"1";
//    // 输出当前下载进度;
//    // 用到除法需要注意除0错误;
//    qDebug() << QString("%1").arg(bytesReceived * 100 / bytesTotal + 1);
//    Downloader *downloader=dynamic_cast<Downloader *>(sender());
//    qDebug()<<"对象为"<<downloader->num;
//    if(downloader->num==1)
//    {
//        // 更新进度条;
//        ui->progressBar->setMaximum(bytesTotal);
//        ui->progressBar->setValue(bytesReceived);
//    }
//    else if (downloader->num==2) {
//        // 更新进度条;
//        ui->progressBar_2->setMaximum(bytesTotal);
//        ui->progressBar_2->setValue(bytesReceived);
//    }
//    else if (downloader->num==3) {
//        // 更新进度条;
//        ui->progressBar_3->setMaximum(bytesTotal);
//        ui->progressBar_3->setValue(bytesReceived);
//    }


//    // m_intervalDownload 为下次计算速度之前的下载字节数;
//    m_intervalDownload += bytesReceived - m_currentDownload;
//    m_currentDownload = bytesReceived;

//    uint timeNow = m_timeRecord.elapsed();

//    // 超过0.3s更新计算一次速度;
//    if (timeNow - m_timeInterval > TIME_INTERVAL)
//    {
//        qint64 ispeed = m_intervalDownload * 1000 / (timeNow - m_timeInterval);
//        QString strSpeed = transformUnit(ispeed, true);
//        ui.labelSpeed->setText(strSpeed);
//        // 剩余时间;
//        qint64 timeRemain = (bytesTotal - bytesReceived) / ispeed;
//        ui.labelRemainTime->setText(transformTime(timeRemain));

//        ui.labelCurrentDownload->setText(transformUnit(m_currentDownload));
//        ui.labelFileSize->setText(transformUnit(bytesTotal));

//        m_intervalDownload = 0;
//        m_timeInterval = timeNow;
//    }
}

