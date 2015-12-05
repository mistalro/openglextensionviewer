// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <algorithm>
#include <vector>
#include <iostream>
#include <ios>

#define _EXTENSIONLIB_INTERNAL_
#include "extensionlib.h"

// --------------------------------------------------------------------------
// Get all display settings
// --------------------------------------------------------------------------

void CDisplaySettingsList::GetAllDisplaySettings( void )
{
int      numsizes;
XRRScreenSize *xrrs;
Display *dpy;
int index = 0;

dpy     = XOpenDisplay(NULL);
xrrs    = XRRSizes(dpy, 0, &numsizes);

clear();

for (int wn = 0; wn < numsizes; wn++) 
	{
	CDisplaySettings settings;
	short *pfreq;
	int numfreq;

	pfreq = XRRRates(dpy, 0, wn, &numfreq );

	for (int freq = 0; freq < numfreq; freq++)
		{
		settings.m_index = index++;

		settings.m_pelswidth = xrrs[freq].width;
		settings.m_pelsheight = xrrs[freq].height;
		settings.m_displayvertfreq = pfreq[freq];

		settings.m_bitsperpel = -1;

		// The horizontal freq must be width * height * vertfreq
		settings.m_displayhorizfreq = 
			settings.m_pelsheight * settings.m_displayvertfreq;
	
		if ( settings.m_bitsperpel > 0)
			{
			settings.m_displayhorizfreq *= settings.m_bitsperpel;
			};

		settings.m_displaybandwidth =
			settings.m_displayhorizfreq * settings.m_pelswidth;
	
		push_back(settings);
		}
	}
}
	
int m_displayflags;     // Display flags
int m_displayvertfreq;  // Display vertical frequency
int m_displayhorizfreq; // Display horizontal frequency
int m_displaybandwidth; // Display bandwidth


// --------------------------------------------------------------------------
// Find a selected video mode
// --------------------------------------------------------------------------
	
CDisplaySettings *CDisplaySettingsList::FindDisplaySetting( int width, int height, int depth, int freq )
{
CDisplaySettings *pptr;

for (unsigned int pn = 0; pn < size(); pn++)  
	{
	pptr = &at(pn);

	if ( ((width  == pptr->m_pelswidth)       || width  == -1) &&
	     ((height == pptr->m_pelsheight)	  || height == -1) &&
	     ((freq   == pptr->m_displayvertfreq) || freq   == -1) &&
	     ((depth  == pptr->m_bitsperpel)	  || depth  == -1) )
		{
		return pptr;
		}
	}

return NULL;
}

// --------------------------------------------------------------------------
// Sort by Index
// --------------------------------------------------------------------------

static int SortByIndex( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	return formata.m_index - formatb.m_index;
	}

static int SortByIndexReversed( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	return formatb.m_index - formata.m_index;
	}

// --------------------------------------------------------------------------
// Sort by Bits per pel
// --------------------------------------------------------------------------

static int SortByBitsPerPel( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formata.m_bitsperpel - formatb.m_bitsperpel;

	if ( !compare )
		{
		compare = formata.m_index - formatb.m_index;
		}

	return compare;
	}

static int SortByBitsPerPelReversed( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formatb.m_bitsperpel - formata.m_bitsperpel;

	if ( !compare )
		{
		compare = formatb.m_index - formata.m_index;
		}

	return compare;
	}

// --------------------------------------------------------------------------
// Sort by Display width
// --------------------------------------------------------------------------

static int SortByPelsWidth( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formata.m_pelswidth - formatb.m_pelswidth;

	if ( !compare )
		{
		compare = formata.m_index - formatb.m_index;
		}

	return compare;
	}

static int SortByPelsWidthReversed( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formatb.m_pelswidth - formata.m_pelswidth;

	if ( !compare )
		compare = formatb.m_index - formata.m_index;

	return compare;
	}

// --------------------------------------------------------------------------
// Sort by Display height
// --------------------------------------------------------------------------

static int SortByPelsHeight( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formata.m_pelsheight - formatb.m_pelsheight;

	if ( !compare )
		{
		compare = formata.m_index - formatb.m_index;
		}

	return compare;
	}

static int SortByPelsHeightReversed( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formatb.m_pelsheight - formata.m_pelsheight;

	if ( !compare )
		{
		compare = formatb.m_index - formata.m_index;
		}

	return compare;
	}

// --------------------------------------------------------------------------
// Sort by Display flags
// --------------------------------------------------------------------------

