#include <QCoreApplication>
#include <QCoreApplication>
#include <QDebug>

#include "httpdownload.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    QUrl url=QUrl("http://127.0.0.1:21/1.pdf");
    QUrl url=QUrl("https://w.wallhaven.cc/full/vg/wallhaven-vg3wm5.jpg");
    httpdownload *downloader=new httpdownload(url);
    downloader->httpDownload("c:/download");
    return a.exec();
}
