#-------------------------------------------------
#
# Project created by QtCreator 2020-01-09T16:08:56
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServer2
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    cuser.cpp

HEADERS  += widget.h \
    cuser.h

FORMS    += widget.ui

CONFIG += C++11