static int SortByDisplayFlags( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formata.m_displayflags - formatb.m_displayflags;

	if ( !compare ) 
		{
		compare = formata.m_index - formatb.m_index;
		}

	return compare;
	}

static int SortByDisplayFlagsReversed( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formatb.m_displayflags - formata.m_displayflags;

	if ( !compare )
		{
		compare = formatb.m_index - formata.m_index;
		}

	return compare;
	}

// --------------------------------------------------------------------------
// Sort by Display vertical frequency
// --------------------------------------------------------------------------

static int SortByDisplayVertFrequency( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formata.m_displayvertfreq - formatb.m_displayvertfreq;

	if ( !compare ) 
		{
		compare = formata.m_index - formatb.m_index;
		}

	return compare;
	}

static int SortByDisplayVertFrequencyReversed( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formatb.m_displayvertfreq - formata.m_displayvertfreq;

	if ( !compare )
		{
		compare = formatb.m_index - formata.m_index;
		}

	return compare;
	}

// --------------------------------------------------------------------------
// Sort by Display horizontal frequency
// --------------------------------------------------------------------------

static int SortByDisplayHorizFrequency( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formata.m_displayhorizfreq - formatb.m_displayhorizfreq;

	if ( !compare ) 
		{
		compare = formata.m_index - formatb.m_index;
		}

	return compare;
	}

static int SortByDisplayHorizFrequencyReversed( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formatb.m_displayhorizfreq - formata.m_displayhorizfreq;

	if ( !compare )
		{
		compare = formatb.m_index - formata.m_index;
		}

	return compare;
	}	

// --------------------------------------------------------------------------
// Sort by Display bandwidth
// --------------------------------------------------------------------------

static int SortByDisplayBandwidth( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formata.m_displaybandwidth - formatb.m_displaybandwidth;

	if ( !compare ) 
		{
		compare = formata.m_index - formatb.m_index;
		}

	return compare;
	}

static int SortByDisplayBandwidthReversed( CDisplaySettings const &formata, CDisplaySettings const &formatb )
	{
	int compare;

	compare = formatb.m_displaybandwidth - formata.m_displaybandwidth;

	if ( !compare )
		{
		compare = formatb.m_index - formata.m_index;
		}

	return compare;
	}

// --------------------------------------------------------------------------
// Sort selected range of list
// --------------------------------------------------------------------------

void CDisplaySettingsList::SetSortMode( int mode )
	{
	m_sortmode = mode;
	}

void CDisplaySettingsList::ToggleSortMode( int mode )
	{
	if ( (mode & ~LIST_SORTREVERSED) == m_sortmode )
		{
		m_sortmode ^= LIST_SORTREVERSED;
		}
	else
		{
		m_sortmode = mode;
		}
	}

void CDisplaySettingsList::SortRange( int start, int num )
	{
	switch ( m_sortmode )
		{
		case LIST_SORTINDEX:
			std::sort( begin()+start, begin()+start+num, SortByIndex );
			break;

		case LIST_SORTBITSPERPEL:
			std::sort( begin()+start, begin()+start+num, SortByBitsPerPel );
			break;

		case LIST_SORTPELSWIDTH:
			std::sort( begin()+start, begin()+start+num, SortByPelsWidth );
			break;
			
		case LIST_SORTPELSHEIGHT:
			std::sort( begin()+start, begin()+start+num, SortByPelsHeight );
			break;

		case LIST_SORTDISPLAYFLAGS:
			std::sort( begin()+start, begin()+start+num, SortByDisplayFlags );
			break;

		case LIST_SORTDISPLAYVERTFREQ:
			std::sort( begin()+start, begin()+start+num, SortByDisplayVertFrequency);
			break;

		case LIST_SORTDISPLAYHORIZFREQ:
			std::sort( begin()+start, begin()+start+num, SortByDisplayHorizFrequency );
			break;

		case LIST_SORTDISPLAYBANDWIDTH:
			std::sort( begin()+start, begin()+start+num, SortByDisplayBandwidth );
			break;

		case LIST_SORTINDEXREVERSED:
			std::sort( begin()+start, begin()+start+num, SortByIndexReversed );
			break;

		case LIST_SORTBITSPERPELREVERSED:
			std::sort( begin()+start, begin()+start+num, SortByBitsPerPelReversed );
			break;
			
		case LIST_SORTPELSWIDTHREVERSED:
			std::sort( begin()+start, begin()+start+num, SortByPelsWidthReversed );
			break;
	
		case LIST_SORTPELSHEIGHTREVERSED:
			std::sort( begin()+start, begin()+start+num, SortByPelsHeightReversed );
			break;

		case LIST_SORTDISPLAYFLAGSREVERSED:
			std::sort( begin()+start, begin()+start+num, SortByDisplayFlagsReversed );
			break;

		case LIST_SORTDISPLAYVERTFREQREVERSED:
			std::sort( begin()+start, begin()+start+num, SortByDisplayVertFrequencyReversed );
			break;

		case LIST_SORTDISPLAYHORIZFREQREVERSED:
			std::sort( begin()+start, begin()+start+num, SortByDisplayHorizFrequencyReversed );
			break;

		case LIST_SORTDISPLAYBANDWIDTHREVERSED:
			std::sort( begin()+start, begin()+start+num, SortByDisplayBandwidthReversed );
			break;

		default:
			break;
		}
	}

