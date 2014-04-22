#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T08:56:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WakfuBDataReader
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    BinaryReader.h \
    BinaryReaders/InteractiveElementTemplate.h \
    BinaryReaders/InteractiveElementModel.h

FORMS    += mainwindow.ui

include(BinaryReaders/BinaryReaders.pri)
