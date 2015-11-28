CONFIG   += warn_on release designer plugin 
TARGET   = extconstantlist
TEMPLATE = lib
LANGUAGE = C++

QT += qt3support

ROOTDIR = ../..

INCLUDEPATH += \
	$$ROOTDIR/filesysascii

HEADERS  += \
	../plugin-common/plugin.h \
	../extconstantlistwidget/extconstantlistwidget.h

SOURCES  += \
	../plugin-common/plugin.cpp \
	../extconstantlistwidget/extconstantlistwidget.cpp
	
DESTDIR   = ../plugins

target.path == $$[QT_INSTALL_PLUGINS]/designer
sources.files == $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/customwidgetplugin

INSTALLS += target sources

DBFILE    = plugin.db
