#-------------------------------------------------
#
# Project created by QtCreator 2015-02-06T12:18:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
RESOURCES =
TARGET = ProjectGUI
TEMPLATE = app

INCLUDEPATH += C:/opencv/mingw/install/include
LIBS += -L "C:/opencv/mingw/install/x64/mingw/bin"

LIBS +=  -lopencv_core249d -lopencv_imgproc249d -lopencv_highgui249d -lopencv_ml249d -lopencv_video249d -lopencv_features2d249d -lopencv_calib3d249d -lopencv_objdetect249d -lopencv_contrib249d -lopencv_legacy249d -lopencv_flann249d


SOURCES += main.cpp\
        mainwindow.cpp \
    qopencvwidget.cpp \
    detectface.cpp \
    genderclassification.cpp \
    globals.cpp \
    advertutilities.cpp

HEADERS  += mainwindow.h \
    qopencvwidget.h \
    detectface.h \
    genderclassification.h \
    globals.h \
    advertutilities.h

FORMS    += mainwindow.ui
