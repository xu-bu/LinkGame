/********************************************************************************
** Form generated from reading UI file 'dialogerror.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGERROR_H
#define UI_DIALOGERROR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogError
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *DialogError)
    {
        if (DialogError->objectName().isEmpty())
            DialogError->setObjectName(QString::fromUtf8("DialogError"));
        DialogError->resize(400, 222);
        DialogError->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/yumao.jpg);\n"
"color:rgb(100, 100, 100)"));
        pushButton = new QPushButton(DialogError);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 150, 113, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/300px-040Wigglytuff.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        label = new QLabel(DialogError);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 50, 261, 41));
        label->setStyleSheet(QString::fromUtf8("font: 13pt \"American Typewriter\";\n"
"font: 9pt \"Sitka Small\";"));

        retranslateUi(DialogError);

        QMetaObject::connectSlotsByName(DialogError);
    } // setupUi

    void retranslateUi(QDialog *DialogError)
    {
        DialogError->setWindowTitle(QApplication::translate("DialogError", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("DialogError", "OK", nullptr));
        label->setText(QApplication::translate("DialogError", "\350\257\267\350\276\223\345\205\245\344\273\245\357\274\232http(s)/file/ftp\345\274\200\345\244\264\347\232\204\351\223\276\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogError: public Ui_DialogError {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGERROR_H
