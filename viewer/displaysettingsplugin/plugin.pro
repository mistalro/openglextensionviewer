CONFIG   += warn_on release designer plugin 
TARGET   = displaysettings
TEMPLATE = lib
LANGUAGE = C++

QT += qt3support

ROOTDIR = ../..

INCLUDEPATH += \
	$$ROOTDIR/filesysascii

SOURCES  = \
	../plugin-common/plugin.cpp \
	../displaysettingswidget/displaysettingswidget.cpp 

HEADERS  = \
	../plugin-common/plugin.h \
	../displaysettingswidget/displaysettingswidget.h \
	plugincustom.h

DESTDIR   = ../plugins

target.path == $$[QT_INSTALL_PLUGINS]/designer
sources.files == $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/customwidgetplugin

INSTALLS += target sources

DBFILE    = plugin.db
