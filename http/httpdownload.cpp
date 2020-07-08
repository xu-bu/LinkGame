#include "httpdownload.h"

httpdownload::httpdownload(QUrl url)
{
    m_pManager=new QNetworkAccessManager();
    m_pUrl=url;
    connect(m_pManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply *)));
}

void httpdownload::httpDownload(QString desName)
{
    //错误处理弹窗
//    if (!newUrl.isValid())
//        {
//            QMessageBox::information(this, QString::fromLocal8Bit("错误"),
//              QString("无效URL: %1 \n 错误信息: %2").arg(m_url, newUrl.errorString()));
//            return;
//        }

    fileName=QFileInfo(m_pUrl.path()).fileName();
    qDebug()<<fileName;
    QString fullName=desName+"/"+fileName;
    if(QFile::exists(fullName)){
        QFile::remove(fullName);
    }
    qDebug()<<fullName;
    m_pFile=new QFile(fullName);
    if(!m_pFile->open(QIODevice::WriteOnly))
    {
        qDebug()<<"error";
    }

    QTimer timer;
    timer.setInterval(5000);  // 设置超时时间 5 秒
    timer.setSingleShot(true);  // 单次触发
    m_pReply=m_pManager->get(QNetworkRequest(m_pUrl));
    QEventLoop eventLoop;
    connect(&timer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);
    connect(m_pReply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    timer.start();
    eventLoop.exec();

//    QByteArray  contentDisposition = m_pReply->rawHeader("Content-Disposition");
//    QString stringContentDisposition = QString::fromUtf8(contentDisposition);
//    qDebug()<<contentDisposition;
    if (timer.isActive())
    {
        timer.stop();
        totalLength = m_pReply->rawHeader("Content-Length").toInt();
//        if(m_pReply->error()==QNetworkReply::NoError)
//        {
//            QByteArray byteArray = m_pReply->readAll();
//            int reciveLength=0;
//            reciveLength += byteArray.count();
//            qDebug() << "recieve"<<reciveLength<<"Bytes";
//            Sleep(1000);
//            while (true)
//            {
//                if (m_pReply->isFinished())
//                {
//                    qDebug() <<"download complete";
//                }
//                if (totalLength == reciveLength)
//                {
//                    break;
//                }
//                else {
//                    qDebug() <<"but file is not complete";
//                    break;
//                }
//            }
//        }
    }
    else
    {
        disconnect(m_pReply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
        m_pReply->abort();
        m_pReply->deleteLater();
        if(QFile::exists(fullName)){
            QFile::remove(fullName);
        }
        qDebug() <<"timeout";
    }
}

void httpdownload::finished(QNetworkReply * reply)
{
    m_pFile->write(reply->readAll());
    m_pFile->flush();
    m_pFile->close();
    reply->deleteLater();
    qDebug()<<"success";
}
