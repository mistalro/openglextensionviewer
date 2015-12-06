TEMPLATE = lib
CONFIG   = staticlib debug
TARGET  = extviewer

BASEDIR = ..

FLAGS = -Wall -DQT_QT3SUPPORT_LIB -DQT3_SUPPORT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
QMAKE_CFLAGS += -D_REENTRANT -Wall $$FLAGS
QMAKE_CXXFLAGS += -D_REENTRANT -Wall $$FLAGS

DEPENDPATH  += \
	$$BASEDIR/filesysascii

INCLUDEPATH += \
	$$BASEDIR/filesysascii

LIBS += -lfilesysascii

# Input
HEADERS += \
	ctrace.h \
	displaysettings.h \
	extcallbacks.h \
	extcode.h \
	extcodetest.h \
	extcodewin.h \
	extconfigfilesettings.h \
	extconst.h \
	extviewerio.h \
	extviewer.h \
	extensionlib.h \
	extentry.h \
	extentrylist.h \
	extfilesettingsio.h \
	extfilesettings.h \
	extheaderfiledata.h \
	extheaderfilesetio.h \
	extheaderfileset.h \
	extheaderfilefunc.h \
	extheaderfileignore.h \
	extheaderfilenew.h \
	extheaderfilesystem.h \
	extheaderfilevendor.h \
	extheaderfilegl.h \
	extheaderfileglx.h \
	extheaderfilecorearb.h \
	extheaderfilewgl.h \
	extheaderfileset.h \
	extregistrysettingsio.h \
	extregistrysettings.h \
	extscriptsettingsio.h \
	extscriptsettings.h \
	extscripttoken.h \
	extsiteinfoio.h \
	extsiteinfo.h \
	extsiteinfolistio.h \
	extsiteinfolist.h \
	funclist.h \
	glxwindow.h \
	filedownloader.h \
	pixelformat.h \
	pixelformatlist.h \
	strpattern.h \
	socketstream.h \
	sorters.h \
	tokenlist.h

SOURCES += \
	ctrace.cpp \
	displaysettings.cpp \
	extconfigfilesettingsio.cpp \
	extconfigfilesettings.cpp \
	extviewerio.cpp \
	extviewer.cpp \
	extentry.cpp \
	extentryio.cpp \
	extentrylist.cpp \
	extentrylistio.cpp \
	extfilesettingsio.cpp \
	extfilesettings.cpp \
	extheaderfiledata.cpp \
	extheaderfilesetio.cpp \
	extheaderfileset.cpp \
	extregistrysettingsio.cpp \
	extregistrysettings.cpp \
	extscriptsettingsio.cpp \
	extscriptsettings.cpp \
	extsiteinfoio.cpp \
	extsiteinfo.cpp \
	extsiteinfolistio.cpp \
	extsiteinfolist.cpp \
	glxwindow.cpp \	
	pixelformatlinux.cpp \
	pixelformatlist.cpp \
	rotatebits.cpp \
	strings.cpp \
	strstream.cpp \
	strpattern.cpp \
	tokenlist.cpp

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}