void CDisplaySettingsList::Sort( void )
{
SortRange( 0, size() );
}


void CDisplaySettingsList::SaveDisplaySettingsList( std::ofstream &stream )
{
char buffer[1024];

//stream.setmode( filebuf::text );

stream << "Display Settings List" << std::endl;
stream << "---------------------" << std::endl << std::endl;

stream << "No. of display settings [" << size() << "]	";
stream << "Sorted by [";

switch (m_sortmode & ~LIST_SORTREVERSED)
	{
	case LIST_SORTINDEX:
		stream << "Index";
		break;

	case LIST_SORTBITSPERPEL:
		stream << "Depth";
		break;

	case LIST_SORTPELSWIDTH:
		stream << "Width";
		break;

	case LIST_SORTPELSHEIGHT:
		stream << "Height";
		break;

	case LIST_SORTDISPLAYFLAGS:
		stream << "Flags";
		break;

	case LIST_SORTDISPLAYVERTFREQ:
		stream << "Vert Refresh";	
		break;

	case LIST_SORTDISPLAYHORIZFREQ:
		stream << "Horiz Refresh";
		break;
		
	case LIST_SORTDISPLAYBANDWIDTH:
		stream << "Bandwidth";
		break;
		
	default:
		break;
	}

stream << "]";
stream << "	Reversed ";

if ( m_sortmode & LIST_SORTREVERSED )			
	{
	stream << "[@]";
	}
else	
	{
	stream << "[ ]";
	}

stream << std::endl << std::endl;

stream << "+-------+-------+--------+--------+-----------+-----------+" << std::endl;
stream << "| Index |  BPP  | Width  | Height | Frequency | Bandwidth |" << std::endl;
stream << "+-------+-------+--------+--------+-----------+-----------+" << std::endl;

for ( unsigned int pn = 0; pn < size(); pn++ )
	{
	stream << "| ";
	
	stream.width( 5 );
	stream << at(pn).m_index << " ";

	stream << " | ";

	stream.width( 5 );
	stream << at(pn).m_bitsperpel;		// Pixel size
	stream << " | ";

	stream.width( 6 );			
	stream << at(pn).m_pelswidth;		// Display width
	stream << " | ";
		
	stream.width( 6 );
	stream << at(pn).m_pelsheight;		// Display height
	stream << " | ";

	stream.width( 8 );
	stream << std::hex; 	
//	stream.pad( '0');
	stream << at(pn).m_displayflags;
	stream << " | ";

	stream.width( 9 );
		
	if ( at(pn).m_displayvertfreq == 0 ||
		 at(pn).m_displayvertfreq == 1 )
		{
		stream << "Default";
		}
	else
		{
		sprintf( buffer, "%d", at(pn).m_displayvertfreq );
		stream << buffer;
		}
		
	stream << " | ";
		
	stream.width( 9 );
	stream << at(pn).m_displaybandwidth;

	stream << " |" << std::endl;			
	}

stream << "+-------+-------+--------+--------+-----------+-----------+" << std::endl;
}

int CDisplaySettingsList::SaveDisplaySettingsList( const char *path )
{
std::ofstream stream;

stream.open( path );

if ( stream.is_open() )
	{
	SaveDisplaySettingsList( stream );
	stream.close();

	return true;
	}

return false;
}	
	
