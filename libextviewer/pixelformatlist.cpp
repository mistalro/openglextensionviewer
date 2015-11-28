// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;                                                                                 
#define _EXTENSIONLIB_INTERNAL_

#include "extensionlib.h"

// --------------------------------------------------------------------------
// Select a visual
// --------------------------------------------------------------------------
                                                                                
int CPixelFormatDescriptorList::SelectVisual( int colorbits, int depthbits,
        int accumbits, int stencilbits, int flags, int xclass, XVisualInfo &xvinfo )
{
int pn, best, curcolorbits, curdepthbits, curaccumbits, curstencilbits;
CPixelFormatDescriptor *pfd;
//CPixelFormatDescriptor *pfd;                                                                                
best = -1;
curcolorbits = 0;       // Clear bits
curdepthbits = 0;
curaccumbits = 0;
curstencilbits = 0;

for ( pn = 0, pfd = m_pixelformatlist; pn < m_maxformat; pfd++, pn++ )
	{
        if ( ((pfd->m_dwFlags & flags) == flags) &&// Check flags?
	     (((XVisualInfo *)pfd->m_pvisualinfo)->c_class == xclass))
                {
                // Check color bits?
		if ( pfd->MatchColorBits( MAXBITS, colorbits, curcolorbits) &&
    			// Check depth bits?
		     pfd->MatchDepthBits( MAXBITS, depthbits, curdepthbits) &&
  			// Check accum bits?
		     pfd->MatchAccumBits( MAXBITS, accumbits, curaccumbits) &&
      			// Check stencil bits?
		     pfd->MatchStencilBits(MAXBITS, stencilbits, curstencilbits ))	
                        {
                        best = pn;
                        curcolorbits   = pfd->m_cColorBits;
                        curdepthbits   = pfd->m_cDepthBits;
                        curaccumbits   = pfd->m_cAccumBits;
                        curstencilbits = pfd->m_cStencilBits;
                        }
                }
	}

if ( best != -1 )               // Found a visual?
        {
        xvinfo = *((XVisualInfo *) m_pixelformatlist[best].m_pvisualinfo); // Yes, so copy it
        return(1);              // Return success
        }
                                                                                
return(0);                      // Return failure
}

// --------------------------------------------------------------------------
// Sort by Flags
// --------------------------------------------------------------------------
                                                                                
