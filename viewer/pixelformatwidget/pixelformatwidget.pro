TEMPLATE = lib
TARGET =  pixelformatwidget

CONFIG += qt debug staticlib

QT += qt3support

ROOTDIR = ../..

INCLUDEPATH += \
        $$ROOTDIR/filesysascii

SOURCES = \
	pixelformatwidget.cpp \
	derivedpixelformatview.cpp

HEADERS = \
	pixelformatwidget.h \
	derivedpixelformatview.h 
