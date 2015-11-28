# set the include path for X, qt and KDE
INCLUDES = $(all_includes)

# these are the headers for your project
noinst_HEADERS = extdirector.h displaysettingsdlg.h registryfileprogressdlg.h scripteditordlg.h scripteditordlg.h generateprogressdlg.h headerfileprogressdlg.h registryprogressdlg.h extensiondlg.h updateextensionsdlg.h exitapplicationdlg.h exitapplicationbasedlg.h headerdownloadprogressdlg.h checksystemprogressdlg.h extensionviewdlg.h aboutdlg.h
# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

messages: rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/extdirector.pot

KDE_ICON = extdirector

#########################################################################
# APPLICATION SECTION
#########################################################################
# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = extdirector

# the application source, library search path, and link libraries
extdirector_SOURCES = main.cpp extdirector.cpp mainwindowdlg.cpp mainwindowbasedlg.ui displaysettingsbasedlg.ui extensionbasedlg.ui aboutbasedlg.ui aboutbasedlg.cpp aboutbasedlg.h aboutdlg.h aboutdlg.moc.cpp outputfilesettingsbasedlg.ui outputfilesettingsdlg.cpp outputfilesettingsbasedlg.cpp outputfilesettingsbasedlg.h outputfilesettingsdlg.h outputfilesettingsdlg.moc.cpp registrysettingsbasedlg.ui registrysettingsdlg.cpp registrysettingsbasedlg.cpp registrysettingsbasedlg.h registrysettingsdlg.h registrysettingsdlg.moc.cpp registryaddsitebasedlg.ui registryaddsitedlg.cpp registryaddsitebasedlg.cpp registryaddsitebasedlg.h registryaddsitedlg.h registryaddsitedlg.moc.cpp headerfileprogressbasedlg.ui pixelformatbasedlg.ui registryfileprogressbasedlg.ui scripteditorbasedlg.ui updateextensionsbasedlg.ui pixelformatdlg.cpp displaysettingsdlg.cpp registryfileprogressdlg.cpp scripteditordlg.cpp generateprogressbasedlg.ui generateprogressdlg.cpp headerfileprogressdlg.cpp registryprogressdlg.cpp extensionbasedlg.cpp extensiondlg.cpp extensiondlg.moc.cpp updateextensionsdlg.cpp registryprogressbasedlg.ui displaysettingsbasedlg.cpp mainwindowbasedlg.cpp pixelformatbasedlg.cpp pixelformatbasedlg.h pixelformatdlg.h displaysettingsdlg.moc.cpp generateprogressdlg.moc.cpp headerfileprogressdlg.moc.cpp pixelformatdlg.moc.cpp registryfileprogressdlg.moc.cpp registryprogressdlg.moc.cpp scripteditordlg.moc.cpp updateextensionsdlg.moc.cpp scripteditorbasedlg.cpp headerfileprogressbasedlg.cpp headerfileprogressbasedlg.moc headerfileprogressbasedlg.moc registryfileprogressbasedlg.cpp registryprogressbasedlg.cpp generateprogressbasedlg.cpp updateextensionsbasedlg.cpp exitapplicationbasedlg.ui exitapplicationbasedlg.cpp exitapplicationbasedlg.moc exitapplicationdlg.cpp exitapplicationdlg.moc.cpp headerdownloadprogressdlg.cpp headerdownloadprogressbasedlg.ui headerdownloadprogressdlg.moc.cpp headerdownloadprogressbasedlg.cpp checksystemprogressbasedlg.ui checksystemprogressdlg.cpp checksystemprogressdlg.moc.cpp checksystemprogressbasedlg.cpp extensionviewbasedlg.ui extensionviewdlg.cpp extensionviewdlg.moc.cpp extensionviewbasedlg.cpp configfilesettingsdlg.cpp configfilesettingsbasedlg.cpp configfilesettingsbasedlg.h configfilesettingsdlg.h configfilesettingsdlg.moc.cpp

extdirector_LDFLAGS = $(KDE_RPATH) $(all_libraries)
extdirector_LDADD = $(top_builddir)/src/pixelformatwidget/libpixelformatwidget.a $(top_builddir)/src/displaysettingswidget/libdisplaysettingswidget.a $(top_builddir)/src/libextcreator/libextcreator.a $(top_builddir)/src/extfunctionlistwidget/libextfunctionlistwidget.a $(top_builddir)/src/extconstantlistwidget/libextconstantlistwidget.a $(top_builddir)/src/extensionlistwidget/libextensionlistwidget.a -lGL $(LIB_KDEUI) $(top_builddir)/src/webpagelistwidget/libwebpagelistwidget.a $(top_builddir)/src/xmltreelib/libxmltree.a

# this is where the desktop file will go 
shelldesktopdir   = $(kde_appsdir)/Utilities
shelldesktop_DATA = extdirector.desktop

# this is where the shell's XML-GUI resource file goes
shellrcdir   = $(kde_datadir)/extdirector
shellrc_DATA = extdirectorui.rc

SUBDIRS = templates libextcreator pixelformatwidget extconstantlistwidget extfunctionlistwidget extensionlistwidget webpagelistwidget xmltreelib
