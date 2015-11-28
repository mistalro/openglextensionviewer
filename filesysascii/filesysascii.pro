TEMPLATE = lib
CONFIG   = staticlib debug

TARGET   = filesysascii
BASEDIR = ..

FLAGS = -DQT_QT3SUPPORT_LIB -DQT3_SUPPORT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
QMAKE_CFLAGS += -D_REENTRANT -Wall $$FLAGS
QMAKE_CXXFLAGS += -D_REENTRANT -Wall $$FLAGS

# Input
HEADERS += \
	filesysascii.h \
	io_boolarray.h \
	io_bool.h \
	io_bytearray.h \
	io_byte.h \
	io_doublearray.h \
	io_double.h \
	io_floatarray.h \
	io_float.h \
	io_intarray.h \
	io_integer.h \
	io_longarray.h \
	io_long.h \
	io_par.h \
	io_shortarray.h \
	io_short.h \
	io_string.h \
	io_system.h \
	tokenentry.h \
	virtualfsascii.h

SOURCES += \
	io_boolarray.cpp \
	io_bytearray.cpp \
	io_doublearray.cpp \
	io_floatarray.cpp \
	io_intarray.cpp \
	io_longarray.cpp \
	io_par.cpp \
	io_shortarray.cpp \
	io_string.cpp \
	tokenentry.cpp \
	virtualfsascii.cpp \
	virtualfsglobal.cpp

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}
