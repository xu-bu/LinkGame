#include "changeinfo.h"
#include "ui_changeinfo.h"

ChangeInfo::ChangeInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeInfo)
{
    ui->setupUi(this);
}

ChangeInfo::~ChangeInfo()
{
    delete ui;
}
