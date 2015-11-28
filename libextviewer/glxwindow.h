// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _GLXWINDOW_H_
#define _GLXWINDOW_H_

// --------------------------------------------------------------------------
// Definition of the COpenGLXWindow class
// --------------------------------------------------------------------------

class COpenGLXWindow
{
public:

static Display *m_pdisplay;
static int      m_windowcount;

Colormap 	m_colormap;
Window 	 	m_window;
GLXContext 	m_glxcontext;
int             m_mapped;

// ----- Constructor and destructor -----------------------------------------

COpenGLXWindow( void ) 
	{ 
	m_pdisplay = NULL;
	m_windowcount = 0;
	m_colormap = 0;
	m_window = 0;
	m_glxcontext = NULL;
	m_mapped = 0;
	};

~COpenGLXWindow( void ) 
	{
	CloseWindow();
	};

// ----- Functions and procedures -------------------------------------------

int OpenDisplay( void );
int OpenWindow( int xlo, int ylo, int width, int height, 
		const XVisualInfo &xvptr, int map );

void CloseWindow( void );
void CloseDisplay( void );
int ActivateWindow( void );
void DeactivateWindow( void );
void GetExtensionString( int mode, char *pbuffer );

int CheckOpenGL( const XVisualInfo &xvref );
int CheckDirect( void );
XVisualInfo *GetVisualList( int &visualnum );
};

#endif	// _GLXWINDOW_H_
