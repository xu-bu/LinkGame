#include <QCoreApplication>
#include <QFuture>
#include <QThread>
#include <QtConcurrent>

#include "downloader.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Downloader *downloader=new Downloader();

//    createThread("http://fastsoft.onlinedown.net/down/pycharmpro2018.3.5.exe","c:/download","pycharm.exe");
//    createThread("https://w.wallhaven.cc/full/vg/wallhaven-vg3wm5.jpg","c:/download","1.jpg");
    downloader->createThread("https://w.wallhaven.cc/full/vg/wallhaven-vg3wm5.jpg","c:/download/1.jpg");
    downloader->createThread("http://fastsoft.onlinedown.net/down/pycharmpro2018.3.5.exe","c:/download/pycharm.exe");
    return a.exec();
}
