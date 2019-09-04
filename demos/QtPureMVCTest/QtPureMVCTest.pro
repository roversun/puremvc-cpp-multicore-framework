#-------------------------------------------------
#
# Project created by QtCreator 2019-09-03T14:18:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtPureMVCTest
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
        appfacade.cpp \
        changedatacommand.cpp \
        data.cpp \
        dataproxy.cpp \
        getdatacommand.cpp \
        main.cpp \
        mainwindow.cpp \
        mainwindow2.cpp \
        uimediator.cpp

HEADERS += \
        appfacade.h \
        changedatacommand.h \
        common.h \
        data.h \
        dataproxy.h \
        getdatacommand.h \
        mainwindow.h \
        mainwindow2.h \
        uimediator.h

FORMS += \
        mainwindow.ui \
        mainwindow2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


DISTFILES +=

win32: LIBS += -L$$PWD/../../lib/vc/  -lPureMVCddll
unix:  LIBS += -L$$PWD/../../bin/gcc/ -lPureMVCd

INCLUDEPATH += $$PWD/../../include/PureMVC
DEPENDPATH += $$PWD/../../include/PureMVC
