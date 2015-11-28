CONFIG   += warn_on release designer plugin
TARGET   = webpagelist
TEMPLATE = lib
LANGUAGE = C++

QT += qt3support

ROOTDIR = /home/msar/CORELIBS

INCLUDEPATH += \
        $$ROOTDIR/filesysascii

SOURCES  = \
        ../plugin-common/plugin.cpp \
        ../webpagelistwidget/webpagelistwidget.cpp \
	../webpagelistwidget/webpagelistview.cpp

HEADERS  = \
        ../plugin-common/plugin.h \
        ../webpagelistwidget/webpagelistwidget.h \
	../webpagelistwidget/webpagelistview.h \
        plugincustom.h

DESTDIR   = ../plugins

target.path == $$[QT_INSTALL_PLUGINS]/designer
sources.files == $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/customwidgetplugin

#INCLUDEPATH += .. ../webpagelistwidget

INSTALLS += target sources

DBFILE    = plugin.db
