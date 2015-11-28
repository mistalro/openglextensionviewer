CONFIG      += warn_on release designer plugin
TARGET   = extensionlist
TEMPLATE = lib
LANGUAGE = C++

QT += qt3support

ROOTDIR = ../..

INCLUDEPATH += \
	$$ROOTDIR/filesysascii

SOURCES = \
	../plugin-common/plugin.cpp \
	../extensionlistwidget/extensionlistwidget.cpp

HEADERS = \
	../plugin-common/plugin.h \
	../extensionlistwidget/extensionlistwidget.h \
	plugincustom.h

DESTDIR   = ../plugins

target.path == $$[QT_INSTALL_PLUGINS]/designer
sources.files == $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/customwidgetplugin
        
INSTALLS += target sources
      
DBFILE       = plugin.db
