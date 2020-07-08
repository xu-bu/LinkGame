#include <QCoreApplication>
#include <QtConcurrent/QtConcurrentRun>
#include <QDebug>

void hello(const QString &name)
{
    qDebug() << "Hello" << name << "from" << QThread::currentThread();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Main Thread" << QThread::currentThread();

    // ��һ���������߳��е��� hello()
    QFuture<void> f1 = QtConcurrent::run(hello, QString("Qter"));
    QFuture<void> f2 = QtConcurrent::run(hello, QString("Pythoner"));

    // ���������̲߳��ȴ�������ɣ�ȷ�����н������
    f1.waitForFinished();
    f2.waitForFinished();
}
