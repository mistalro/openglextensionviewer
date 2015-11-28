CONFIG += qt debug staticlib
TEMPLATE = lib
TARGET = extconstantlistwidget

QT += qt3support

ROOTDIR = ../..

INCLUDEPATH += \
        $$ROOTDIR/filesysascii

SOURCES = extconstantlistwidget.cpp

HEADERS = extconstantlistwidget.h
