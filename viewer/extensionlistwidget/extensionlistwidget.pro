TEMPLATE = lib
TARGET = extensionlistwidget

QT += qt3support

ROOTDIR = ../..

INCLUDEPATH += \
        $$ROOTDIR/filesysascii

SOURCES = extensionlistwidget.cpp

HEADERS = extensionlistwidget.h

CONFIG += qt debug staticlib
