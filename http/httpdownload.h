#ifndef HTTPDOWNLOAD_H
#define HTTPDOWNLOAD_H

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

class httpdownload:public QObject
{
    Q_OBJECT
protected slots:
    void finished(QNetworkReply * reply);
public:
    httpdownload(QUrl url);
    void httpGet(QString sor, QString dev);
    void httpDownload(QString desName);
private:
    QFile * m_pFile;
    QNetworkReply *m_pReply;
    QNetworkAccessManager * m_pManager;
    QUrl m_pUrl;
    QString fileName;
    int totalLength;
};

#endif // HTTPDOWNLOAD_H
