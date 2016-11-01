#-------------------------------------------------
#
# Project created by QtCreator 2016-08-24T08:29:07
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Modelagem
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    octree/octree.cpp \
    object/object.cpp \
    scene.cpp \
    application.cpp \
    globaloptions.cpp \
    octree/octreenode.cpp \
    octree/octreeshape.cpp \
    octree/octreesphere.cpp \
    octree/octreecylinder.cpp \
    octree/octreecone.cpp \
    octree/octreebox.cpp \
    octree/octreetorus.cpp \
    octree/newoctreedialog.cpp \
    treewidget.cpp \
    octree/operateoctreedialog.cpp \
    octree/octreeunion.cpp \
    octree/octreeprism.cpp \
    octree/octreepyramid.cpp \
    raycastwidget.cpp \
    csg/csgobject.cpp \
    ray.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    octree/octree.h \
    object/object.h \
    scene.h \
    application.h \
    globaloptions.h \
    octree/octreenode.h \
    octree/octreeshape.h \
    octree/octreesphere.h \
    octree/octreecylinder.h\
    commondefs.h\
    octree/octreecone.h \
    octree/octreebox.h \
    octree/octreetorus.h \
    octree/newoctreedialog.h\
    treewidget.h \
    octree/operateoctreedialog.h \
    octree/octreeunion.h \
    octree/octreeprism.h \
    octree/octreepyramid.h \
    raycastwidget.h \
    csg/csgobject.h \
    ray.h

FORMS    += mainwindow.ui \
    octree/newoctreedialog.ui \
    octree/operateoctreedialog.ui

LIBS += -lopengl32

RESOURCES += \
    icons/icons.qrc
