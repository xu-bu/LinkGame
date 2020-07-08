#include <QCoreApplication>
#include <QDebug>

#include "ftpdownload.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ftpDownload *downloader=new ftpDownload();
    downloader->FtpSetHostPort("127.0.0.1",21);
    downloader->FtpGet("12.mp4","c:/download/12.mp4");
    return a.exec();
}