void CDisplaySettingsList::SaveDisplaySettingsModeTable( std::ofstream &stream )
{
CDisplaySettingsList videomodelist;
CDisplaySettingsList pixelsizelist;
CDisplaySettingsList displayfreqlist;
CDisplaySettings temp, *pptr;
char buffer[128], padline[128], padspace[128], padtop[128];
static int padtable[6] = { 0, 28, 14, 9, 5 };
static char title[] = "Display Frequencies";

int newfreq, freq, len;
unsigned int padlen;

for (unsigned int pn = 0; pn < size(); pn++ )
	{
	pptr = &at(pn);
	newfreq = at(pn).m_pelswidth *
		at(pn).m_pelsheight *
	   	at(pn).m_displayvertfreq;

	if ( newfreq > m_maxfreq )
		{
		m_maxfreq = newfreq;
		}

	// Generate list of unique video resolutions

	if ( videomodelist.FindDisplaySetting( 
		 pptr->m_pelswidth, pptr->m_pelsheight, -1, -1 ) == NULL )
		{
		videomodelist.push_back( *pptr );
		}

	// Generate list of pixel sizes

	if ( pixelsizelist.FindDisplaySetting( 
		 -1, -1, pptr->m_bitsperpel, -1 ) == NULL )
		{
		pixelsizelist.push_back( *pptr );
		}

	// Generate list of display frequencies

	if ( displayfreqlist.FindDisplaySetting(
		 -1, -1, -1, pptr->m_displayvertfreq ) == NULL )
		{
		displayfreqlist.push_back( *pptr );
		}
	}

pixelsizelist.SetSortMode( LIST_SORTBITSPERPEL );
pixelsizelist.Sort();

stream << std::endl << std::endl;
stream << "Display modes" << std::endl;
stream << "-------------" << std::endl << std::endl;

stream << "Maximum bandwidth: " << m_maxfreq << " Hertz" << std::endl;

if ( displayfreqlist.size() < 5)
	{
	padlen = padtable[ displayfreqlist.size()];
	}
else
	{
	padlen = 5;
	}
		
for (unsigned int pn = 0; pn < padlen; pn++ )
	{
	padline[pn]  = '-';
	padtop[pn] = '-';
	padspace[pn] = ' ';			
	}
	 
padline[padlen]   = '+';
padline[padlen+1] = '\0';
padspace[padlen]  = '\0';
padtop[padlen]	= '-';
padtop[padlen+1] = '\0';

for (unsigned int qn = 0; qn < pixelsizelist.size(); qn++ )
	{
	stream << std::endl << std::endl;
	stream << "Pixel size: " << pixelsizelist[qn].m_bitsperpel << " bits" << std::endl;
	stream << "-------------------" << std::endl << std::endl;

	// ------ Top line

	stream << "			   +";

	for (unsigned int pn = 0; pn < displayfreqlist.size()-1; pn++ )
		{
		stream << padtop;
		}

	stream << padline;
	stream << std::endl;
  
	// ------ Display frequencies

	stream << "			   | ";
	stream.width( padlen-1);
	stream << title;
	stream.width( 0 );

	len = padlen * displayfreqlist.size() - strlen( title );

	while ( len % padlen )	
		{
		stream << " ";
		len--;
		}

	stream << " ";

	padspace[2] = ' ';

	while ( len > 0 )
		{			
		stream << padspace;
		stream << " ";
		len -= padlen;
		}

	stream << " |" << std::endl;

	// Top line for resolutions

	stream << "+--------------+";

	for (unsigned int pn = 0; pn < displayfreqlist.size(); pn++ )
		{
		stream << padline;
		}
					
	stream << std::endl;
	stream << "| Resolution   |";

	// List of frequencies

	for (unsigned int pn = 0; pn < displayfreqlist.size(); pn++ )
		{
		stream.width( padlen-1 );
	
		freq = displayfreqlist[pn].m_displayvertfreq;

		if (  freq == 0 || freq == 1 )
			{
			stream << "VGA";
			}
		else
			{
			stream << freq;

			stream.width(0);
			stream << " |";
			}

		stream << std::endl;

		// Bottom of resolutions

		stream << "+--------------+";

		for ( pn = 0; pn < displayfreqlist.size(); pn++ )
			{
			stream << padline;
			}
					
		stream << std::endl;

		// For each display resolution

		for ( pn = 0; pn < videomodelist.size(); pn++ )
			{
			int empty = TRUE;

			for (unsigned int vn = 0; vn < displayfreqlist.size(); vn++ )
				{
				if ( FindDisplaySetting( 
					videomodelist[pn].m_pelswidth,
					videomodelist[pn].m_pelsheight,
					pixelsizelist[qn].m_bitsperpel,
					displayfreqlist[vn].m_displayvertfreq ) )
					{
					empty = FALSE;
					}
				}
					
			if ( !empty )
				{
				stream.width(4);
				stream << videomodelist[pn].m_pelswidth;
				stream << " x ";
				stream.width(4);
				stream << videomodelist[pn].m_pelsheight;

				stream << "|";
				stream.width(13);

				stream << buffer;	
				stream.width(0);

				stream << " |";

				for (unsigned int vn = 0; vn < displayfreqlist.size(); vn++ )
					{
					pptr = FindDisplaySetting( 
						videomodelist[pn].m_pelswidth,
						videomodelist[pn].m_pelsheight,
						pixelsizelist[qn].m_bitsperpel,
						displayfreqlist[vn].m_displayvertfreq );
						
					newfreq =
						videomodelist[pn].m_pelswidth *
						videomodelist[pn].m_pelsheight *
						displayfreqlist[vn].m_displayvertfreq;

					if ( newfreq < m_maxfreq )
						{
						padspace[2] = '?';
						}
					else
						{
						padspace[2] = ' ';
						}
						
					if ( !pptr )
						{
						stream << padspace << "|";
						}
					else
						{
						stream.width( padlen-1 );
						stream << pptr->m_index << " |";
						stream.width( 0 );
						}
					}

				stream << std::endl;
				}

			if ( pn == videomodelist.size()-1 )
				{
				stream << "+--------------+";

				for (unsigned int vn = 0; vn < displayfreqlist.size(); vn++ )
					{
					stream << padline;
					}
					
				stream << std::endl;
				}		   
			}	
		}
	}
}

