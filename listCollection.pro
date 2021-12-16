#-------------------------------------------------
#
# Project created by QtCreator 2021-12-16T09:27:23
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = listCollection
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    model/ListTableModel.cpp \
    model/SubmitModel.cpp \
    model/UnsubmitModel.cpp \
    dataManager/infoState.cpp

HEADERS += \
        mainwindow.h \
    model/ListTableModel.h \
    model/SubmitModel.h \
    model/UnsubmitModel.h \
    dataManager/infoState.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/model
INCLUDEPATH += $$PWD/dataManager

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
