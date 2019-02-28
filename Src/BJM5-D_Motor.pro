#-------------------------------------------------
#
# Project created by QtCreator 2018-09-11T11:41:34
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BJM5-D
TEMPLATE = app

DESTDIR = "../exe"

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

## halcon ################
#includes
INCLUDEPATH += "$$(HALCONROOT)/include"
INCLUDEPATH += "$$(HALCONROOT)/include/halconcpp"
#libs
QMAKE_LIBDIR  += "$$(HALCONROOT)/lib/$$(HALCONARCH)"
win32:LIBS    += "$$(HALCONROOT)/lib/$$(HALCONARCH)/halconcpp.lib" \
                 "$$(HALCONROOT)/lib/$$(HALCONARCH)/halcon.lib" \

## HK x64 ################
#includes
INCLUDEPATH += "../"
INCLUDEPATH += "../HikvisionCpp/Includes"\
                "../HikvisionCpp/Includes/Render"\
                "../HikvisionCpp/Includes/GenICam"

#libs
QMAKE_LIBDIR  += "../HikvisionCpp/Libraries/win64"
win32:LIBS    += "../HikvisionCpp/Libraries/win64/MvCameraControl.lib" \

#glog
win32: LIBS += -L$$PWD/../glog/ -llibglog

INCLUDEPATH += $$PWD/../glog
DEPENDPATH += $$PWD/../glog

#Operator
win32: LIBS += -L$$PWD/../Operator/ -lHOperator

INCLUDEPATH += $$PWD/../Operator
DEPENDPATH += $$PWD/../Operator



FORMS    += mainwindow.ui \
    dialogprogress.ui \
    paramSetDialog.ui

DISTFILES +=

RESOURCES += \
    icon.qrc

RC_ICONS = pic.ico

HEADERS += \
    Camera.h \
    cplc.h \
    dialogprogress.h \
    mainwindow.h \
    param.h \
    paramSetDialog.h \
    qcamera1.h \
    qcamera2.h \
    qcamera3.h \
    qcamera4.h \
    qcamera5.h \
    qhalconwindow.h \
    sanling_plc.h \
    paramSetDialog.h

SOURCES += \
    Camera.cpp \
    cplc.cpp \
    dialogprogress.cpp \
    main.cpp \
    mainwindow.cpp \
    param.cpp \
    paramSetDialog.cpp \
    qcamera2.cpp \
    qcamera3.cpp \
    qcamera4.cpp \
    qcamera5.cpp \
    qhalconwindow.cpp \
    sanling_plc.cpp \
    qcamera1.cpp \
    paramSetDialog.cpp

