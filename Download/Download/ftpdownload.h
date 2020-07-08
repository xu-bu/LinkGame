#ifndef FTPDOWNLOAD_H
#define FTPDOWNLOAD_H

//QT += network
//QT += widgets
#include <QFile>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QByteArray>
#include <QFileInfo>
#include <QDir>
#include <QTime>
#include <QTimer>
#include <QEventLoop>
#include <windows.h>

class ftpDownload:public QObject//ʹ��connect��Ҫ�̳�QObject��дQ_OBJECT��,����ᱨ��û�вۺ���
{
    Q_OBJECT
protected slots:
    void finished(QNetworkReply * reply);
public:
    ftpDownload();
    void FtpGet(QString sor, QString dev);
    void FtpSetUserInfor(QString user, QString pwd);
    void FtpSetHostPort(QString str, int port =21);
private:
    QFile * m_pFile;
    QNetworkReply *m_pReply;
    QNetworkAccessManager * m_pManager;
    QUrl m_pUrl;
    QString fileName;
    int totalLength;
};

#endif // FTPDOWNLOAD_H
