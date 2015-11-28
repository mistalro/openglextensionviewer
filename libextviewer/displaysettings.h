// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _DISPLAYSETTINGS_
#define _DISPLAYSETTINGS_

// --------------------------------------------------------------------------
// The EnumDisplaySettings function sets values for the following five DEVMODE 
// members: 
// 
// dmBitsPerPel 
// dmPelsWidth 
// dmPelsHeight 
// dmDisplayFlags 
// dmDisplayFrequency 
// --------------------------------------------------------------------------

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define LIST_SORTREVERSED         0x8000
#define LIST_SORTINDEX            0x0001
#define LIST_SORTBITSPERPEL       0x0002
#define LIST_SORTPELSWIDTH        0x0004
#define LIST_SORTPELSHEIGHT       0x0008
#define LIST_SORTDISPLAYFLAGS     0x0010
#define LIST_SORTDISPLAYVERTFREQ  0x0020
#define LIST_SORTDISPLAYHORIZFREQ 0x0040
#define LIST_SORTDISPLAYBANDWIDTH 0x0080

#define LIST_SORTINDEXREVERSED            (LIST_SORTINDEX|LIST_SORTREVERSED)
#define LIST_SORTBITSPERPELREVERSED       (LIST_SORTBITSPERPEL|LIST_SORTREVERSED)
#define LIST_SORTPELSWIDTHREVERSED        (LIST_SORTPELSWIDTH|LIST_SORTREVERSED)
#define LIST_SORTPELSHEIGHTREVERSED       (LIST_SORTPELSHEIGHT|LIST_SORTREVERSED)
#define LIST_SORTDISPLAYFLAGSREVERSED     (LIST_SORTDISPLAYFLAGS|LIST_SORTREVERSED)
#define LIST_SORTDISPLAYVERTFREQREVERSED  (LIST_SORTDISPLAYVERTFREQ|LIST_SORTREVERSED)
#define LIST_SORTDISPLAYHORIZFREQREVERSED (LIST_SORTDISPLAYHORIZFREQ|LIST_SORTREVERSED)
#define LIST_SORTDISPLAYBANDWIDTHREVERSED (LIST_SORTDISPLAYBANDWIDTH|LIST_SORTREVERSED)

// --------------------------------------------------------------------------
// Class used to represent a single display mode
// --------------------------------------------------------------------------

class CDisplaySettings
{
public:
int m_index;            // Index of mode
int m_bitsperpel;       // Bits per pixel
int m_pelswidth;        // Width of display
int m_pelsheight;       // Height of display
int m_displayflags;     // Display flags
int m_displayvertfreq;  // Display vertical frequency
int m_displayhorizfreq; // Display horizontal frequency
int m_displaybandwidth; // Display bandwidth

// ----- Constructor and destructor -----------------------------------------

CDisplaySettings() { };
~CDisplaySettings() { };

// ----- Function prototypes ------------------------------------------------

void Init( void)
	{
	m_index = 0;
	m_bitsperpel = 0;
	m_pelswidth = 0;
	m_pelsheight = 0;
	m_displayflags = 0;
	m_displayvertfreq = 0;
	m_displayhorizfreq = 0;
	m_displaybandwidth = 0;
	};

void Duplicate( CDisplaySettings &settings ) 
	{ 
	*this = settings;
	};

void Deallocate( void ) 
	{ 
	};

int SortCompare( CDisplaySettings &settings )
	{
	return( m_index - settings.m_index );
	};

int operator < ( const CDisplaySettings &display )
	{
	return( m_index < display.m_index );
	};

int operator > ( const CDisplaySettings &display )
	{
	return( m_index > display.m_index );
	};
};

// --------------------------------------------------------------------------
// Class used to represent a list of display modes
// --------------------------------------------------------------------------

class CDisplaySettingsList : public vector <CDisplaySettings>
{
public:
int     m_sortmode;   // Sort mode for list
int     m_maxfreq;    // Maximum frequency

// ----- Constructor and destructor -----------------------------------------

CDisplaySettingsList( void ) 
	{ 
	Init(); 
	};

~CDisplaySettingsList( void ) 
	{ 
	Deallocate(); 
	};

// ----- Functions and Procedures -------------------------------------------

void Init( void )
    	{
    	m_sortmode = LIST_SORTBITSPERPEL;
    	m_maxfreq  = 0;
    	}

void Deallocate( void )
	{
	}

void GetAllDisplaySettings( void );

CDisplaySettings *FindDisplaySetting( int width, int height, int depth, int freq );

void SetSortMode( int mode );
void ToggleSortMode( int mode );
void SortRange( int start, int num );  
void Sort( void );

inline int  GetReverseMode( void ) 
	{
	return ((m_sortmode & LIST_SORTREVERSED) == LIST_SORTREVERSED); 
	};

inline int  GetCount( void ) 
	{
	return size(); 
	};

CDisplaySettings & GetListItem( int pos ) 
	{ 
	return( at(pos) ); 
	};

void SaveDisplaySettingsList( ofstream &stream );
int  SaveDisplaySettingsList( const char *path );
void SaveDisplaySettingsModeTable( ofstream &stream );

int  ReadConfigurationFile( const char *path );
void ReadConfigurationFile( ifstream &stream);

int AddDimensions( int width, int height, int depth );
};

#endif // _DISPLAYSETTINGS_

