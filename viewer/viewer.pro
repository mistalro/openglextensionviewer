TEMPLATE = app

CONFIG += qt debug

QT += qt3support

BASEDIR = ..

LIBEXTVIEWER = $$BASEDIR/libextviewer
FORMBASE      = FORMS-4
FILEASCIILIB  = $$BASEDIR/filesysascii

SUBDIRS += \
        viewer/displaysettingsplugin \
        viewer/displaysettingswidget \
        viewer/extconstantlistplugin \
        viewer/extconstantlistwidget \
        viewer/extfunctionlistplugin \
        viewer/extfunctionlistwidget \
        viewer/extensionlistplugin \
        viewer/extensionlistwidget \
        viewer/pixelformatplugin \
        viewer/pixelformatwidget \
        viewer/webpagelistplugin \
        viewer/webpagelistwidget 

DEPENDPATH += \
		$$BASEDIR/filesysascii \
		$$LIBEXTVIEWER \
		pixelformatwidget \
		displaysettingswidget \
		extconstantlistwidget \
		extfunctionlistwidget \
		extensionlistwidget \
		webpagelistwidget \
		pixelformatwidget \
		webpagelistwidget

INCLUDEPATH += . \
		$$BASEDIR/filesysascii \
		$$LIBEXTVIEWER \
		pixelformatwidget \
		displaysettingswidget \
		extconstantlistwidget \
		extfunctionlistwidget \
		extensionlistwidget \
		webpagelistwidget \
		webpagelistwidget

LIBS += \
	-Lpixelformatwidget \
	-Ldisplaysettingswidget \
	-Lextconstantlistwidget \
	-Lextfunctionlistwidget \
	-Lextensionlistwidget \
	-Lwebpagelistwidget \
	-L$$FILEASCIILIB \
	-L$$LIBEXTVIEWER 

LIBS += -lextfunctionlistwidget \
	-lextconstantlistwidget \
	-lextensionlistwidget \
	-lpixelformatwidget \
	-ldisplaysettingswidget \
	-lwebpagelistwidget \
	-lextviewer \
	-lfilesysascii \
	-lGL \
	-lX11 \
	-lXrandr \
	-lcurl

FORMS = $$FORMBASE/aboutbasedlg.ui \
	$$FORMBASE/checksystemprogressbasedlg.ui \
	$$FORMBASE/configfilesettingsbasedlg.ui \
	$$FORMBASE/displaysettingsbasedlg.ui \
	$$FORMBASE/exitapplicationbasedlg.ui \
	$$FORMBASE/extensionbasedlg.ui \
	$$FORMBASE/extensionviewbasedlg.ui \
	$$FORMBASE/findextensionspecbasedlg.ui \
	$$FORMBASE/findfuncconstbasedlg.ui \
	$$FORMBASE/generateprogressbasedlg.ui \
	$$FORMBASE/headerdownloadprogressbasedlg.ui \
	$$FORMBASE/headerfileprogressbasedlg.ui \
	$$FORMBASE/mainwindowbasedlg.ui \
	$$FORMBASE/outputfilesettingsbasedlg.ui \
	$$FORMBASE/pixelformatbasedlg.ui \
	$$FORMBASE/registryaddsitebasedlg.ui \
	$$FORMBASE/registryfileprogressbasedlg.ui \
	$$FORMBASE/registryprogressbasedlg.ui \
	$$FORMBASE/registrysettingsbasedlg.ui \
	$$FORMBASE/scripteditorbasedlg.ui \
	$$FORMBASE/updateextensionsbasedlg.ui

# Input
HEADERS += aboutdlg.h \
	checksystemprogressdlg.h \
	configfilesettingsdlg.h \
	derivedlistviewitem.h \
	displaysettingsdlg.h \
	viewer.h \
	exitapplicationdlg.h \
	extensiondlg.h \
	extensionviewdlg.h \
	findextensionspecdlg.h \
	findfuncconstdlg.h \
	generateprogressdlg.h \
	headerdownloadprogressdlg.h \
	headerfileprogressdlg.h \
	mainwindowdlg.h \
	outputfilesettingsdlg.h \
	pixelformatdlg.h \
	registryaddsitedlg.h \
	registryfileprogressdlg.h \
	registryprogressdlg.h \
	registrysettingsdlg.h \
	scripteditordlg.h \
	updateextensionsdlg.h

SOURCES += \
	main.cpp \
	mainwindowdlg.cpp \
	checksystemprogressdlg.cpp \
	configfilesettingsdlg.cpp \
	displaysettingsdlg.cpp \ 
	exitapplicationdlg.cpp \
	extensiondlg.cpp \
	extensionviewdlg.cpp \
	findfuncconstdlg.cpp \
	findextensionspecdlg.cpp \
	generateprogressdlg.cpp \
	headerdownloadprogressdlg.cpp \
	headerfileprogressdlg.cpp \
	extensionlistbox.cpp \
	outputfilesettingsdlg.cpp \
	pixelformatdlg.cpp \
	registryaddsitedlg.cpp \
	registryfileprogressdlg.cpp \
	registryprogressdlg.cpp \
	registrysettingsdlg.cpp \
	scripteditordlg.cpp \
	updateextensionsdlg.cpp

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}


