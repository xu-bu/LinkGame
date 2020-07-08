#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QFile>
#include <string>

using namespace std;

namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = nullptr);
    ~myWidget();
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    void playMovie(string fileName);
    bool isPlaying;
//    virtual bool event(QEvent *e)override;
    QString fileName;
    QString numberToTime(qint64 positon);

public slots:
//    void on_videowidget_play();
    void updatePosition(qint64 positon);

private slots:
    void on_pushButton_clicked();


    void on_horizontalSlider_seek_sliderMoved(qint64 position);

private:
    Ui::myWidget *ui;
};

#endif // WIDGET_H
