//#ifndef DIALOGERROR_H
//#define DIALOGERROR_H
#pragma once
#include <QDialog>

namespace Ui {
class DialogError;
}

class DialogError : public QDialog
{
    Q_OBJECT

public:
    explicit DialogError(QWidget *parent = nullptr);
    ~DialogError();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogError *ui;
};

//#endif // DIALOGERROR_H
