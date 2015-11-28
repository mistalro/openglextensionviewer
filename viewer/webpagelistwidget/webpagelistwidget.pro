TEMPLATE = lib
TARGET = webpagelistwidget

QT += qt3support

ROOTDIR = ../..

INCLUDEPATH += \
	$$ROOTDIR/filesysascii

DEPENDPATH += \
	$$ROOTDIR/filesysascii \

SOURCES = webpagelistwidget.cpp webpagelistview.cpp

HEADERS = webpagelistwidget.h webpagelistview.h

CONFIG += qt debug staticlib
