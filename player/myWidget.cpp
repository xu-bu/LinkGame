#include "myWidget.h"
#include "ui_myWidget.h"
#include "main.cpp"
#include <QVBoxLayout>
#include <QDebug>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
    isPlaying=true;
    setWindowFlag(Qt::FramelessWindowHint);

    player=new QMediaPlayer(this);
    connect(player,&QMediaPlayer::positionChanged,this,&myWidget::updatePosition);
    videoWidget=new QVideoWidget(this);
    videoWidget->resize(700,500);
    player->setVideoOutput(videoWidget);
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::playMovie(string fileName)
{
    player->setMedia(QUrl::fromLocalFile(QString::fromStdString(fileName)));
    player->play();
}

//bool myWidget::event(QEvent *e)
//{
//    if(e->type()==QEvent::MouseButtonPress)
//    {
//        if(isPlaying)
//        {
//            player->pause();
//        }
//        else
//        {
//            player->play();
//        }
//    }
//}

void myWidget::on_pushButton_clicked()
{
    if(isPlaying)
    {
        player->pause();
        ui->pushButton->setText("play");
        isPlaying=false;
    }
    else
    {
        player->play();
        ui->pushButton->setText("pause");
        isPlaying=true;
    }
}

void myWidget::updatePosition(qint64 position)
{
//    qDebug()<<position<<endl;
    ui->horizontalSlider_seek->setMaximum(player->duration()/1000);
    ui->horizontalSlider_seek->setValue(position/1000);
    ui->label_now->setText(numberToTime(position/1000));
    ui->label_total->setText(numberToTime(player->duration()/1000));
}

QString myWidget::numberToTime(qint64 positon)
{
    int second=positon%60;
    int min=positon/60;
    if(second<10)
    {
        return QString::number(min)+":0"+QString::number(second);
    }
    else {
        return QString::number(min)+":"+QString::number(second);
    }
}

void myWidget::on_horizontalSlider_seek_sliderMoved(qint64 position)
{
    player->setPosition(position);
}
