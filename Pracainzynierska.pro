#-------------------------------------------------
#
# Project created by QtCreator 2015-12-30T16:30:18
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pracainzynierska
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    opengl.cpp \
    warning.cpp \
    glwidget.cpp \
    dane.cpp \
    warning2.cpp

HEADERS  += mainwindow.h \
    opengl.h \
    warning.h \
    glwidget.h \
    dane.h \
    warning2.h

FORMS    += mainwindow.ui \
    opengl.ui \
    warning.ui \
    dane.ui \
    warning2.ui
