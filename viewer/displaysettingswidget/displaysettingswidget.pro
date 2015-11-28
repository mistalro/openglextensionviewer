TEMPLATE = lib
TARGET = displaysettingswidget

QT += qt3support

ROOTDIR = ../..

INCLUDEPATH += \
        $$ROOTDIR/filesysascii

HEADERS = deriveddisplaysettingsview.h \
	  displaysettingswidget.h

SOURCES = displaysettingswidget.cpp \
	  deriveddisplaysettingsview.cpp 

CONFIG += qt debug staticlib