int SortByFlags( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_dwFlags - formatb.m_dwFlags;
                                                                                
if ( !compare )
	{
        compare = formata.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
int SortByFlagsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formatb.m_dwFlags - formata.m_dwFlags;
                                                                                
if ( !compare )
	{
        compare = formatb.m_index - formata.m_index;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Index
// --------------------------------------------------------------------------
                                                                                
int SortByIndex( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
return( formata.m_index - formatb.m_index );
}
                                                                                
int SortByIndexReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
return( formatb.m_index - formata.m_index );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Pixel Type
// --------------------------------------------------------------------------
                                                                                
int SortByPixelType( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_iPixelType - formatb.m_iPixelType;
                                                                                
if ( !compare )
	{	
	compare = formata.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
int SortByPixelTypeReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formatb.m_iPixelType - formata.m_iPixelType;
                                                                                
if ( !compare )
	{
	compare = formatb.m_index - formata.m_index;
	}
                                                                                
return( compare );
}

// --------------------------------------------------------------------------
// Sort by Color Bits
// --------------------------------------------------------------------------
                                                                                
int SortByColorBits( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_cColorBits - formatb.m_cColorBits;
                                                                                
if ( !compare )
	{
	compare = formata.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
int SortByColorBitsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formatb.m_cColorBits - formata.m_cColorBits;
                                                                                
if ( !compare )
	{
        compare = formatb.m_index - formata.m_index;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Red Bits
// --------------------------------------------------------------------------
                                                                                
int SortByRedBits( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_cRedBits - formatb.m_cRedBits;
                                                                                
if ( !compare )
	{
        compare = formata.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
int SortByRedBitsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formatb.m_cRedBits - formata.m_cRedBits;
                                                                               
if ( !compare )
	{
        compare = formatb.m_index - formata.m_index;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Green Bits
// --------------------------------------------------------------------------
                                                                                
int SortByGreenBits( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                               
compare = formata.m_cGreenBits - formatb.m_cGreenBits;

if ( !compare )
	{
        compare = formatb.m_cGreenBits - formata.m_cGreenBits;
	}
                                                                              
return( compare );
}
                                                                                
int SortByGreenBitsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_cGreenBits - formatb.m_cGreenBits;
                                                                               
if ( !compare )
	{
        compare = formatb.m_cGreenBits - formata.m_cGreenBits;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Blue Bits
// --------------------------------------------------------------------------
                                                                                
int SortByBlueBits( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_cBlueBits - formatb.m_cBlueBits;
                                                                                
if ( !compare )
	{
        compare = formata.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
int SortByBlueBitsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formatb.m_cBlueBits - formata.m_cBlueBits;
                                                                                
if ( !compare )
	{
        compare = formatb.m_index - formata.m_index;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Alpha Bits
// --------------------------------------------------------------------------
                                                                                
int SortByAlphaBits( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_cAlphaBits - formatb.m_cAlphaBits;
                                                                                
if ( !compare )
	{
        compare = formata.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
int SortByAlphaBitsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formatb.m_cAlphaBits - formata.m_cAlphaBits;
                                                                                
if ( !compare )
	{
        compare = formatb.m_index - formata.m_index;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Accumulation Bits
// --------------------------------------------------------------------------
                                                                                
int SortByAccumBits( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_cAccumBits - formatb.m_cAccumBits;
                                                                                
if ( !compare )
	{
        compare = formata.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
int SortByAccumBitsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formatb.m_index - formata.m_index;
                                                                                
if ( !compare )
	{
        compare = formatb.m_index - formata.m_index;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Accumulation Bits Red
// --------------------------------------------------------------------------
                                                                                
int SortByAccumRedBits( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_cAccumRedBits - formatb.m_cAccumRedBits;
                                                                                
if ( !compare )
	{
        compare = formata.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
int SortByAccumRedBitsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formatb.m_cAccumRedBits - formata.m_cAccumRedBits;
                                                                                
if ( !compare )
	{
        compare = formatb.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Accumulation Bits Green
// --------------------------------------------------------------------------
                                                                                
int SortByAccumGreenBits( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_cAccumGreenBits - formatb.m_cAccumGreenBits;
                                                                                
if ( !compare )
	{
        compare = formata.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
int SortByAccumGreenBitsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formatb.m_cAccumGreenBits - formata.m_cAccumGreenBits;
                                                                                
if ( !compare )
	{
        compare = formatb.m_index - formata.m_index;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Accumulation Bits Blue
// --------------------------------------------------------------------------
                                                                                
int SortByAccumBlueBits( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_cAccumBlueBits - formatb.m_cAccumBlueBits;
                                                                                
if ( !compare )
	{
        compare = formatb.m_index - formata.m_index;
	}

return( compare );
}
                                                                                
int SortByAccumBlueBitsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )    
{
int compare;
                                                                                
compare = formatb.m_cAccumBlueBits - formata.m_cAccumBlueBits;
                                                                                
if ( !compare )
	{
	compare = formatb.m_index - formata.m_index;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Accumulation Bits Alpha
// --------------------------------------------------------------------------
                                                                                
int SortByAccumAlphaBits( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;

compare = formata.m_cAccumAlphaBits - formatb.m_cAccumAlphaBits;
                                                                               
if ( !compare )
	{
        compare = formata.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
int SortByAccumAlphaBitsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formatb.m_cAccumAlphaBits - formata.m_cAccumAlphaBits;
                                                                                
if ( !compare )
	{
        compare = formatb.m_index - formata.m_index;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Depth Bits
// --------------------------------------------------------------------------
                                                                                
int SortByDepthBits( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_cDepthBits - formatb.m_cDepthBits;
                                                                                
if ( !compare )
	{
        compare = formata.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
int SortByDepthBitsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formatb.m_cDepthBits - formata.m_cDepthBits;
                                                                                
if ( !compare )
	{
        compare = formatb.m_index - formata.m_index;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort by Stencil Bits
// --------------------------------------------------------------------------
                                                                                
int SortByStencilBits( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formata.m_cStencilBits - formatb.m_cStencilBits;
                                                                                
if ( !compare )
	{
        compare = formata.m_index - formatb.m_index;
	}
                                                                                
return( compare );
}
                                                                                
int SortByStencilBitsReversed( CPixelFormatDescriptor const &formata, CPixelFormatDescriptor const &formatb )
{
int compare;
                                                                                
compare = formatb.m_cStencilBits - formata.m_cStencilBits;
                                                                                
if ( !compare )
	{
        compare = formatb.m_index - formata.m_index;
	}
                                                                                
return( compare );
}
                                                                                
// --------------------------------------------------------------------------
// Sort selected range of list
//
// Inputs:  mode - Which mode to use
//
// Outputs: None
//
// Results: None
//
// Effects: The sort mode is set
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SetSortMode( int mode )
{
m_sortmode = mode;
}

// --------------------------------------------------------------------------
// Toggle the sorting mode
//
// Inputs: mode - The new mode
//
// Outputs: None
//
// Results: None
//
// Effects: If the new sort mode is the same as the existing sort mode
//          the sort order is reversed. Otherwise the sort mode is
//          set to the new mode
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::ToggleSortMode( int mode )
{
if ( (mode & ~LIST_SORTREVERSED) == m_sortmode )  // Same sort mode?
	{
        m_sortmode ^= LIST_SORTREVERSED;	  // Toggle mode
	}
else
	{
        m_sortmode = mode;			// Just set new mode
	}
}

// ---------------------------------------------------------------------------
// Toggle the ascending/descending mode of the sort specification
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: 
// ---------------------------------------------------------------------------

int CPixelFormatDescriptorList::ToggleReverseMode( void )
{
m_sortmode ^= LIST_SORTREVERSED;
	
return( m_sortmode );
}
	
// ---------------------------------------------------------------------------
// Sort the selected range of items by the current sort mode
//
// Inputs: start - Where to start
//         num   - Number of items
//
// Outputs: None
//
// Results: None
//
// Effects: The selected range of the list is sorted
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SortRange( int start, int num )
{
switch ( m_sortmode )
	{
        case LIST_SORTINDEX:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByIndex);
		break;

	case LIST_SORTINDEXREVERSED:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByIndexReversed );
		break;

        case LIST_SORTPIXELTYPE:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByPixelType );
		break;

        case LIST_SORTPIXELTYPEREVERSED:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByPixelTypeReversed );
		break;

        case LIST_SORTCOLORBITS:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByColorBits );
		break;

        case LIST_SORTCOLORBITSREVERSED:
            	std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByColorBitsReversed );
		break;

        case LIST_SORTCOLORREDBITS:
            	std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByRedBits );
		break;

        case LIST_SORTCOLORREDBITSREVERSED:
          	std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByRedBitsReversed );
		break;

        case LIST_SORTCOLORGREENBITS:
            	std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByGreenBits );
		break;

        case LIST_SORTCOLORGREENBITSREVERSED:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByGreenBitsReversed );
            	break;

        case LIST_SORTCOLORBLUEBITS:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByBlueBits );
            	break;

        case LIST_SORTCOLORBLUEBITSREVERSED:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByBlueBitsReversed);
            	break;

        case LIST_SORTCOLORALPHABITS:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByAlphaBits );
            	break;

        case LIST_SORTCOLORALPHABITSREVERSED:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByAlphaBitsReversed);
            	break;

        case LIST_SORTACCUMBITS:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByAccumBits);
            	break;

        case LIST_SORTACCUMBITSREVERSED:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByAccumBitsReversed);
            	break;

        case LIST_SORTACCUMREDBITS:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByAccumRedBits);
            	break;

        case LIST_SORTACCUMREDBITSREVERSED:
            	std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByAccumRedBitsReversed );
            	break;

        case LIST_SORTACCUMGREENBITS:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByAccumGreenBits);
            	break;

        case LIST_SORTACCUMGREENBITSREVERSED:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByAccumGreenBitsReversed);
            	break;

        case LIST_SORTACCUMBLUEBITS:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByAccumBlueBits );
            	break;

        case LIST_SORTACCUMBLUEBITSREVERSED:
            	std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByAccumBlueBitsReversed );
            	break;

        case LIST_SORTACCUMALPHABITS:
            	std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByAccumBlueBits );
            	break;

        case LIST_SORTACCUMALPHABITSREVERSED:
            	std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByAccumBlueBitsReversed );
            	break;

        case LIST_SORTDEPTHBITS:
            	std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByDepthBits );
            	break;

        case LIST_SORTDEPTHBITSREVERSED:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByDepthBitsReversed);
            	break;

        case LIST_SORTSTENCILBITS:
		std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByStencilBits);
            	break;

        case LIST_SORTSTENCILBITSREVERSED:
            	std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByStencilBitsReversed );
            	break;

        case LIST_SORTFLAGS:
            	std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByFlags );
            break;

        case LIST_SORTFLAGSREVERSED:
            	std::sort( m_pixelformatlist+start, m_pixelformatlist+start+num, SortByFlagsReversed );
            break;

        default:
            break;
        }
}

// --------------------------------------------------------------------------
// Reorder the list
// 
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The list is reordered
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::Sort( void )
{
SortRange( 0, m_maxformat );
}

// --------------------------------------------------------------------------
// Save the pixel format list count to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatListCount( ostream &stream)
{
stream << "No. of pixel formats [" << m_maxformat << "]    ";
}

// --------------------------------------------------------------------------
// Save the pixel format list sorting mode to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatListSortMode( ostream &stream)
{
stream << "Sorted by [";

switch ( m_sortmode & ~LIST_SORTREVERSED )
        {
        case LIST_SORTINDEX:
                stream << "Index";
                break;

        case LIST_SORTPIXELTYPE:
                stream << "Pixel type";
                break;

        case LIST_SORTCOLORBITS:
                stream << "Color bits";
                break;

        case LIST_SORTCOLORREDBITS:
                stream << "Red bits/shift";
                break;

        case LIST_SORTCOLORGREENBITS:
                stream << "Green bits/shift";
                break;

        case LIST_SORTCOLORBLUEBITS:
                stream << "Blue bits/shift";
                break;

        case LIST_SORTCOLORALPHABITS:
                stream << "Alpha bits/shift";
                break;

        case LIST_SORTACCUMBITS:
                stream << "Accumulation bits";
                break;

        case LIST_SORTDEPTHBITS:
                stream << "Depth bits";
                break;

        case LIST_SORTSTENCILBITS:
                stream << "Stencil bits";
                break;

        case LIST_SORTFLAGS:
                stream << "Flags";
                break;

        default:
                break;
        }

stream << "]    Reversed ";

if ( m_sortmode & LIST_SORTREVERSED )
        {
        stream << "[@]";
        }
else
        {
        stream << "[ ]";
        }
}

// --------------------------------------------------------------------------
// Save the pixel format list horizontal border to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatListHorizBorder( ostream &stream )
{
stream << "+-------+------------+-";
stream << "-----------+----------------+------------------+----------------";
stream << "-+------------------+---------------------+------------+--------------";
stream << "+------------------------------------------------------------------------------+";
stream << endl;
}

// --------------------------------------------------------------------------
// Save the pixel format list horizontal title to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatListHorizTitle( ostream &stream )
{
stream << "| Index | Pixel type | ";
stream << "Color bits | Red bits/shift | Green bits/shift | Blue bits/shift";
stream << " | Alpha bits/shift | Accumulation bits   | Depth bits | Stencil bits ";
stream << "| Flags                                                                        |";
stream << endl;
}

// --------------------------------------------------------------------------
// Save the pixel format list index to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatListIndex( ostream &stream, CPixelFormatDescriptor *pdesc)
{
stream << "| ";
stream.width( 4 );
stream << pdesc->m_index+1;
}

// --------------------------------------------------------------------------
// Save the pixel format list type to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatListType( ostream &stream, CPixelFormatDescriptor *pdesc)
{
// ----- Pixel format type -----
stream << "  | ";
stream.width( 7 );

if ( pdesc->m_iPixelType == FLAG_RGBA )
	{
	stream << "RGBA ";
	}
else
	if ( pdesc->m_iPixelType == FLAG_INDEX )
		{
		stream << "INDEX";
		}
	else
                {
                stream << "unknown";
                }
}

// --------------------------------------------------------------------------
// Save the pixel format list RGBA type to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatListRGBA( ostream &stream, CPixelFormatDescriptor *pdesc)
{
// ----- Red/Green/Blue/Alpha bits -----
stream << "    | ";
stream.width( 10 );
stream << (int) pdesc->m_cColorBits;

stream << " | ";
stream.width( 11 );
stream << (int) pdesc->m_cRedBits << "/" << (int) pdesc->m_cRedShift;

stream << " | ";
stream.width( 14 );
stream << (int) pdesc->m_cGreenBits << "/" << (int) pdesc->m_cGreenShift;

stream << " | ";
stream.width( 13 );
stream << (int) pdesc->m_cBlueBits << "/" << (int) pdesc->m_cBlueShift;

stream << " | ";
stream.width( 14 );
stream << (int) pdesc->m_cAlphaBits << "/" << (int) pdesc->m_cAlphaShift;
}

// --------------------------------------------------------------------------
// Save the pixel format list accumulator type to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatListAccum( ostream &stream, CPixelFormatDescriptor *pdesc)
{
stream << " | ";
stream.width( 3 );
stream << (int) pdesc->m_cAccumBits << ", (";
stream.width( 2 );
stream << (int) pdesc->m_cAccumRedBits << ",";
stream.width( 2 );
stream << (int) pdesc->m_cAccumGreenBits << ",";
stream.width( 2 );
stream << (int) pdesc->m_cAccumBlueBits << ",";
stream.width( 2 );
stream << (int) pdesc->m_cAccumAlphaBits << " )";
}

// --------------------------------------------------------------------------
// Save the pixel format list depth bits to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatListDepth( ostream &stream, CPixelFormatDescriptor *pdesc)
{
stream << " | ";
stream.width( 10 );
stream << (int) pdesc->m_cDepthBits;
}

// --------------------------------------------------------------------------
// Save the pixel format list stencil bits to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatListStencil( ostream &stream, CPixelFormatDescriptor *pdesc)
{
stream << " | ";
stream.width( 12 );
stream << (int) pdesc->m_cStencilBits;
}

// --------------------------------------------------------------------------
// Save the pixel format list Linux flags to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatListLinux( ostream &stream, CPixelFormatDescriptor *pdesc)
{
string buffer;
XVisualInfo *pvisual = (XVisualInfo *) pdesc->m_pvisualinfo;
stream << " | ";
stream.width( 76 );
buffer[0] = 0;

switch ( pvisual->c_class )
	{
	case StaticGray:
		buffer += "StaticGray  ";
		break;

	case GrayScale:
		buffer += "GrayScale   ";
		break;

	case StaticColor:
		buffer += "StaticColor ";
		break;

	case PseudoColor:
		buffer += "PseudoColor ";
		break;

	case TrueColor:
		buffer += "TrueColor   ";
		break;

	case DirectColor:
		buffer += "DirectColor ";
		break;

	default:
		break;
	}

if ( pdesc->m_dwFlags & FLAG_DIRECT )
	{
	buffer += "Direct ";
	}

if ( pdesc->m_dwFlags & FLAG_SUPPORT_OPENGL )
	{
	buffer += "Support_OpenGL ";
	}

if ( pdesc->m_dwFlags & FLAG_DOUBLEBUFFER )
	{
	buffer += "DoubleBuffer ";
	}

if ( pdesc->m_dwFlags & FLAG_STEREO )
	{
	buffer += "Stereo ";
	} 

stream << buffer;
}

// --------------------------------------------------------------------------
// Save the pixel format list end-of-line to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatListEndLine( ostream &stream, CPixelFormatDescriptor *pdesc)
{
stream << " |";
stream << endl;
}

// --------------------------------------------------------------------------
// Save the pixel format list end-of-line to an open stream
// --------------------------------------------------------------------------

void CPixelFormatDescriptorList::SavePixelFormatList( ostream &stream )
{
int pn;

stream << "Pixel Format List" << endl;
stream << "-----------------" << endl << endl;

SavePixelFormatListCount(stream);
SavePixelFormatListSortMode( stream);

stream << endl << endl;

SavePixelFormatListHorizBorder( stream );
SavePixelFormatListHorizTitle( stream );
SavePixelFormatListHorizBorder( stream );

stream.flags( ios::left );

for ( pn = 0; pn < m_maxformat; pn++)
	{
	CPixelFormatDescriptor *pdesc = m_pixelformatlist+pn;

	SavePixelFormatListIndex( stream, pdesc );
	SavePixelFormatListType( stream, pdesc );
	SavePixelFormatListRGBA( stream, pdesc );
	SavePixelFormatListAccum( stream, pdesc );
	SavePixelFormatListDepth( stream, pdesc );
	SavePixelFormatListStencil( stream, pdesc );

	SavePixelFormatListLinux( stream, pdesc);

	SavePixelFormatListEndLine( stream, pdesc);
        };

SavePixelFormatListHorizBorder( stream );
}
 
// ----------------------------------------------------------------------------
// Save the pixel format to the selected file path
// ----------------------------------------------------------------------------

int CPixelFormatDescriptorList::SavePixelFormatList( const string &path )
{
ofstream outbuf;

outbuf.open( path.data(), ios::out );

if ( !outbuf.is_open() )
	{
    	return(0);
	}

SavePixelFormatList( outbuf );

outbuf.close();
return(1);
}
