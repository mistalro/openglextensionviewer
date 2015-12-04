// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

const char *internalscript =
{
"<begin><main></begin>"
"<fileopen><outputheader>"
"<call><headerfile>"
"<fileclose>"
"<fileopen><outputsource>"
"<call><sourcefile>"
"<fileclose>"
"<end>"

"<begin><fileheader></begin>"
"// --------------------------------------------------------------------------\n"
"<if><cppmode>// <filetype> file for the <classname> <moduletype>\n<endif>"
"<if><cmode>// <filetype> file for the extension manager\n<endif>"
"//\n"
"// Stored in file <outputsource>\n"
"//\n"

"// File:   <filename>\n"
"// Author: Automatic code generator\n"
"// Date:   <time>\n"
"// System: <hostname>\n"
"// User:   <username>\n"
"// Script: <scriptfile>\n"
"// Config: <configfile>\n"
"// Path:   <filepath>\n"
"//\n"
"// From: extcode.h (Internal version)\n"
"// --------------------------------------------------------------------------\n"
"//\n"
"// This file is based on the following header files:\n"
"//\n"
"<foreach><extregistry>"
"// Set <extregistrycounter>\n"
"// <wglheader> - Version <wglversion>\n"
"// <glheader>  - Version <glversion>\n"
"// <glxheader> - Version <glxversion>\n"
"//\n<endfor>"
"// --------------------------------------------------------------------------\n" 
"//\n"
"// The following extensions are currently supported by this class:\n"
"//\n"
"<if><glnum>"
"// ----- <glmax> GL extensions ---------\n"
"//\n"
"<foreach><glext><if><selected>// <glcounter> <extname>\n<endif><endfor>"
"<endif>"

"<if><wglnum>"
"//\n"
"// ----- <wglmax> WGL extensions ----------\n"
"//\n"
"<foreach><wglext><if><selected>// <wglcounter> <extname>\n<endif><endfor>"
"<endif>"

"<if><glxnum>"
"//\n"
"// ----- <glxmax> GLX extensions ----------\n"
"//\n"
"<foreach><glxext><if><selected>// <glxcounter> <extname>\n<endif><endfor>"
"<endif>"

//"<uppercase><foreach><glext><extfunclist> <funcprefix> <funcname><funcproto><endfor>\n"
//"<normalcase>\n"
//"<foreach><glext><foreach><extfunclist><funcprefix> <funcname><funcheader>;\n<endfor><endfor>"
//"<foreach><glext><foreach><extconstlist>//  <constcounter>/<constmax>#define <constname> <constvalue>\n<endfor><endfor>"
//"<foreach><wglext><foreach><extconstlist>// <constcounter>/<constmax>#define <constname> <constvalue>\n<endfor><endfor>"
//"<foreach><glxext><foreach><extconstlist>// <constcounter>/<constmax>#define <constname> <constvalue><endfor><endfor>\n"
"// --------------------------------------------------------------------------\n"
"<end>\n"

// --------------------------------------------------------------------------
// ----- Header Prototype ---------------------------------------------------
// --------------------------------------------------------------------------
"\n"
"<begin><headerprototype></begin>"
"#ifdef <extname>\n"
"<if><cmode><foreach><extfunclist>extern <pfnproc> <funcname>;\n<endfor><endif>"
"<if><cppmode><foreach><extfunclist><pfnproc> <funcname>;\n<endfor><endif>"
"#endif\t\t// <extname>\n"
"<end>\n"

// --------------------------------------------------------------------------
// ----- Class constructors and destructor ----------------------------------
// --------------------------------------------------------------------------

"<begin><headercondes></begin>"
"// ----- Constructors -------------------------------------------------------\n"
"\n"
"<classname>( void );\n"
"\n"
"// ------ Destructors -------------------------------------------------------\n"
"\n"
"~<classname>();\n"
"\n"
"// ------ Initialisation routines -------------------------------------------\n"
"<end>"

"<begin><glgetprocaddress></begin>"
"// ----------------------------------------------------------------------------\n"
"// Find the call address of a WGL or GLX extension function\n"
"// ----------------------------------------------------------------------------\n"
"\n"
"void *<classname::>GetGLProcAddress( char *buf )\n"
"{\n"
"#ifdef _WIN32\n"
"\treturn( wglGetProcAddress( buf ) );\n"
"#endif\n"
"\n"
"#ifdef _GLX\n"
"\treturn( (void *) glXGetProcAddressARB( (const GLubyte *) buf ) );\n"
"#endif\n"
"\n"
"return( NULL );\n"
"}\n"
"<end>"

// --------------------------------------------------------------------------
// ----- Header file --------------------------------------------------------
// --------------------------------------------------------------------------

"<begin><headerfile></begin>"
"<call><fileheader>"
"\n"
"#ifndef __EXTMANAGER__\n"
"#define __EXTMANAGER__\n"
"\n"
"<if><cppmode>class <classname>\n"
"{\n"
"public:\n"
"<endif>"
"<if><extnum>// Extension presence flags\n"
"\n<endif>"
"<if><cmode>"
"<foreach><version>extern int m_OpenGL<versionvar>;\n<endfor>"
"<endif>"
"<if><cppmode>"
"<foreach><version>int m_OpenGL<versionvar>;\n<endfor>" 
"<endif>"
"\n"
"<if><cmode>"
"<foreach><glext><if><selected>extern int m_<extname>;\n<endif><endfor>"
"<endif>"

"<if><cppmode>"
"<foreach><glext><if><selected>int m_<extname>;\n<endif><endfor>"
"<endif>"
"<if><glnum>\n<endif>"

"<if><wglnum>#ifdef _WIN32\n"
"\n"
"<if><cmode><foreach><wglext><if><selected>extern int m_<extname>;\n<endif><endfor><endif>"
"<if><cppmode><foreach><wglext><if><selected>int m_<extname>;\n<endif><endfor>"
"<endif>"
"\n"
"#endif\t\t// _WIN32\n"
"\n<endif>"

"<if><glxnum>#ifdef _GLX\n"
"\n"
"<if><cmode>"
"<foreach><glxext><if><selected>extern int m_<extname>;\n<endif><endfor>"
"<endif>"
"<if><cppmode>"
"<foreach><glxext><if><selected>int m_<extname>;\n<endif><endfor>"
"<endif>"
"\n"
"#endif\t\t// _GLX\n"
"\n<endif>"

"<if><glfuncnum>"
"//\n"
"// ----- GL extensions --------\n"
"//\n"
"\n"
"#ifdef NONO\n"	// Needed to disable errors with GL AMD_multi_draw_indirect etc
"<foreach><glext><if><selected><if><funcnum><call><headerprototype>\n<endif><endif><endfor>"
"<endif>"
"#endif\n"	// Needed to disable errors as above

"<if><wglfuncnum>"
"//\n"
"// ----- WGL extensions --------\n"
"//\n"
"\n"
"<foreach><wglext><if><selected><if><funcnum><call><headerprototype>\n<endif><endif><endfor>"
"\n<endif>"

"<if><glxfuncnum>//\n"
"// ----- GLX extensions --------\n"
"//\n"
"\n"
"#ifdef NONO\n"	// Needed to disable errors with GLXgetprocaddressARB
"<foreach><glxext><if><selected><if><funcnum><call><headerprototype>\n<endif><endif><endfor>"
"<endif>"
"#endif\n\n"
"<if><wglfuncnum>int padding2[1024]; // Bodge to handle Visual Studio C++ bug\n\n<endif>"
"<if><cppmode><call><headercondes><endif>"
"void *GetGLProcAddress( char *buf );\n"
//"void *GetWGLProcAddress( char *pchname );\n"
"int  StringSearch( char *pext, char *pstring );\n"
"int  CheckGLExtension(  char *pchname );\n"
"void CheckOpenGLVersion( void );\n"
"<if><glnum>void CheckOpenGLExtensions( void );\n<endif>"

"<if><wglnum>void CheckWGLExtensions( void );\n"
"int  CheckWGLExtension( char *pchname );\n<endif>"

"<if><glxnum>void CheckGLXExtensions( void );\n"
"int  CheckGLXExtension( char *pchname );\n"
"<endif>"
"void ExtensionInit( void );\n"
"<if><glfuncnum>"
"\n"
"// ----- GL extensions -----------\n"
"\n"
"<foreach><glext><if><selected><if><funcnum>void Init_<extname>( void );\n<endif><endif><endfor>"
"<endif>"

"<if><wglnum>\n"
"// ----- WGL extensions --------\n"
"\n"
"#ifdef _WIN32\n"
"\n"
"<foreach><wglext><if><selected><if><funcnum>void Init_<extname>( void );\n<endif><endif><endfor>"
"\n"
"#endif\t\t// _WIN32\n"
"<endif>"
"<if><glxnum>\n"
"// ----- GLX extensions ---------\n"
"\n"
"#ifdef _GLX\n"
"\n"
"<foreach><glxext><if><selected><if><funcnum>void Init_<extname>( void );\n<endif><endif><endfor>"
"\n"
"#endif\t\t// _GLX\n"
"\n<endif>"

"<if><cppmode>"
"};\n"
"\n<endif>"
"#endif\t\t// __EXTMANAGER__\n"
"<end>\n"

// --------------------------------------------------------------------------
// ----- Header Init --------------------------------------------------------
// --------------------------------------------------------------------------

"<begin><headerinit></begin>"
"#ifdef <extname>\n"
"<if><cppmode><foreach><extfunclist>\t<funcname> = NULL;\n<endfor><endif>"
"<if><cmode><foreach><extfunclist><pfnproc>\t<funcname> = NULL;\n<endfor><endif>"
"#endif\t\t// <extname>\n"
"\n"
"<end>\n"

// --------------------------------------------------------------------------
// ----- Source Init --------------------------------------------------------
// --------------------------------------------------------------------------

"<begin><sourceinit></begin>"
"// --------------------------------------------------------------------------\n"
"// Initialise extension <extname>\n"
"//\n"
"// Inputs: None\n"
"//\n"
"// Outputs: None\n"
"//\n"
"// Results: None\n"
"//\n"
"// Effects: The extension is initialised\n"
"// --------------------------------------------------------------------------\n"
"\n"
"void <classname::>Init_<extname>( void )\n"
"{\n"
"#ifdef <extname>\n"
"if (!m_<extname>)\n" 
"\treturn;\n"
"<if><funcnum>\n<endif>"
"<foreach><extfunclist><funcname> = (<pfnproc>) GetGLProcAddress( \"<funcname>\");\n<endfor>"
"#endif\n"
"}\n"
"\n"
"<end>\n"


"<begin><extpresflagsc></begin>"
"\n// Extension presence flags\n"
"\n"
"<foreach><version>int m_OpenGL<versionvar> = 0;\n<endfor>"
"<foreach><glext><if><selected>int m_<extname> = 0;\n<endif><endfor>"
"<if><wglnum>\n"
"#ifdef _WIN32\n"
"\n"
"<foreach><wglext><if><selected><if><wgldef>int m_<extname> = 0;\n<endif><endif><endfor>"
"\n"
"#endif\t\t//_WIN32\n"
"\n<endif>"
"<if><glxnum>\n"
"#ifdef _GLX\n"
"\n"
"<foreach><glxext><if><selected><if><glxdef>int m_<extname> = 0;\n<endif><endif><endfor>"
"\n"
"#endif\t\t//_GLX\n"
"\n<endif>"
"<end>"

"<begin><extpresflagscpp></begin>"
"}\n"
"\n"
"// --------------------------------------------------------------------------\n"
"// Destructor\n"
"// --------------------------------------------------------------------------\n\n"
"<classname::>~<classname>( void )\n"
"{\n"
"\t// ... Destructor ...\n"
"}\n"
"\n"
"<end>"

"<begin><checkglext></begin>"
"// --------------------------------------------------------------------------\n"
"// Routine to check the OpenGL Extensions\n"
"//\n"
"// Inputs: None\n"
"//\n"
"// Outputs: None\n"
"//\n"
"// Results: None\n"
"//\n"
"// Effects: Status flags are set according to the OpenGL version present\n"
"// --------------------------------------------------------------------------\n"
"\n"
"void <classname::>CheckOpenGLExtensions( void )\n"
"{\n"
"<foreach><glext><if><selected>m_<extname> = CheckGLExtension( \"<extname>\" );\n<endif><endfor>"
"}\n"
"\n"
"<end>"


"<begin><checkwglext></begin>"
"// --------------------------------------------------------------------------\n"
"// Routine to check the presence of a Windows OpenGL extension\n"
"//\n"
"// Inputs: None\n"
"//\n"
"// Outputs: None\n"
"//\n"
"// Results: 1 is returned if the extension exists, 0 otherwise\n"
"//\n"
"// Effects: None\n"
"// --------------------------------------------------------------------------\n"
"\n"
"#ifdef _WIN32\n"
"\n"
"int <classname::>CheckWGLExtension( char *pchname )\n"
"{\n"
"GLubyte *pextstring;\n\n"
"HDC      hdc;\n"
"\n"
"hdc = wglGetCurrentDC();\n"
"PFNWGLGETEXTENSIONSSTRINGARBPROC wglproc;\n"
"\n"
"wglproc = (PFNWGLGETEXTENSIONSSTRINGARBPROC)\n"
"        wglGetProcAddress( \"wglGetExtensionsStringARB\" );\n"
"\n"
"if ( wglproc != NULL )\n"
"\tpextstring = (GLubyte*) wglproc(hdc);\n"
"/*\n"
"else\n"
"\tif ( wglGetExtensionsStringARB != NULL )\n"
"\t\tpextstring = (GLubyte *) wglGetExtensionsStringEXT();\n"
"*/\n"
"else\n"
"\treturn(0);\n"
"\n" 
"return( StringSearch( (char *) pextstring, (char *) pchname ) );\n"
"}\n"
"\n"
"// --------------------------------------------------------------------------\n"
"// Routine to check the WGL Extensions\n"
"//\n"
"// Inputs: None\n"
"//\n"
"// Outputs: None\n"
"//\n"
"// Results: None\n"
"//\n"
"// Effects: Status flags are set according to the OpenGL version present\n"
"// --------------------------------------------------------------------------\n"
"\n"
"void <classname::>CheckWGLExtensions( void )\n"
"{\n"
"<foreach><wglext><if><selected>m_<extname> = CheckWGLExtension( \"<extname>\" );\n<endif><endfor>"
"}\n"
"#endif\t\t// #ifdef _WIN32\n"
"\n"
"<end>"

"<begin><checkglxext></begin>"
"// --------------------------------------------------------------------------\n"
"// Routine to check the presence of a Windows OpenGL extension\n"
"//\n"
"// Inputs: None\n"
"//\n"
"// Outputs: None\n"
"//\n"
"// Results: 1 is returned if the extension exists, 0 otherwise\n"
"//\n"
"// Effects: None\n"
"// --------------------------------------------------------------------------\n"
"\n"
"#ifdef _GLX\n"
"int <classname::>CheckGLXExtension( char *pchname )\n"
"{\n"
"Display *dptr;\n"
"int result = 0;\n"
"char *pstr;\n"
"\n"
"dptr = XOpenDisplay(NULL);\n"
"\n"
"if ( dptr )\n"
"\t{\n"
"\tpstr = (char *) glXGetClientString( dptr, GLX_EXTENSIONS );\n"
"\n"
"\tresult = ( strstr( pstr, pchname) != NULL );\n"
"\n"
"\tpstr = (char *) glXQueryExtensionsString( dptr, 0 );\n"
"\n"
"\tresult |= ( strstr( pstr, pchname) != NULL );\n"
"\n"
"\tpstr = (char *) glXQueryServerString( dptr, 0, GLX_EXTENSIONS );\n" 
"\n"
"\tresult |= ( strstr( pstr, pchname) != NULL );\n"
"\n"
"\tXCloseDisplay(dptr);\n"
"\t}\n"
"\n"
"return( result );\n"
"}\n"
"\n"
"// --------------------------------------------------------------------------\n"
"// Routine to check the GLX Extensions\n"
"//\n"
"// Inputs: None\n"
"//\n"
"// Outputs: None\n"
"//\n"
"// Results: None\n"
"//\n"
"// Effects: Status flags are set according to the OpenGL version present\n"
"// --------------------------------------------------------------------------\n"
"\n"
"void <classname::>CheckGLXExtensions( void )\n"
"{\n"
"<foreach><glxext><if><selected>m_<extname> = CheckGLXExtension( \"<extname>\" );\n<endif><endfor>"
"}\n"
"#endif\t\t// #ifdef _GLX\n"
"\n"
"<end>"

// --------------------------------------------------------------------------
// ----- Source file --------------------------------------------------------
// --------------------------------------------------------------------------

"<begin><sourcefile></begin>"
"<call><fileheader>"
"\n"
"\n#ifdef _WIN32\n"
"//#include \"stdafx.h\"\n"
"#endif\n"
"\n"
"#include <stdio.h>\n"
"#include <string.h>\n"
"#include <GL/gl.h>\n"
"#include <GL/glext.h>\n"
"#ifdef _WIN32\n"
"#include <GL/wglext.h>\n"
"#endif\n"
"\n"
"#define _GLX\n"
"\n"
"#ifdef  _GLX\n"
"#include <X11/X.h>\n"
"#include <X11/Xlib.h>\n"
"#include <X11/Xutil.h>\n"
"\n"
"#include <GL/glx.h>\n" 
"#include <GL/glxext.h>\n"
"#endif\n"
"\n"
"#include \"<outputheader>\"\n"
/*
"\n"
"// Include this so we can read the libGL.so.1 file directly\n"
"\n"
"#ifdef LOAD_LIBRARY\n"
"#include <dlfcn.h>\n"
"#endif\n"
*/
"\n"
"<if><cppmode>"
"// --------------------------------------------------------------------------\n"
"// Default constructor\n"
"// --------------------------------------------------------------------------\n"
"\n"
"<classname::><classname>( void )\n"
"{\n<endif>"

"<if><glfuncnum>"
"// ----- GL extensions -------\n"
"\n"
"<foreach><glext><if><selected><if><funcnum><call><headerinit><endif><endif><endfor>"
"\n<endif>"

"<if><wglfuncnum>"
"// ----- WGL extensions --------\n"
"#ifdef _WIN32\n"
"\n"
"<foreach><wglext><if><selected><if><funcnum><call><headerinit><endif><endif><endfor>"
"#endif\t\t// _WIN32\n"
"<endif>"

"<if><glxfuncnum>"
"// ----- GLX extensions --------\n"
"\n"
"#ifdef _GLX\n"
"\n"
"<foreach><glxext><if><selected><if><funcnum><call><headerinit><endif><endif><endfor>"
"#endif\t\t// _GLX\n"
"<endif>"

"<if><cmode><call><extpresflagsc><endif>"
"<if><cppmode><call><extpresflagscpp><endif>"
"<call><glgetprocaddress>\n"
"// --------------------------------------------------------------------------\n"
"// Routines to search for an extension string in another string\n"
"//\n"
"// Inputs: None\n"
"//\n"
"// Outputs: None\n"
"//\n"
"// Results: 1 is returned if the substring is found, 0 otherwise\n"
"//\n"
"// Effects: None\n"
"// --------------------------------------------------------------------------\n"
"\n"
"int <classname::>StringSearch( char *pext, char *pstring )\n"
"{\n"
"char *pstart, *pend;\n"
"int len;\n"
"\n"
"if ( !(pstart = strstr( pext, pstring ) ) )\n"
"\treturn( 0 );\n"
"\n"
"if ( (pstart > pext) && (pstart[-1] != ' ') )\n"
"	 return( 0 );\n"
"\n"
"len  = strlen(pstring);\n"
"pend = pstart + len;\n"
"\n"
"while ( pstart && (*pend != ' ') && (*pend != '\\0') )\n"
"    {\n"
"	 pstart = strstr( pend, pstring );\n"
"\n"
"	 if ( pstart )\n"
"        pend   = pstart + len;\n"
"	 else\n"
"        pend = NULL;\n"
"	 }\n"
"\n"
"if ( !pend )\n"
"    return( 0 );\n"
"\n"
"if ( (*pend != ' ') && (*pend != '\\0' ) )\n"
"    return( 0 );\n"
"\n"	
"return( 1 );\n"
"}\n"
"\n"
"// --------------------------------------------------------------------------\n"
"// Routine to check the presence of an OpenGL extension\n"
"//\n"
"// Inputs: None\n"
"//\n"
"// Outputs: None\n"
"//\n"
"// Results: 1 is returned if the extension exists, 0 otherwise\n"
"//\n"
"// Effects: None\n"
"// --------------------------------------------------------------------------\n"
"\n"
"int <classname::>CheckGLExtension( char *pchname )\n"
"{\n"
"GLubyte *pextstring = (GLubyte *) glGetString(GL_EXTENSIONS);\n"
"\n"
"return( StringSearch( (char *) pextstring, (char *) pchname ) );\n"
"}\n"
"\n"
"// --------------------------------------------------------------------------\n"
"// Routine to check whether an OpenGL version is supported\n"
"// The OpenGL version is specified using integer format <hi>.<lo>\n"
"//\n" 
"// Inputs: shi - first integer <hi>\n"
"//         slo - second integer <lo>\n"
"//\n"
"// Outputs: None\n"
"//\n" 
"// Results: true if the version is supported, false otherwise\n"
"// --------------------------------------------------------------------------\n"
"\n"
"bool CheckGLVersion( unsigned int shi, unsigned int slo )\n"
"{\n"
"unsigned int dlo, dhi, dvlo;\n"
"\n" 
"// Get the device driver number\n"
"GLubyte *pextstring = (GLubyte *) glGetString(GL_VERSION);\n"
"\n" 
"sscanf( (char *) pextstring, \"%d.%d.%d\", &dhi, &dlo, &dvlo);\n"
"\n" 
"return (dhi > shi) || ((dhi == shi) && (dlo >= slo));\n"
"}\n"
"\n"
"// --------------------------------------------------------------------------\n"
"// Routine to check the OpenGL Version\n"
"//\n"
"// Inputs: None\n"
"//\n"
"// Outputs: None\n"
"//\n"
"// Results: None\n"
"//\n"
"// Effects: Status flags are set according to the OpenGL version present\n"
"// --------------------------------------------------------------------------\n"
"\n"
"void <classname::>CheckOpenGLVersion( void )\n"
"{\n"
//"<foreach><version>m_OpenGL<versionvar> = CheckGLExtension( \"<versionname>\" );\n<endfor>"
"<foreach><version>m_OpenGL<versionvar> = CheckGLVersion( <versionnumber> );\n<endfor>"
"}\n"
"\n"
"<if><glnum><call><checkglext><endif>"
"<if><wglnum><call><checkwglext><endif>"
"<if><glxnum><call><checkglxext><endif>"

"// --------------------------------------------------------------------------\n"
"// Main initialisation routine\n"
"//\n"
"// Inputs: None\n"
"//\n"
"// Outputs: None\n"
"//\n"
"// Results: None\n"
"//\n"
"// Effects: The initialisation routines are called\n"
"// --------------------------------------------------------------------------\n"
"\n"
"void <classname::>ExtensionInit( void )\n" 
"{\n"
/*
"#ifdef LOAD_LIBRARY\n"
"m_libhandler = dlopen( \"/usr/lib/libGL.so.1\", RTLD_NOW | RTLD_GLOBAL );\n"
"// printf( \"Opened handler = %08X\\n\", (unsigned int) m_libhandler );\n"
"#endif\n"
"\n"
*/
"CheckOpenGLVersion();\n"
"<if><glnum>CheckOpenGLExtensions();\n<endif>"

"<if><glfuncnum>\n"
"<foreach><glext><if><selected><if><funcnum>Init_<extname>();\n<endif><endif><endfor>"
"\n"
"<endif>"

"<if><wglnum>"
"\n"
"#ifdef _WIN32\n"
"CheckWGLExtensions();\n"
"<foreach><wglext><if><selected><if><funcnum>Init_<extname>();\n<endif><endif><endfor>"
"#endif\n"
"\n"
"<endif>"

"<if><glxnum>"
"#ifdef _GLX\n"
"CheckGLXExtensions();\n"
"<foreach><glxext><if><selected><if><funcnum>Init_<extname>();\n<endif><endif><endfor>"
"#endif\n"
"<endif>"

/*
"#ifdef LOAD_LIBRARY\n"
"//printf( \"Closing libhandler %08X\\n\", (unsigned int) m_libhandler );\n"
"dlclose( m_libhandler );\n"
"#endif // LOAD_LIBRARY\n"
*/
"}\n"
"\n"
"<foreach><glext><if><selected><if><funcnum><call><sourceinit><endif><endif><endfor>"

"<if><wglnum>"
"#ifdef _WIN32\n"
"<foreach><wglext><if><selected><if><funcnum><call><sourceinit><endif><endif><endfor>"
"#endif\n<endif>"

"<if><glxfuncnum>"
"#ifdef _GLX\n"
"<foreach><glxext><if><selected><if><funcnum><call><sourceinit><endif><endif><endfor>"
"#endif // _GLX\n"
"<endif>"
"<end>\n"
};

