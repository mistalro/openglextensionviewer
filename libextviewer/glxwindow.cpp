// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#define _EXTENSIONLIB_INTERNAL_

#include "extensionlib.h"

#include "X11/X.h"
#include "X11/Xlib.h"
#include "X11/Xutil.h"
#include "X11/Xproto.h"

#ifndef _EXTGLXWINDOW_H_
#define _EXTGLXWINDOW_H_
#include "GL/gl.h"
#include "GL/glx.h"
#include "glxwindow.h"
#endif

// --------------------------------------------------------------------------
// Definition of the static members
// --------------------------------------------------------------------------

Display *COpenGLXWindow::m_pdisplay = 0;
int COpenGLXWindow::m_windowcount = 0;

// --------------------------------------------------------------------------
// Get the list of visuals
// --------------------------------------------------------------------------

XVisualInfo *COpenGLXWindow::GetVisualList( int &maxformats )
{
XVisualInfo *pxvlist;

OpenDisplay();

if ( m_pdisplay != 0 )
	pxvlist = XGetVisualInfo( m_pdisplay, VisualNoMask, NULL, &maxformats );
else
	{
	maxformats = 0;
	pxvlist = NULL;
	}

//CloseDisplay();

return( pxvlist );
}

// --------------------------------------------------------------------------
// Check if a visual can use OpenGL
// --------------------------------------------------------------------------

int COpenGLXWindow::CheckOpenGL( const XVisualInfo &xvref )
{
GLint intvalue;

OpenDisplay();

glXGetConfig( m_pdisplay, (XVisualInfo *) &xvref, GLX_USE_GL, &intvalue );

CloseDisplay();

return(intvalue);
}

// --------------------------------------------------------------------------
// Check if a visual is direct
// --------------------------------------------------------------------------

int COpenGLXWindow::CheckDirect( void )
{
GLint intvalue;

intvalue = glXIsDirect( m_pdisplay, m_glxcontext );

return(intvalue);
}

// --------------------------------------------------------------------------
// Open a Window
//
// Inputs: xlo - Top Left X-coordinate
//         ylo - Top Left Y-coordinate
//         width - Width of window
//         height - Height of window
//         xvref - XVisualInfo to use
//
// Outputs: None 
//
// Results: Non-zero if frame was created, zero otherwise
//
// Effects: The X-Display is opened if possible 
// -------------------------------------------------------------------------- 

int COpenGLXWindow::OpenDisplay( void )
{
if ( m_pdisplay == NULL )
	m_pdisplay = XOpenDisplay( NULL );

if ( m_pdisplay == NULL )
	return(0);

m_windowcount++;
return(1);
}

int COpenGLXWindow::OpenWindow( int xlo, int ylo, int width, int height,
                         const XVisualInfo &xvref, int map )
{
XSetWindowAttributes xattribs;
XColor color,exact;
int white, black;

OpenDisplay();

m_colormap = XCreateColormap( m_pdisplay, RootWindow( m_pdisplay, 0 ),
			xvref.visual, AllocNone );

XAllocNamedColor( m_pdisplay, m_colormap, "black", &color, &exact );
black = color.pixel;

XAllocNamedColor( m_pdisplay, m_colormap, "white", &color, &exact );
white = color.pixel;

xattribs.background_pixel = white;
xattribs.border_pixel     = black;
xattribs.colormap         = m_colormap;

m_window = XCreateWindow( m_pdisplay, RootWindow( m_pdisplay, 0 ),
           xlo, ylo, width, height, 0, 
	   xvref.depth,
	   InputOutput,
           xvref.visual,
	   CWBackPixel | CWBorderPixel | CWColormap, &xattribs );

if ( m_window )
	{
	m_glxcontext = glXCreateContext( m_pdisplay, (XVisualInfo *) &xvref, NULL, True );

	if ( m_glxcontext )
		{
//		glXMakeCurrent( m_pdisplay, m_window, m_glxcontext);

		if ( map )
			{
			XMapWindow( m_pdisplay, m_window );
			m_mapped = 1;
			}
		return(1);
		}
	else
		{
		XDestroyWindow(m_pdisplay, m_window );
		XFreeColormap( m_pdisplay, m_colormap );

		m_window = 0;
		m_colormap = 0;
		}
	}
 
return(0);
}

// --------------------------------------------------------------------------
// Close a Window
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: The window is closed
// --------------------------------------------------------------------------
                                                                                
void COpenGLXWindow::CloseWindow( void )
{
if ( !m_pdisplay )
	return;

glXMakeCurrent( m_pdisplay, None, NULL );

if ( !m_window )
	return;

if ( m_mapped )
	{
	XUnmapWindow( m_pdisplay, m_window );
	m_mapped = 0;
	}

glXDestroyContext( m_pdisplay, m_glxcontext );
m_glxcontext = NULL;

XDestroyWindow( m_pdisplay, m_window );
m_window = 0;

CloseDisplay();
}

void COpenGLXWindow::CloseDisplay( void )
{ 
m_windowcount--;

if ( m_windowcount > 0 )
	return;

XCloseDisplay( m_pdisplay );

m_pdisplay = NULL;
}

// --------------------------------------------------------------------------
// Activate the current frame
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: The window is activated
// --------------------------------------------------------------------------

int COpenGLXWindow::ActivateWindow( void )
{
if ( (m_pdisplay == NULL ) ||
	(m_window == 0 ) ||
	(m_glxcontext == NULL ) )
	return(0);

if ( glXMakeCurrent( m_pdisplay, m_window, m_glxcontext ) == True)
	return(1);

return(0);
}

// --------------------------------------------------------------------------
// Deactivate the current frame
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The window is deactivated
// --------------------------------------------------------------------------

void COpenGLXWindow::DeactivateWindow( void )
{
if ( !m_pdisplay )
	{
	return;
	}

glXMakeCurrent( m_pdisplay, None, NULL );
}

// --------------------------------------------------------------------------
// Get the selected OpenGL extension string
//
// Inputs:  None
//
// Outputs: None
//
// Results: The selected OpenGL string
//
// Effects: None
// --------------------------------------------------------------------------

void COpenGLXWindow::GetExtensionString( int mode, char *pbuffer )
{
char *pextstring;

switch( mode )
	{
	case EXTENSION_GL:
		pextstring = (char *) 
			glGetString( GL_EXTENSIONS );
		break;

	case EXTENSION_GLX:
		pextstring = (char *) 
			glXQueryExtensionsString( m_pdisplay,0);
		break;

	case EXTENSION_GLXCLIENT:
		pextstring = (char *) 
			glXGetClientString( m_pdisplay, GLX_EXTENSIONS );
		break;

	case EXTENSION_GLXSERVER:
		pextstring = (char *)
			glXQueryServerString( m_pdisplay, 0, GLX_EXTENSIONS );
		break;

	case EXTENSION_WGL:
		pextstring = NULL;
		break;

	default:
		pextstring = NULL;
		break;
	}

if ( pextstring )
	{
	strcpy( pbuffer, pextstring );
	}
else
	{
	pbuffer[0] = '\0';
	}
}
