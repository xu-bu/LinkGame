#include "myWidget.h"
#include <QApplication>
#include <QDebug>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWidget w;
    w.show();

//    QString fileName=argv[1];
    QString name = QString::fromLocal8Bit("C:/qt project/player/test.rmvb");
    if (name.isEmpty()) { return 0; }
    string file = name.toLocal8Bit().data();
    std::cout<<file<<endl;
    w.playMovie(file);
//    for (int i =0;i<argc;i++) {
//        qDebug()<<argv[i]<<endl;
//    }
    return a.exec();
}
