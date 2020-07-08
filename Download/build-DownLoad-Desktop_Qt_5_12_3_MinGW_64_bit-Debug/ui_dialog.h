/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(347, 254);
        Dialog->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/yumao.jpg);\n"
"\n"
"color:rgb(100, 100, 100)"));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 170, 101, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/63198a7c57c3ea975e12d91882686786.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 80, 161, 51));
        label->setStyleSheet(QString::fromUtf8("font: 13pt \".SF NS Text\";\n"
"font: 9pt \"Arial\";\n"
"background-image: url(:/new/prefix1/yumao.jpg);"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "\347\241\256\345\256\232\351\200\200\345\207\272", nullptr));
        label->setText(QApplication::translate("Dialog", "  \344\275\240\347\241\256\345\256\236\350\246\201\351\200\200\345\207\272\344\270\213\350\275\275\345\220\227\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
