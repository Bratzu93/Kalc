#-------------------------------------------------
#
# Project created by QtCreator 2018-07-17T20:26:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kalc
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


SOURCES += \
        main.cpp \
    kalc.cpp \
    model/base.cpp \
    model/Punto.cpp \
    model/poligono.cpp \
    model/segmento.cpp \
    controller.cpp \
    leftarea.cpp \
    creazione.cpp \
    rightarea.cpp \
    newpoint.cpp \
    newsegmento.cpp \
    newpoligono.cpp \
    dettagli.cpp

HEADERS += \
    kalc.h \
    model/base.h \
    model/Punto.h \
    model/poligono.h \
    model/object.h \
    model/segmento.h \
    controller.h \
    leftarea.h \
    creazione.h \
    rightarea.h \
    newpoint.h \
    newsegmento.h \
    newpoligono.h \
    dettagli.h \
