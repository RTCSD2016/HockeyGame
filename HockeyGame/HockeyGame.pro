#-------------------------------------------------
#
# Project created by QtCreator 2016-12-29T22:41:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HockeyGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    render.cpp \
    gameobject.cpp \
    guimanager.cpp \
    guimain.cpp \
    gameobjects.cpp \
    collision.cpp \
    runthread.cpp \
    MotionControl.cpp \
    messenger.cpp \
    logicmanager.cpp

HEADERS  += \
    render.h \
    gameobject.h \
    guimanager.h \
    guimain.h \
    gameobjects.h \
    collision.h \
    runthread.h \
    MotionControl.h \
    messenger.h \
    logicmanager.h \
    messagetypes.h

FORMS    +=

DISTFILES += \
    table.png

RESOURCES += \
    resources.qrc

INCLUDEPATH += /home/magicxu/xenomai/xenomai-2.6.5/include

INCLUDEPATH += /home/magicxu/xenomai/xenomai-2.6.5/src/include

unix:!macx: LIBS += -L$$PWD/../../../../usr/xenomai/lib/ -lanalogy

INCLUDEPATH += $$PWD/../../../../usr/xenomai/include
DEPENDPATH += $$PWD/../../../../usr/xenomai/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/xenomai/lib/libanalogy.a

unix:!macx: LIBS += -L$$PWD/../../../../usr/xenomai/lib/ -lnative

INCLUDEPATH += $$PWD/../../../../usr/xenomai/include
DEPENDPATH += $$PWD/../../../../usr/xenomai/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/xenomai/lib/libnative.a

unix:!macx: LIBS += -L$$PWD/../../../../usr/xenomai/lib/ -lpsos

INCLUDEPATH += $$PWD/../../../../usr/xenomai/include
DEPENDPATH += $$PWD/../../../../usr/xenomai/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/xenomai/lib/libpsos.a

unix:!macx: LIBS += -L$$PWD/../../../../usr/xenomai/lib/ -lpthread_rt

INCLUDEPATH += $$PWD/../../../../usr/xenomai/include
DEPENDPATH += $$PWD/../../../../usr/xenomai/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/xenomai/lib/libpthread_rt.a

unix:!macx: LIBS += -L$$PWD/../../../../usr/xenomai/lib/ -lrtdm

INCLUDEPATH += $$PWD/../../../../usr/xenomai/include
DEPENDPATH += $$PWD/../../../../usr/xenomai/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/xenomai/lib/librtdm.a

unix:!macx: LIBS += -L$$PWD/../../../../usr/xenomai/lib/ -luitron

INCLUDEPATH += $$PWD/../../../../usr/xenomai/include
DEPENDPATH += $$PWD/../../../../usr/xenomai/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/xenomai/lib/libuitron.a

unix:!macx: LIBS += -L$$PWD/../../../../usr/xenomai/lib/ -lvrtx

INCLUDEPATH += $$PWD/../../../../usr/xenomai/include
DEPENDPATH += $$PWD/../../../../usr/xenomai/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/xenomai/lib/libvrtx.a

unix:!macx: LIBS += -L$$PWD/../../../../usr/xenomai/lib/ -lvxworks

INCLUDEPATH += $$PWD/../../../../usr/xenomai/include
DEPENDPATH += $$PWD/../../../../usr/xenomai/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/xenomai/lib/libvxworks.a

unix:!macx: LIBS += -L$$PWD/../../../../usr/xenomai/lib/ -lxenomai

INCLUDEPATH += $$PWD/../../../../usr/xenomai/include
DEPENDPATH += $$PWD/../../../../usr/xenomai/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/xenomai/lib/libxenomai.a


