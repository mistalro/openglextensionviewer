// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;

#define _EXTENSIONLIB_INTERNAL_

#include "extensionlib.h"
#include <vector>

// --------------------------------------------------------------------------
// Get an extension string from an existing window
// 
// Inputs:  None
//
// Outputs: None
//
// Results: Pointer to extension string
//
// Effects: None      
// --------------------------------------------------------------------------

void CPixelFormatDescriptor::GetExtensionString( int mode, char *buffer )
{
COpenGLXWindow glxwindow;

if ( glxwindow.OpenWindow( 5, 5, 10, 10,*( (XVisualInfo *) m_pvisualinfo), 0) )
	{
	if ( glxwindow.ActivateWindow() )
		{
		glxwindow.GetExtensionString( mode, buffer );
		}	
	else
		{
		*buffer = '\0';
		}

	glxwindow.CloseWindow();
	}
}

// --------------------------------------------------------------------------
// Read the pixel format attributes from the visual and GLX context
//
// Inputs: xvdata - X Visual Pointer
//
// Outputs: None
//
// Results: None
//
// Effects: None
// --------------------------------------------------------------------------

void CPixelFormatDescriptor::GetPixelFormat(const XVisualInfo &xvdata )
{
COpenGLXWindow glxwindow;
GLint intvalue;
GLint bits;

if (NULL == m_pvisualinfo)
	{
	m_pvisualinfo = new XVisualInfo;
	}

*((XVisualInfo *) m_pvisualinfo) = xvdata;

if ( glxwindow.CheckOpenGL(xvdata) )
	{	
	m_dwFlags = 0;

	glxwindow.OpenWindow( 5, 5, 10, 10, xvdata, 0 );
	glxwindow.ActivateWindow();

	m_dwFlags |= FLAG_SUPPORT_OPENGL;

	intvalue = glxwindow.CheckDirect();

	if ( intvalue == True )
		{
		m_dwFlags |= FLAG_DIRECT;
		}

	glGetIntegerv( GL_DOUBLEBUFFER, &intvalue );

	if ( intvalue == GL_TRUE )
		{
		m_dwFlags |= FLAG_DOUBLEBUFFER;
		}

	glGetIntegerv( GL_STEREO, &intvalue );

	if ( intvalue == GL_STEREO )
		{
		m_dwFlags |= FLAG_STEREO;
		}

	glGetIntegerv( GL_INDEX_MODE, &intvalue );

	if ( intvalue == GL_TRUE ) 
		{
		m_iPixelType = FLAG_INDEX;
		}
	
	if ( intvalue == GL_FALSE )
		{
		m_iPixelType = FLAG_RGBA;
		}

	glGetIntegerv( GL_ACCUM_ALPHA_BITS, &intvalue );	
	m_cAccumAlphaBits = intvalue;

	glGetIntegerv( GL_ACCUM_RED_BITS, &intvalue );
	m_cAccumRedBits = intvalue;

	glGetIntegerv( GL_ACCUM_GREEN_BITS, &intvalue );
	m_cAccumGreenBits = intvalue;

	glGetIntegerv( GL_ACCUM_BLUE_BITS, &intvalue );
	m_cAccumBlueBits = intvalue;

	m_cAccumBits = m_cAccumAlphaBits +
        	m_cAccumRedBits + m_cAccumGreenBits + m_cAccumBlueBits;

	m_cRedShift = 0;

	bits = ((XVisualInfo *) m_pvisualinfo)->red_mask;

	while ( !(bits& 0x01))
		{
		bits>>=1;
		m_cRedShift++;	
		}

	m_cGreenShift = 0;
	bits = ((XVisualInfo *) m_pvisualinfo)->green_mask;

	while ( !(bits & 0x01))
		{
		bits>>=1;
		m_cGreenShift++;
		}

	bits = ((XVisualInfo *) m_pvisualinfo)->blue_mask;

	m_cBlueShift = 0;
	while ( !(bits & 0x01) )
		{
		bits>>=1;
		m_cBlueShift++;
		}

	m_cAlphaShift = 0;

	glGetIntegerv( GL_ALPHA_BITS, &intvalue );
	m_cAlphaBits = intvalue;

	glGetIntegerv( GL_RED_BITS, &intvalue );
	m_cRedBits = intvalue;
	
	glGetIntegerv( GL_GREEN_BITS, &intvalue );
	m_cGreenBits = intvalue;

	glGetIntegerv( GL_BLUE_BITS, &intvalue );
	m_cBlueBits = intvalue;

	m_cColorBits = m_cRedBits + m_cGreenBits 
		     + m_cBlueBits + m_cAlphaBits;

	glGetIntegerv( GL_DEPTH_BITS, &intvalue );
	m_cDepthBits = intvalue;

	glGetIntegerv( GL_STENCIL_BITS, &intvalue );
	m_cStencilBits = intvalue;
	}

glxwindow.CloseWindow();
}

// --------------------------------------------------------------------------
// Get all pixel formats
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: The list is initialised with the list of pixel formats
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::GetAllFormats( 
				CCheckSystemProgressCallback &callback, int max )
{
COpenGLXWindow window;
XVisualInfo *xvdata;
int maxformats, xn;
                                                                                
Deallocate();

xvdata = window.GetVisualList( maxformats );

// Allow the user to specify how many formats to process. Sometime just one
// is enough when checking the extension lists.
if ( max > 0)
	{
	if (maxformats> max )
		{
		maxformats = max;
		}
	}	

Allocate(maxformats);

for (xn = 0; xn < maxformats; xn++)
	{
	callback.CheckSystemProgressCallback( xn, maxformats );

	m_pixelformatlist[xn].GetPixelFormat( xvdata[xn] );
    	m_pixelformatlist[xn].m_index = xn;
	}                                                                        

callback.CheckSystemProgressCallback( maxformats, maxformats );

m_maxformat = maxformats;
}
