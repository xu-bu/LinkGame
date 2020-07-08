#include "ftpdownload.h"

#include <QDebug.h>

ftpDownload::ftpDownload()
{
    m_pManager=new QNetworkAccessManager();
    //第一个finished是QNetworkAccessManager自带的，get到之后会发出这个信号
    //第二个finished是自己写的，恰好同名而已
    connect(m_pManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply *)));
}

//设置FTP服务器用户名和密码
void ftpDownload::FtpSetUserInfor(QString user, QString pwd)
{
    m_pUrl.setUserName(user);
    m_pUrl.setPassword(pwd);
}
//设置地址和端口
void ftpDownload::FtpSetHostPort(QString str, int port )
{
    m_pUrl.setHost(str);
    m_pUrl.setPort(port);
}
//下载文件
void ftpDownload::FtpGet(QString sor, QString dev)
{
    QFileInfo info;
    info.setFile(dev);
    m_pFile = new QFile(info.filePath());
    m_pFile->open(QIODevice::Append|QIODevice::WriteOnly);
    m_pUrl.setPath(sor);

    QTimer timer;
    timer.setInterval(10000);  // 设置超时时间 10 秒
    timer.setSingleShot(true);  // 单次触发
    m_pReply=m_pManager->get(QNetworkRequest(m_pUrl));

    QEventLoop eventLoop;
    connect(&timer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);
    connect(m_pReply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    timer.start();
    eventLoop.exec();
    if (timer.isActive())
    {
        timer.stop();
        totalLength = m_pReply->rawHeader("Content-Length").toInt();
        if(m_pReply->error()==QNetworkReply::NoError)
        {
            QByteArray byteArray = m_pReply->readAll();
            int reciveLength=0;
            reciveLength += byteArray.count();
            qDebug() << "recieve"<<reciveLength<<"Bytes";
            Sleep(1000);
            while (true)
            {
                if (m_pReply->isFinished())
                {
                    qDebug() <<"download complete";
                }
                if (totalLength == reciveLength)
                {
                    break;
                }
                else {
                    qDebug() <<"but file is not complete";
                }
            }
        }
    }
    else
    {
        disconnect(m_pReply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
        m_pReply->abort();
        m_pReply->deleteLater();
        if(QFile::exists(dev)){
            QFile::remove(dev);
        }
        qDebug() <<"timeout";
    }
}

void ftpDownload::finished(QNetworkReply * reply)
{
    m_pFile->write(reply->readAll());
    m_pFile->flush();
    m_pFile->close();
    reply->deleteLater();
    qDebug()<<"success";
}


