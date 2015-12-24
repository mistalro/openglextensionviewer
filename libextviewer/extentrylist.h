// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _EXTLIST_
#define _EXTLIST_

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define LIST_SORTNAME           0x0000
#define LIST_SORTVALUE          0x0001
#define LIST_SORTPREFIX         0x0002
#define LIST_SORTREVERSED       0x8000

#define LIST_SORTNAMEREVERSED   (LIST_SORTNAME  |LIST_SORTREVERSED)
#define LIST_SORTVALUEREVERSED  (LIST_SORTVALUE |LIST_SORTREVERSED)
#define LIST_SORTPREFIXREVERSED (LIST_SORTPREFIX|LIST_SORTREVERSED)

#define SEARCH_CONSTANTS       0x0001
#define SEARCH_FUNCTIONS       0x0002

#define MATCH_BEGINNING 0x0001
#define MATCH_EXACTLY   0x0002
#define MATCH_SUBSTRING 0x0003

/*
#define LIST_GL                 0x0100
#define LIST_WGL                0x0101
*/

// ----- Match modes required for adding extension std::strings ------------------
/*
#define MATCH_EXACTLY   0x001
#define MATCH_BEGINNING 0x002
#define MATCH_SUBSTRING 0x003
*/
// ----- Update modes required for updating lists ---------------------------

#define UPDATE_NONE     0x000
#define UPDATE_NEWLIST  0x001

// --------------------------------------------------------------------------
// Class used for the storage of lists of extensions, functions and constants
// --------------------------------------------------------------------------

class CExtensionEntryList : virtual public CExtensionEntryListIO,
			virtual public TSortFuncs< CExtensionEntry>
{
public:

int              m_sortmode; // List sorting mode
std::string           m_listname; // Name of list

// ----- Constructor and destructor -----------------------------------------

CExtensionEntryList( void ) 
	{ 
	Init(); 
	};

~CExtensionEntryList( void ) 
	{ 
	Deallocate(); 
	};

// ----- Functions and procedures -------------------------------------------

void Init( void );

void Allocate( int num )
	{
	reserve(num);
	}

void Deallocate( void )
	{
	clear();
	}

void Duplicate( const CExtensionEntryList &src )
	{
	*this = src;	
	}

void SetListName( const char *pname )
        {
        m_listname = pname;
        };

void SetListName( const std::string &name )
        {
        m_listname = name;
        };

std::string &GetListName( void )
        {
        return( m_listname );
        };

int  FindName(     const std::string &pname );
int  FindFullName( const char *pname );
int  FindValue(  const char *pvalue );
int  FindProc(   const std::string &pproc );

int  Add( const std::string &name );
int  AddStart( const std::string &name, int funcstart, int conststart );

int  Add( const char *name );
int  AddNameValue( const char *name, const char *value );

void AddProtoVars( const char *pchptra, const char *pchptrc );

// This one is used for the function parmeters
int  AddPrefixNameValue( const char *prefix, const char *name,
			const char *header, unsigned int funcnumparams );

int  AddPrefixNameValue( const std::string &prefix, const std::string &name, 
                         const std::string &header, unsigned int funcnumparams );

int  AddPrefixNameValueProto( const std::string &prefix, const std::string &name, 
                              const std::string &header, const std::string &proto );

void DeleteIndex(  unsigned int index );
int  DeleteName(  const std::string &name );
void DeleteRange( int start, int num );

void SetAllFlags(     int mode );
void ClearAllFlags(   int mode );
int  ClearNameFlag(   const std::string &name, int mode );
int  GetNameFlag(     const std::string &name, int mode );
int  SetNameFlag(     const std::string &name, int mode );
int  SetFullNameFlag( const std::string &name, int flag, int matchmode );
int  ClearFullNameFlag(const std::string &name, int flag, int matchmode );
int  ToggleNameFlag(  const std::string &name, int mode );
void SetIndexFlag(    unsigned int idno, int mode );
int  GetIndexFlag(    unsigned int idno, int mode );
void ClearIndexFlag(  unsigned int idno, int mode );
void ToggleIndexFlag( unsigned int idno, int mode );

void SaveState( void );
void UndoState( void );
void RedoState( void );

void SelectByName( const std::string &name );
void RemoveName( const std::string &name );
void ToggleSortMode( int mode );
void SortRange( int start, int num );

static int SortByName(           CExtensionEntry const &ptra, CExtensionEntry const &ptrb );
static int SortByNameReversed(   CExtensionEntry const &ptra, CExtensionEntry const &ptrb );
static int SortByValue(          CExtensionEntry const &ptra, CExtensionEntry const &ptrb );
static int SortByValueReversed(  CExtensionEntry const &ptra, CExtensionEntry const &ptrb );
static int SortByPrefix(         CExtensionEntry const &ptra, CExtensionEntry const &ptrb );
static int SortByPrefixReversed( CExtensionEntry const &ptra, CExtensionEntry const &ptrb );

void SetSortMode( int mode )
    {
    m_sortmode = mode;
    }

void Sort( void )
    {
    SortRange( 0, size() );
    }

int GetCount( void ) 
    {
    return( size() );
    };

void ResetConstEntry( int pos, int start, int num )
    {
    at(pos).m_conststart = start;
    at(pos).m_constnum   = num;
    };

void ResetFuncEntry( int pos, int start, int num )
    {
    at(pos).m_funcstart = start;
    at(pos).m_funcnum   = num;
    };

void IncrementConstNum( int pos )
    {
    at(pos).m_constnum++;
    };

void IncrementFuncNum( int pos )
    {
    at(pos).m_funcnum++;
    };

void AddExtensionString( const std::string &pextstring );
void RemoveExtensionString( const std::string &pextstring );

void SelectExtensionString( const std::string &pextstring, 
			CExtensionEntryList &ignorelist, 
			CExtensionEntryList &newlist, 
			int mode, int matchmode, int updatemode );

void UnselectExtensionString( const std::string &pextstring,
			int mode, int matchmode );

void SearchConstants( const std::string &string,
                        CHeaderFileDataSearchCallback &callback );

void SearchFunctions( const std::string &string,
                        CHeaderFileDataSearchCallback &callback );

void SearchString( int mode, const std::string &string, 
			CHeaderFileDataSearchCallback &callback );

};

#endif // _EXTLIST_
