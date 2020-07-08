
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
    this->m_bytesReceived=0;
    this->m_bytesTotal=0;
}

void Downloader::download(QString url,QString path,QString fileName)
{
//    setIsDownloading(true);

    QTimer timer;
    timer.setInterval(5000);  // 设置超时时间 5 秒
    timer.setSingleShot(true);  // 单次触发
    timer.start();
    QNetworkAccessManager mgr;
    QNetworkRequest req;
    QEventLoop event;
    req.setUrl(url);
    //解决重定向问题，否则会得不到header
    req.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    QNetworkReply *reply = mgr.head(req);
    connect(reply, &QNetworkReply::finished, &event, &QEventLoop::quit);
//    connect(&timer,&QTimer::timeout,&event,&QEventLoop::quit);
    event.exec();
    if (timer.isActive())
    {
        //获取请求响应时间
        auto cost = timer.remainingTime();
        qInfo() << "get header info cost" << cost << " ms";
        timer.stop();
        qlonglong length = reply->header(QNetworkRequest::ContentLengthHeader).toLongLong();
        qInfo() << "Content length:" << length;

        //获取响应范围，为Bytes代表支持多线程，为none代表不支持
        bool supportRange = (reply->rawHeader("Accept-Ranges") == QByteArrayLiteral("bytes"));
        qInfo() << "support Range:" << supportRange;

        //C++11的自动类型
        //time.elapsed()返回计时器从开始到现在经过的时间，单位为ms


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
    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
    //匿名函数()内填写参数列表
//    [=] 表示值传递方式捕捉所有父作用域的变量（包括this）
//    [&var] 表示引用传递捕捉变量var
//    [&] 表示引用传递捕捉所有父作用域的变量（包括this）
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
    //任务等分
    qlonglong segmentSize = length / CPUCount;
    //QPair是一个模板类用于存储两个item
    //这里用于存储每一块数据的起止位置
    QVector<QPair<qlonglong, qlonglong>> vec(CPUCount);
    //++i和i++效果是一样的
    for (int i = 0; i <CPUCount; ++i) {
        vec[i].first = i * segmentSize;
        vec[i].second = i * segmentSize + segmentSize - 1;
    }
    //余数部分加入最后一个
    vec[CPUCount -1].second += length % CPUCount;
    qWarning() << "main thread" << QThread::currentThreadId();
    //匿名函数捕捉QPair向量，返回qlonglong类型
    auto mapCaller = [&](const QPair<qlonglong, qlonglong> &pair) ->qlonglong{
        //qWarning和qDebug似乎没区别？
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
        //QEventLoop相当于死循环，就等着QNetworkReply发送finished信号
        QEventLoop event;
        connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error), reply, [&]{
            qWarning() << u8"出错" << reply->errorString();
            event.quit();
        });
        connect(reply, &QNetworkReply::finished, &event, &QEventLoop::quit);
        event.exec();
        qWarning() << "lambda " << hasWritePos - pair.first;
        return hasWritePos - pair.first;
    };

    //QFuture函数可以在不同线程中异步使用
    //似乎使用匿名函数捕获就不需要run了？
    QFuture<void> future =  QtConcurrent::map(vec, mapCaller);
    //利用QFutureWatcher监控future，如果future区别运行完毕就退出
    QFutureWatcher<void> futureWatcher;
    QEventLoop loop;
    //多线程情况下一般使用Qt::QueuedConnection
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

// 下载进度信息;
void Downloader::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
//    if (!m_isStop)
//    {
        m_bytesReceived = bytesReceived;
        m_bytesTotal = bytesTotal;
//        qDebug()<<bytesReceived;
//        // 更新下载进度;(加上 m_bytesCurrentReceived 是为了断点续传时之前下载的字节)
//        emit signalDownloadProcess(m_bytesReceived + m_bytesCurrentReceived, m_bytesTotal + m_bytesCurrentReceived);
        emit signalDownloadProcess(bytesReceived,bytesTotal);
//    }
}
