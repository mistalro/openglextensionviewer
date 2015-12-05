// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Header file to include all other header files
// --------------------------------------------------------------------------

#define _LINUX

#include <ios>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <string>
#include <vector>
#include <stack>

#include "strstream.h"
#include "strpattern.h"

// --------------------------------------------------------------------------
// Q. Why is these here? 
// A. Qt won't play nice with X11, especially with constants like 
//    "Above" "Below" "Always" and "None" (The ABBA problem).
//    Therefore we must restrict access to these headers to those files 
//    that actually need to use them. Everywhere else just sees a void 
//    pointer and is none the wiser.
// --------------------------------------------------------------------------

#ifdef _EXTENSIONLIB_INTERNAL_
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xproto.h>
#include <X11/extensions/Xrandr.h>

#include "GL/gl.h"
#include "GL/glx.h"
#include "glxwindow.h"
#else
struct XVisualInfo;
#endif

#ifndef _EXTENSIONLIB_
#define _EXTENSIONLIB_
#include "virtualfsascii.h"

#include "sorters.h"

#include "extcallbacks.h"
#include "pixelformat.h"
#include "pixelformatlist.h"
#include "tokenlist.h"
#include "extconst.h"

#include "extentryio.h"
#include "extentry.h"

#include "extentrylistio.h"
#include "extentrylist.h"

#include "extscripttoken.h"
#include "funclist.h"

#include "extsiteinfoio.h"
#include "extsiteinfo.h"

#include "extsiteinfolistio.h"
#include "extsiteinfolist.h"

#include "extfilesettingsio.h"
#include "extfilesettings.h"

#include "extscriptsettingsio.h"
#include "extscriptsettings.h"

#include "extheaderfiledata.h"

#include "extheaderfilefunc.h"
#include "extheaderfileignore.h"
#include "extheaderfilenew.h"
#include "extheaderfilesystem.h"
#include "extheaderfilevendor.h"
#include "extheaderfileversion.h"
#include "extheaderfilegl.h"
#include "extheaderfileglx.h"
#include "extheaderfilecorearb.h"
#include "extheaderfilewgl.h"

#include "extheaderfilesetio.h"
#include "extheaderfileset.h"

#include "extregistrysettingsio.h"
#include "extregistrysettings.h"

#include "extconfigfilesettingsio.h"
#include "extconfigfilesettings.h"

#include "extviewerio.h"
#include "extviewer.h"
#include "displaysettings.h"
#include "filedownloader.h"
#include "socketstream.h"
#endif

extern void ExtractServerPath( char *src, char *server, char *path );

void stl_strupr( std::string &str );
void stl_strlwr( std::string &str );
void stl_hostname( std::string &str );
void stl_getusername( std::string &str );
void stl_strdel( std::string &str, int delch );
void stl_getcwd( std::string &str );
void stl_itoa( std::string &str, int value );


