TEMPLATE = lib
TARGET = extfunctionlistwidget

QT += qt3support

ROOTDIR = ../..

INCLUDEPATH += \
        $$ROOTDIR/filesysascii

SOURCES = extfunctionlistwidget.cpp

HEADERS = extfunctionlistwidget.h

CONFIG += qt debug staticlib
