#-------------------------------------------------
#
# Project created by QtCreator 2017-06-21T18:48:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = library
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bookinout.cpp \
    search.cpp \
    addnewbook.cpp \
    book.cpp

HEADERS  += mainwindow.h \
    bookinout.h \
    search.h \
    addnewbook.h \
    book.h \
    global.h

FORMS    += mainwindow.ui \
    bookinout.ui \
    search.ui \
    addnewbook.ui

RESOURCES += \
    resource.qrc
