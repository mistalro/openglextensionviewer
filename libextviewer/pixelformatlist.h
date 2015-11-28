// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _PIXELFORMATLIST_
#define _PIXELFORMATLIST_

#include <iostream>
#include <algorithm>
#include <vector>

#define MAXBITS 0xFFFF

// --------------------------------------------------------------------------
// Flags for sorting the pixel format list
// --------------------------------------------------------------------------

#define LIST_SORTREVERSED        0x8000
#define LIST_SORTINDEX           0x0001
#define LIST_SORTPIXELTYPE       0x0002
#define LIST_SORTCOLORBITS       0x0003
#define LIST_SORTCOLORREDBITS    0x0004
#define LIST_SORTCOLORGREENBITS  0x0005
#define LIST_SORTCOLORBLUEBITS   0x0006
#define LIST_SORTCOLORALPHABITS  0x0007
#define LIST_SORTACCUMBITS       0x0008
#define LIST_SORTACCUMREDBITS    0x0009
#define LIST_SORTACCUMGREENBITS  0x000A
#define LIST_SORTACCUMBLUEBITS   0x000B
#define LIST_SORTACCUMALPHABITS  0x000C
#define LIST_SORTDEPTHBITS       0x000D
#define LIST_SORTSTENCILBITS     0x000E
#define LIST_SORTFLAGS           0x000F

#define LIST_SORTINDEXREVERSED           (LIST_SORTINDEX|LIST_SORTREVERSED)
#define LIST_SORTPIXELTYPEREVERSED       (LIST_SORTPIXELTYPE|LIST_SORTREVERSED)       
#define LIST_SORTCOLORBITSREVERSED       (LIST_SORTCOLORBITS|LIST_SORTREVERSED)        
#define LIST_SORTCOLORREDBITSREVERSED    (LIST_SORTCOLORREDBITS|LIST_SORTREVERSED)     
#define LIST_SORTCOLORGREENBITSREVERSED  (LIST_SORTCOLORGREENBITS|LIST_SORTREVERSED)   
#define LIST_SORTCOLORBLUEBITSREVERSED   (LIST_SORTCOLORBLUEBITS|LIST_SORTREVERSED)    
#define LIST_SORTCOLORALPHABITSREVERSED  (LIST_SORTCOLORALPHABITS|LIST_SORTREVERSED)   
#define LIST_SORTACCUMBITSREVERSED       (LIST_SORTACCUMBITS|LIST_SORTREVERSED)        
#define LIST_SORTACCUMREDBITSREVERSED    (LIST_SORTACCUMREDBITS|LIST_SORTREVERSED)     
#define LIST_SORTACCUMGREENBITSREVERSED  (LIST_SORTACCUMGREENBITS|LIST_SORTREVERSED)   
#define LIST_SORTACCUMBLUEBITSREVERSED   (LIST_SORTACCUMBLUEBITS|LIST_SORTREVERSED)    
#define LIST_SORTACCUMALPHABITSREVERSED  (LIST_SORTACCUMALPHABITS|LIST_SORTREVERSED)   
#define LIST_SORTDEPTHBITSREVERSED       (LIST_SORTDEPTHBITS|LIST_SORTREVERSED)        
#define LIST_SORTSTENCILBITSREVERSED     (LIST_SORTSTENCILBITS|LIST_SORTREVERSED)      
#define LIST_SORTFLAGSREVERSED           (LIST_SORTFLAGS|LIST_SORTREVERSED)

// --------------------------------------------------------------------------
// Definition of the CPixelFormatDescriptorList class
// --------------------------------------------------------------------------

class CPixelFormatDescriptorList 
{
public:
CPixelFormatDescriptor *m_pixelformatlist;
int 			m_maxformat;
int                     m_sortmode;   // Sort mode
int                     m_pfdsize;

// ----- Constructor and destructor  ----------------------------------------

CPixelFormatDescriptorList() 
	{ 
	Init(); 
	};

~CPixelFormatDescriptorList() { Deallocate(); };

// ----- Functions and procedures -------------------------------------------

void Init( void )
	{
	m_sortmode = LIST_SORTINDEX;
	m_maxformat = 0;
	m_pixelformatlist = NULL;
	m_pfdsize = sizeof(CPixelFormatDescriptor);
	}

void Deallocate( void )
	{
	if ( m_pixelformatlist != NULL)
		{
		delete [] m_pixelformatlist;
		m_pixelformatlist = NULL;	
		}
	}

void Allocate( int num )
	{
	Deallocate();

	m_pixelformatlist = new CPixelFormatDescriptor[num];
	}

// --------------------------------------------------------------------------
// Get all pixel formats
// --------------------------------------------------------------------------

void GetAllFormats( CCheckSystemProgressCallback &callback, int max );

void GetExtensionString( int index, int mode, char *pbuffer )
	{
	if ( (index >= 0) && (index <= m_maxformat) )
		{		
		m_pixelformatlist[index].GetExtensionString(mode, pbuffer);
		}
	}

int GetCount(void )
	{
	return m_maxformat;
	}

int GetCount2(void)
	{
	return m_maxformat;
	}

void SetSortMode( int mode );
void ToggleSortMode( int mode );
int  ToggleReverseMode( void );
void SortRange( int start, int num );
void Sort( void );
int  GetReverseMode( void ) { return (( m_sortmode & LIST_SORTREVERSED) == LIST_SORTREVERSED); };
const CPixelFormatDescriptor &GetListItem( int row ) { return( m_pixelformatlist[row] ); };

void SavePixelFormatListCount( ostream &stream);
void SavePixelFormatListSortMode( ostream &stream);
void SavePixelFormatListHorizBorder( ostream &stream );
void SavePixelFormatListHorizTitle( ostream &stream );
void SavePixelFormatListIndex( ostream &stream, CPixelFormatDescriptor * pdesc);
void SavePixelFormatListType( ostream &stream, CPixelFormatDescriptor *pdesc);

void SavePixelFormatListRGBA( ostream &stream, CPixelFormatDescriptor *pdesc);
void SavePixelFormatListAccum( ostream &stream, CPixelFormatDescriptor *pdesc);
void SavePixelFormatListDepth( ostream &stream, CPixelFormatDescriptor *pdesc);
void SavePixelFormatListStencil( ostream &stream, CPixelFormatDescriptor *pdesc);

void SavePixelFormatListLinux( ostream &stream, CPixelFormatDescriptor *pdesc);

void SavePixelFormatListEndLine( ostream &stream, CPixelFormatDescriptor *pdesc);

void SavePixelFormatList( ostream &stream );
void SavePixelFormatList( void ) 
	{ 
	SavePixelFormatList( cout ); 
	};

int SavePixelFormatList( const string &path );

int SelectVisual( int colorbits, int depthbits, int accumbits, 
		int stencilbits, int flags, int xclass, XVisualInfo &xvinfo );
};

#endif // _PIXELFORMATLIST_

