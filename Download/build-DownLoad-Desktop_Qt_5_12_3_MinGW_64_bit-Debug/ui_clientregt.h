/********************************************************************************
** Form generated from reading UI file 'clientregt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTREGT_H
#define UI_CLIENTREGT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientregt
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QWidget *clientregt)
    {
        if (clientregt->objectName().isEmpty())
            clientregt->setObjectName(QString::fromUtf8("clientregt"));
        clientregt->resize(434, 300);
        clientregt->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/yumao.jpg);"));
        label = new QLabel(clientregt);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 80, 51, 21));
        label_2 = new QLabel(clientregt);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 160, 31, 21));
        lineEdit = new QLineEdit(clientregt);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 80, 181, 21));
        lineEdit_2 = new QLineEdit(clientregt);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 160, 181, 21));
        pushButton = new QPushButton(clientregt);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 220, 93, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/pkq.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        retranslateUi(clientregt);

        QMetaObject::connectSlotsByName(clientregt);
    } // setupUi

    void retranslateUi(QWidget *clientregt)
    {
        clientregt->setWindowTitle(QApplication::translate("clientregt", "Form", nullptr));
        label->setText(QApplication::translate("clientregt", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("clientregt", "\345\257\206\347\240\201", nullptr));
        pushButton->setText(QApplication::translate("clientregt", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientregt: public Ui_clientregt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTREGT_H
