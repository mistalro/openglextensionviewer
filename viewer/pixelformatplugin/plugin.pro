CONFIG   += warn_on release designer plugin
TARGET   = pixelformat
TEMPLATE = lib
LANGUAGE = C++

QT += qt3support

ROOTDIR = /home/msar/CORELIBS

INCLUDEPATH += \
	$$ROOTDIR/filesysascii

LIBS += \
	../pixelformatwidget/libpixelformatwidget.a

SOURCES  = \
        ../plugin-common/plugin.cpp 
        
HEADERS  = \
        ../plugin-common/plugin.h \
        ../pixelformatwidget/pixelformatwidget.h \
        plugincustom.h

DESTDIR   = ../plugins
      
target.path == $$[QT_INSTALL_PLUGINS]/designer
sources.files == $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/customwidgetplugin
        
INSTALLS += target sources
        
DBFILE    = plugin.db
