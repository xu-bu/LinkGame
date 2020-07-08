//#ifndef DOWNLOADER_H
//#define DOWNLOADER_H
#pragma once
#include <QObject>
#include <QCoreApplication>
#include <QUrl>
class Downloader : public QObject {
    Q_OBJECT

//    Q_PROPERTY(bool isDownloading READ isDownloading WRITE setIsDownloading NOTIFY isDownloadingChanged)
public:
    Downloader();
    bool isDownloading() const
    {
        return m_isDownloading;
    }
    //��ȡheader��Ȼ�������Ƕ��̻߳��ǵ��߳�
    void download(QString url,QString path,QString fileName);
    void singleDownload(const QString &url,  const QString &filePath,const qint64 length=0);
    static void newDownload(QString url,QString absPath);
    static void createThread(QString url,QString absPath);
    int num;
    qint64 m_bytesReceived;
    qint64 m_bytesTotal;

signals:
    void signalDownloadProcess(qint64,qint64);

public slots:

    void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
protected:
//    void singleDownload(const QString &url,  const QString &filePath,const qint64 length=0);
    void mulitDownload(const QString &url, const qint64 length, const QString &filePath);
private:
    bool m_isDownloading = false;
    QUrl FTPurl;
};
//#endif
