#ifndef CHANGEINFO_H
#define CHANGEINFO_H

#include <QWidget>

namespace Ui {
class ChangeInfo;
}

class ChangeInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeInfo(QWidget *parent = 0);
    ~ChangeInfo();

private:
    Ui::ChangeInfo *ui;
};

#endif // CHANGEINFO_H
