// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Constants for the OpenGL extension creator class
// --------------------------------------------------------------------------

#define VAR_CONFIGFILE    "ConfigFile"
#define VAR_OPENGLHEADER  "OpenGLHeader"
#define VAR_GLXHEADER     "GLXHeader"
#define VAR_WGLHEADER     "WGLHeader"
#define VAR_OUTPUTHEADER  "OutputHeader"
#define VAR_OUTPUTSOURCE  "OutputSource"
#define VAR_SCRIPTFILE    "ScriptFile"

#define VAR_CLASSNAME     "ClassName"

#define VAR_FILE          "File"
#define VAR_VENDOR        "Vendor"
#define VAR_OPENGL        "OpenGL"
#define VAR_WGL           "WGL"
#define VAR_GLX           "GLX"

#define MODE_GL      0x0001
#define MODE_WGL     0x0002
#define MODE_GLX     0x0004

// --------------------------------------------------------------------------
// List of constants
// --------------------------------------------------------------------------

#define MAX_FUNCLIST      8192
#define MAX_EXTLIST       2048
#define MAX_VENDORLIST    2048
#define MAX_VERSIONLIST    128
#define MAX_CONSTANTLIST  4096
#define MAX_PREFUNCLIST    128

#define FLAG_OUTPUT		  0x0001    // Ouput extension flag
#define FLAG_NEWEXTENSION 0x0002	// New extension flag

#define RANGE_ALL     0x0001   // Select all extensions
#define RANGE_WGL     0x0002   // Select WGL extensions
#define RANGE_GL      0x0004   // Select OpenGL extensions
#define RANGE_GLX     0x0008   // Select GLX extensions

#define MAX_STRNAME 256
#define MAX_STRPATH 512

typedef char STRNAME[MAX_STRNAME];
typedef char STRPATH[MAX_STRPATH];
