/********************************************************************************
** Form generated from reading UI file 'downloadwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADWINDOW_H
#define UI_DOWNLOADWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownLoadWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QWidget *tab_2;
    QWidget *tab_3;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *DownLoadWindow)
    {
        if (DownLoadWindow->objectName().isEmpty())
            DownLoadWindow->setObjectName(QString::fromUtf8("DownLoadWindow"));
        DownLoadWindow->resize(743, 501);
        DownLoadWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/yumao.jpg);\n"
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
        centralwidget = new QWidget(DownLoadWindow);
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
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(112, 430, 111, 51));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/300px-078Rapidash.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(40, 30, 661, 381));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(40, 11, 601, 311));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 30, 72, 15));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 150, 72, 15));
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(172, 30, 261, 21));
        lineEdit_3 = new QLineEdit(tab_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(170, 150, 261, 21));
        lineEdit_4 = new QLineEdit(tab_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(170, 280, 261, 21));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 280, 72, 15));
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(500, 150, 93, 41));
        tabWidget->addTab(tab_3, QString());
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(660, 10, 80, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(450, 430, 141, 51));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/pkq.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 430, 121, 51));
        DownLoadWindow->setCentralWidget(centralwidget);

        retranslateUi(DownLoadWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DownLoadWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DownLoadWindow)
    {
        DownLoadWindow->setWindowTitle(QApplication::translate("DownLoadWindow", "DownLoadWindow", nullptr));
        pushButton_2->setText(QApplication::translate("DownLoadWindow", "\351\200\200 \345\207\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DownLoadWindow", "\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DownLoadWindow", "\344\270\213\350\275\275", nullptr));
        label->setText(QApplication::translate("DownLoadWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QApplication::translate("DownLoadWindow", "\346\226\260\345\257\206\347\240\201", nullptr));
        label_4->setText(QApplication::translate("DownLoadWindow", "\345\206\215\346\254\241\347\241\256\350\256\244", nullptr));
        pushButton_6->setText(QApplication::translate("DownLoadWindow", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("DownLoadWindow", "\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        pushButton_7->setText(QApplication::translate("DownLoadWindow", "log in", nullptr));
        pushButton->setText(QApplication::translate("DownLoadWindow", "\346\226\260\345\273\272\344\270\213\350\275\275", nullptr));
        pushButton_3->setText(QApplication::translate("DownLoadWindow", "\344\270\213\350\275\275\351\200\211\344\270\255\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DownLoadWindow: public Ui_DownLoadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADWINDOW_H
