/********************************************************************************
** Form generated from reading UI file 'newloadwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWLOADWINDOW_H
#define UI_NEWLOADWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewLoadWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_4;
    QProgressBar *progressBar;
    QLabel *label_4;
    QLabel *label_5;
    QProgressBar *progressBar_2;
    QLabel *label_6;
    QProgressBar *progressBar_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NewLoadWindow)
    {
        if (NewLoadWindow->objectName().isEmpty())
            NewLoadWindow->setObjectName(QString::fromUtf8("NewLoadWindow"));
        NewLoadWindow->resize(658, 654);
        NewLoadWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/yumao.jpg);\n"
"QPushButton{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:2px solid white;border-radius:10px;\n"
"}\n"
" \n"
"QPushButton:hover{ \n"
"background-color: rgba(255, 255, 255, 150);\n"
"border:2px solid white;border-radius:10px;\n"
"}\n"
" \n"
"\n"
"QPushButton:pressed{\n"
"background-color: rgba(255, 255, 255, 150);\n"
"border:2px solid white;border-radius:10px;\n"
"padding-left:6px;\n"
"padding-top:6px;\n"
"}"));
        centralwidget = new QWidget(NewLoadWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:2px solid white;border-radius:10px;\n"
"}\n"
" \n"
"QPushButton:hover{ \n"
"background-color: rgba(255, 255, 255, 150);\n"
"border:2px solid white;border-radius:10px;\n"
"}\n"
" \n"
"\n"
"QPushButton:pressed{\n"
"background-color: rgba(255, 255, 255, 150);\n"
"border:2px solid white;border-radius:10px;\n"
"padding-left:6px;\n"
"padding-top:6px;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 150, 51, 21));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 140, 391, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 290, 121, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/098ad8b4dc34862a4290ddd5e93eb249.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 290, 113, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/83f245157afef398ed1830a40b671ad3.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(560, 230, 71, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/300px-131Lapras.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(140, 230, 391, 32));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(18, 235, 51, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 60, 41, 21));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 60, 391, 31));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(270, 290, 121, 41));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(160, 360, 331, 23));
        progressBar->setValue(24);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 360, 131, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 400, 131, 31));
        progressBar_2 = new QProgressBar(centralwidget);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(160, 400, 331, 23));
        progressBar_2->setValue(24);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 450, 131, 31));
        progressBar_3 = new QProgressBar(centralwidget);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setGeometry(QRect(160, 450, 331, 23));
        progressBar_3->setValue(24);
        NewLoadWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NewLoadWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 658, 17));
        NewLoadWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(NewLoadWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NewLoadWindow->setStatusBar(statusbar);

        retranslateUi(NewLoadWindow);

        QMetaObject::connectSlotsByName(NewLoadWindow);
    } // setupUi

    void retranslateUi(QMainWindow *NewLoadWindow)
    {
        NewLoadWindow->setWindowTitle(QApplication::translate("NewLoadWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("NewLoadWindow", "\346\226\207\344\273\266\345\220\215:", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QApplication::translate("NewLoadWindow", "\346\231\256\351\200\232\344\270\213\350\275\275", nullptr));
        pushButton_2->setText(QApplication::translate("NewLoadWindow", "\351\200\200\345\207\272", nullptr));
        pushButton_3->setText(QApplication::translate("NewLoadWindow", "\346\265\217\350\247\210", nullptr));
        label_2->setText(QApplication::translate("NewLoadWindow", "\344\270\213\350\275\275\345\210\260:", nullptr));
        label_3->setText(QApplication::translate("NewLoadWindow", "\347\275\221\345\235\200:", nullptr));
        pushButton_4->setText(QApplication::translate("NewLoadWindow", "\345\244\232\347\272\277\347\250\213\344\270\213\350\275\275", nullptr));
        label_4->setText(QApplication::translate("NewLoadWindow", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("NewLoadWindow", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("NewLoadWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewLoadWindow: public Ui_NewLoadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWLOADWINDOW_H
