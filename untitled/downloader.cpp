#include "downloader.h"
#include "filewrite.h"

#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QtConcurrent>

#define CPUCount 4

Downloader::Downloader()
{

}

void Downloader::download(QString url,QString path,QString fileName)
{
//    setIsDownloading(true);

    QTimer timer;
    timer.setInterval(5000);  // ���ó�ʱʱ�� 5 ��
    timer.setSingleShot(true);  // ���δ���
    timer.start();
    QNetworkAccessManager mgr;
    QNetworkRequest req;
    QEventLoop event;
    req.setUrl(url);
    //����ض������⣬�����ò���header
    req.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    QNetworkReply *reply = mgr.head(req);
    connect(reply, &QNetworkReply::finished, &event, &QEventLoop::quit);
//    connect(&timer,&QTimer::timeout,&event,&QEventLoop::quit);
    event.exec();
    if (timer.isActive())
    {
        //��ȡ������Ӧʱ��
        auto cost = timer.remainingTime();
        qInfo() << "get header info cost" << cost << " ms";
        timer.stop();
        qlonglong length = reply->header(QNetworkRequest::ContentLengthHeader).toLongLong();
        qInfo() << "Content length:" << length;

        //��ȡ��Ӧ��Χ��ΪBytes����֧�ֶ��̣߳�Ϊnone����֧��
        bool supportRange = (reply->rawHeader("Accept-Ranges") == QByteArrayLiteral("bytes"));
        qInfo() << "support Range:" << supportRange;

        //C++11���Զ�����
        //time.elapsed()���ؼ�ʱ���ӿ�ʼ�����ھ�����ʱ�䣬��λΪms


//        QString filename = QFileInfo(url).fileName();
        QString absPath=path+"/"+fileName;
        if (supportRange) {
//            this->m_isDownloading=true;
            mulitDownload(url, length, absPath);
        } else {
            this->m_isDownloading=true;
            singleDownload(url, absPath);
        }
    //    setIsDownloading(false);
    }
    else {
        qDebug()<<"error";
    }
    this->m_isDownloading=false;
}


void Downloader::singleDownload(const QString &url, const QString &filename, const qint64 length)
{
    QFile file(filename);
    if (file.exists()) {
        file.remove();
    }
    if (!file.open(QFile::WriteOnly))
    {
        qWarning() << file.errorString();
        return;
    }
    QNetworkAccessManager mgr;
    QTime time;
    time.start();
    QNetworkRequest req;
    req.setUrl(url);
    req.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    auto reply = mgr.get(req);
    //��������()����д�����б�
//    [=] ��ʾֵ���ݷ�ʽ��׽���и�������ı���������this��
//    [&var] ��ʾ���ô��ݲ�׽����var
//    [&] ��ʾ���ô��ݲ�׽���и�������ı���������this��
    connect(reply, &QNetworkReply::readyRead, this, [&](){
        file.write(reply->readAll());
    });
    QEventLoop event;
    connect(reply, &QNetworkReply::finished, &event, &QEventLoop::quit);
    event.exec();
    file.close();
    auto cost = time.elapsed();
    qWarning() << "cost" << cost;
}

void Downloader::mulitDownload(const QString &url, const qint64 length, const QString &filePath)
{
    QFile file(filePath);
    if (file.exists()) {
        file.remove();
    }
    if (!file.open(QFile::ReadWrite))
    {
        qWarning() << file.errorString();
        return;
    }
    bool ok = file.resize(length);
    qWarning() << "resize" << ok << file.size();
    ok = file.setPermissions(QFileDevice::ReadUser | QFileDevice::WriteUser | QFileDevice::ReadGroup | QFileDevice::WriteGroup);
    qWarning() << "set permission " << ok;
    FileWriter fileWriter(&file);

    QTime time;
    time.start();
    //����ȷ�
    qlonglong segmentSize = length / CPUCount;
    //QPair��һ��ģ�������ڴ洢����item
    //�������ڴ洢ÿһ�����ݵ���ֹλ��
    QVector<QPair<qlonglong, qlonglong>> vec(CPUCount);
    //++i��i++Ч����һ����
    for (int i = 0; i <CPUCount; ++i) {
        vec[i].first = i * segmentSize;
        vec[i].second = i * segmentSize + segmentSize - 1;
    }
    //�������ּ������һ��
    vec[CPUCount -1].second += length % CPUCount;
    qWarning() << "main thread" << QThread::currentThreadId();
    //����������׽QPair����������qlonglong����
    auto mapCaller = [&](const QPair<qlonglong, qlonglong> &pair) ->qlonglong{
        //qWarning��qDebug�ƺ�û����
        qWarning() << "lambda start" << pair.first << pair.second << QThread::currentThreadId();
        QNetworkAccessManager mgr;
        QNetworkRequest req;
        req.setUrl(url);
        req.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
        req.setRawHeader("Range", QString("bytes=%1-%2").arg(pair.first).arg(pair.second).toUtf8());
        QNetworkReply *reply = mgr.get(req);
        qlonglong hasWritePos = pair.first;
        const qint64 bufSize = 1024 * 32;
        QByteArray data(bufSize, 0);
        connect(reply, &QNetworkReply::readyRead, this, [&](){
            auto d = reply->readAll();
            qint64 realSize =fileWriter.writeTo(hasWritePos, d);
            hasWritePos += realSize;
        }, Qt::DirectConnection);
        //QEventLoop�൱����ѭ�����͵���QNetworkReply����finished�ź�
        QEventLoop event;
        connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error), reply, [&]{
            qWarning() << u8"����" << reply->errorString();
            event.quit();
        });
        connect(reply, &QNetworkReply::finished, &event, &QEventLoop::quit);
        event.exec();
        qWarning() << "lambda " << hasWritePos - pair.first;
        return hasWritePos - pair.first;
    };

    //QFuture���������ڲ�ͬ�߳����첽ʹ��
    //�ƺ�ʹ��������������Ͳ���Ҫrun�ˣ�
    QFuture<void> future =  QtConcurrent::map(vec, mapCaller);
    //����QFutureWatcher���future�����future����������Ͼ��˳�
    QFutureWatcher<void> futureWatcher;
    QEventLoop loop;
    //���߳������һ��ʹ��Qt::QueuedConnection
    connect(&futureWatcher, &QFutureWatcher<void>::finished,
            &loop, &QEventLoop::quit, Qt::QueuedConnection);
    futureWatcher.setFuture(future);
    if (!future.isFinished()) {
        qWarning() << "not finished, wait";
        loop.exec();
    }
    file.close();
    auto cost = time.elapsed();
    qWarning() << "end cost" << cost;
}

void Downloader::newDownload(QString url,QString absPath)
{
    Downloader *downloader=new Downloader();
    downloader->singleDownload(url,absPath);
}

void Downloader::createThread(QString url,QString absPath)
{
    QFuture <void> thread=QtConcurrent::run(Downloader::newDownload,url,absPath);
}
