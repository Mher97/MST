#-------------------------------------------------
#
# Project created by QtCreator 2016-05-20T18:42:54
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MST
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphics_vertex.cpp \
    graphics_edge.cpp \
    logical_edge.cpp \
    graphics_text.cpp \
    about_window.cpp \
    dsu.cpp \
    media.cpp \
    graphics_graph.cpp \
    algorithm.cpp \
    prim.cpp \
    kruskal.cpp

HEADERS  += mainwindow.h \
    const.h \
    graphics_vertex.h \
    graphics_edge.h \
    logical_edge.h \
    graphics_text.h \
    about_window.h \
    dsu_exceptions.h \
    dsu.h \
    media.h \
    graphics_graph.h \
    algorithm.h \
    prim.h \
    kruskal.h

FORMS    += mainwindow.ui

CONFIG   += c++11


