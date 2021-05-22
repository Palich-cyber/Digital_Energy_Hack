#-------------------------------------------------
#
# Project created by QtCreator 2021-05-22T10:47:13
#
#-------------------------------------------------

QT       += core gui sql opengl

win32:CONFIG(release, debug|release): LIBS += libOpenGL32 libGLu32
else:win32:CONFIG(debug, debug|release): LIBS += libOpenGL32 libGLu32
else:unix:!macx: LIBS += -lGL

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EnergyOracle
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
        EnergyOracle.cpp \
    Libs/Visualisation/camera3d.cpp \
    Libs/Visualisation/light3d.cpp \
    Libs/Visualisation/materiallibrary.cpp \
    Libs/Visualisation/materials.cpp \
    Libs/Visualisation/Scene.cpp \
    Libs/Visualisation/simpleelement.cpp \
    Libs/Visualisation/spaceobject3d.cpp \
    Libs/DataBase/DataBaseFunction.cpp

HEADERS += \
        EnergyOracle.h \
    Libs/Visualisation/camera3d.h \
    Libs/Visualisation/light3d.h \
    Libs/Visualisation/materiallibrary.h \
    Libs/Visualisation/materials.h \
    Libs/Visualisation/Scene.h \
    Libs/Visualisation/sceneconstants.h \
    Libs/Visualisation/simpleelement.h \
    Libs/Visualisation/spaceobject3d.h \
    Libs/Visualisation/transform.h \
    Libs/DataBase/DataBaseConstants.h \
    Libs/DataBase/DataBaseFunction.h \
    Libs/DataBase/DataBaseStructs.h

FORMS += \
        EnergyOracle.ui
