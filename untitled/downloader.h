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
    //获取header，然后决定是多线程还是单线程
    void download(QString url,QString path,QString fileName);
    void singleDownload(const QString &url,  const QString &filePath,const qint64 length=0);
    static void newDownload(QString url,QString absPath);
    void createThread(QString url,QString absPath);

signals:

//    void isDownloadingChanged(bool isDownloading);

public slots:
//    void setIsDownloading(bool isDownloading)
//    {
//        if (m_isDownloading == isDownloading)
//            return;

//        m_isDownloading = isDownloading;
//        emit isDownloadingChanged(m_isDownloading);
//    }
protected:
//    void singleDownload(const QString &url,  const QString &filePath,const qint64 length=0);
    void mulitDownload(const QString &url, const qint64 length, const QString &filePath);
private:
    bool m_isDownloading = false;
//    bool m_isDownloading = true;
    QUrl FTPurl;
};
