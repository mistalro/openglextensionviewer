// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _PIXELFORMAT_H_
#define _PIXELFORMAT_H_

#include <GL/gl.h>

// --------------------------------------------------------------------------
// Window Compatibility
// --------------------------------------------------------------------------

#define FLAG_DOUBLEBUFFER   0x0001
#define FLAG_SUPPORT_OPENGL 0x0002
#define FLAG_STEREO         0x0004
#define FLAG_DIRECT         0x0008

#define FLAG_RGBA           0x0001
#define FLAG_INDEX          0x0002

#define FLAG_MAINPLANE      0x0001
#define FLAG_OVERLAYPLANE   0x0002
#define FLAG_UNDERLAYPLANE  0x0003

// --------------------------------------------------------------------------
// Definition of the pixel format class
// --------------------------------------------------------------------------

class CPixelFormatDescriptor
{
public:
GLint   m_index;              // Index of pixel format

GLint  m_dwFlags;
GLint  m_iPixelType;         // RGBA or Index
GLint  m_cColorBits;         // Pixel size RGB/Index

GLint  m_cAccumRedBits;      // Accumulation buffer red bits
GLint  m_cAccumGreenBits;    // Accumulation buffer green bits
GLint  m_cAccumBlueBits;     // Accumulation buffer blue bits
GLint  m_cAccumAlphaBits;    // Accumulation buffer alpha bits

GLint  m_cRedBits;           // Red component size
GLint  m_cRedShift;          // Red component shift
GLint  m_cGreenBits;         // Green component size
GLint  m_cGreenShift;        // Green component shift
GLint  m_cBlueBits;          // Blue component size
GLint  m_cBlueShift;         // Blue component shift
GLint  m_cAlphaBits;         // Alpha component size
GLint  m_cAlphaShift;        // Alpha component shift
GLint  m_cAccumBits;         // Accumulation buffer size

GLint  m_cDepthBits;         // Depth bits
GLint  m_cStencilBits;       // Stencil bits

void *m_pvisualinfo;		// Pointers

// ----- Constructor and Destructor -----------------------------------------

CPixelFormatDescriptor( void )
    { 
    Init();
    };

~CPixelFormatDescriptor( void ) { };

// ----- Function prototypes ------------------------------------------------

void Init( void )
	{
	m_pvisualinfo = NULL;
	};

void Deallocate( void )
	{

	};

void Duplicate( CPixelFormatDescriptor &format )
	{
	*this = format;
	};

void Display( void )
	{

	};

int SortCompare( CPixelFormatDescriptor &format )
	{
	return( m_index - format.m_index );
	};

int operator < ( CPixelFormatDescriptor &format )
	{
	return( m_index < format.m_index );
	};

int operator > ( CPixelFormatDescriptor &format )
	{
	return( m_index > format.m_index );
	};

void GetPixelFormat( const XVisualInfo &xvptr );

void GetExtensionString( int mode, char *pbuffer );

int MatchColorBits( int maxbits, int colorbits, int curcolorbits )
	{
	return (colorbits == maxbits) &&
		(m_cColorBits >= curcolorbits ) &&
		(m_cColorBits == colorbits );
	}

int MatchDepthBits( int maxbits, int depthbits, int curdepthbits )
	{
	return (depthbits == maxbits) &&
		(m_cDepthBits >= curdepthbits ) &&
		(m_cDepthBits == depthbits );
	}

int MatchAccumBits( int maxbits, int accumbits, int curaccumbits )
	{
	return (accumbits == maxbits) &&
		(m_cAccumBits >= curaccumbits) &&
		(m_cAccumBits == accumbits );
	}

int MatchStencilBits( int maxbits, int stencilbits, int curstencilbits)
	{
	return (stencilbits == maxbits) &&
		(m_cStencilBits >= curstencilbits) &&
		(m_cStencilBits == stencilbits);
	}
};

#endif	// _PIXELFORMAT_H_