int CDisplaySettingsList::ReadConfigurationFile( const char *path )
{
std::ifstream stream;

stream.open(path);

if ( stream.is_open() )
	{
	ReadConfigurationFile( stream );
	stream.close();

	return true;	
	}

return false;
}

int CDisplaySettingsList::AddDimensions( int width, int height, int depth )
{
CDisplaySettings temp;

temp.m_index 		= size();
temp.m_bitsperpel	= depth;
temp.m_pelswidth	= width;
temp.m_pelsheight	= height;
temp.m_displayflags	=  0;
temp.m_displayvertfreq  = -1;
temp.m_displayhorizfreq = -1;
temp.m_displaybandwidth = -1;

push_back( temp );

return true;
}

void CDisplaySettingsList::ReadConfigurationFile( std::ifstream &stream)
{
char buffer[1024], *pstr;
int sectionscreen, subsectiondisplay;
int depth, xres, yres;

sectionscreen = 0;
subsectiondisplay = 0;

while ( !stream.eof() )
	{
	stream.getline(buffer,1024);

	if ( strstr( buffer, "Section \"Screen\"" ) )
		sectionscreen = 1;

	if ( sectionscreen && strstr( buffer, "EndSection" ) )
		{
		sectionscreen = 0;
		}

	if ( sectionscreen )
		{
		if ( strstr( buffer, "SubSection" ) && strstr( buffer, "Display" ) )
			subsectiondisplay = 1;

		if ( subsectiondisplay && 
			strstr( buffer, "EndSubSection" ) )
			subsectiondisplay = 0; 
		}

	if ( sectionscreen && subsectiondisplay )
		{
		pstr = strstr( buffer, "Depth" );

		if ( pstr )	
			sscanf( pstr+5, "%d", &depth );

		pstr = strstr( buffer, "Modes" );

		if ( pstr )
			{
			pstr += 5;			// Skip over "Modes"

			while ( *pstr )		// While not EOL
				{
				while ( *pstr && *pstr != '"' )	// Find first "
					{
					pstr++;
					}

				if ( *pstr == '"' )		// If " was found
					{
					pstr++;		// Skip over "

					if ( *pstr )		// If not EOL
						{				// Read Xpos and Ypos
						sscanf( pstr, "%dx%d", &xres, &yres );

						AddDimensions( xres, yres, depth );

						while ( *pstr && *pstr != '"' ) // Find closing "
							{
							pstr++;
							}

						if ( *pstr == '"' )		// Skip over closing "
							{
							pstr++;
							}
						}
					}
				}
			}
		}
	}
}
