#-------------------------------------------------
#
# Project created by QtCreator 2016-07-11T19:08:59
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CompanyDataManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    databasehandler.cpp

HEADERS  += mainwindow.h \
    databasehandler.h

FORMS    += mainwindow.ui
