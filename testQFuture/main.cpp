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

    // 在一个单独的线程中调用 hello()
    QFuture<void> f1 = QtConcurrent::run(hello, QString("Qter"));
    QFuture<void> f2 = QtConcurrent::run(hello, QString("Pythoner"));

    // 阻塞调用线程并等待计算完成，确保所有结果可用
    f1.waitForFinished();
    f2.waitForFinished();
}
