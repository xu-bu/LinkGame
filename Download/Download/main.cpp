#include "downloadwindow.h"
#include "userwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    UserWindow w;
//    w.show();
    DownLoadWindow *downloadWindow=new DownLoadWindow();
    downloadWindow->show();
    return a.exec();
}
