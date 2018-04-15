#-------------------------------------------------
#
# Project created by QtCreator 2018-04-11T23:05:41
#
#-------------------------------------------------

QT += core gui qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JsLogo
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
        MainW.cpp \
    DisWidget.cpp \
    utils.cpp \
    TurtleHelper.cpp

HEADERS  += MainW.h \
	DisWidget.h \
    utils.h \
    TurtleHelper.h

RESOURCES += \
    resource.qrc

OTHER_FILES += \
	README.md

DISTFILES += \
    data/img/complex.png \
    data/img/complex2.png \
    data/img/complex3.png \
    data/img/coord.png \
    data/img/draw.png \
    data/img/forward.png \
    data/img/pen.png \
    data/img/running.png \
    data/img/turn.png \
    data/img/visible.png
