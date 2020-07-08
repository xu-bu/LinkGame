#ifndef MYVIDEOWIDGET_H
#define MYVIDEOWIDGET_H
#include <QOpenGLWidget>

class myVideoWidget:public QOpenGLWidget
{
public:
    myVideoWidget(QWidget *p);
    void paintEvent(QPaintEvent *e);
    virtual ~myVideoWidget();
};

#endif // MYVIDEOWIDGET_H
