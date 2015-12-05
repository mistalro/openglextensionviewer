// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "extensionlib.h"

#define OPTION_LISTFUNCS

// --------------------------------------------------------------------------
// Initialise the list
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: None
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::Init( void )
{
m_savedstates = 0;

m_gllist.FuncInit();
m_glxlist.FuncInit();
m_wgllist.FuncInit();
m_corearblist.FuncInit();
m_vendorlist.FuncInit();
m_systemlist.FuncInit();
m_newlist.FuncInit();
m_ignorelist.FuncInit();
m_versionlist.FuncInit();
}

// --------------------------------------------------------------------------
// Clear all lists
//
// Inputs:  flags - Flags to select the lists
//
// Outputs: None
//
// Results: None 
//
// Effects: The selected lists are cleared
// --------------------------------------------------------------------------                                                                               
void CExtensionHeaderFileSet::ClearLists( int flags)
{
if ( flags & FLAG_GL )
        {
        m_gllist.Init();
        }

if ( flags & FLAG_WGL )
        {
        m_wgllist.Init();
        }

if ( flags & FLAG_GLX )
        {
        m_glxlist.Init();
        }

m_vendorlist.Init();
}

// --------------------------------------------------------------------------
// Clear all flags
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: All lists are cleared
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::ListClearAllFlags( void )
{
m_wgllist.ClearAllFlags( FLAG_OUTPUT );
m_gllist.ClearAllFlags(  FLAG_OUTPUT );
m_glxlist.ClearAllFlags( FLAG_OUTPUT );
m_vendorlist.ClearAllFlags( FLAG_OUTPUT );
m_corearblist.ClearAllFlags( FLAG_OUTPUT );
}

// --------------------------------------------------------------------------
// Sort all lists
//
// Inputs:  None
//
// Outputs: None
//
// Results: Index value of name in list, -1 if not found
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::ListSortAll( void )
{
m_vendorlist.Sort();
m_systemlist.Sort();
m_gllist.Sort();
m_wgllist.Sort();
m_glxlist.Sort();
m_newlist.Sort();
m_ignorelist.Sort();
m_corearblist.Sort();
}

// --------------------------------------------------------------------------
// Select all extensions
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: All extensions are selected
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::ListSetAllFlags( void )
{
m_wgllist.SetAllFlags( FLAG_OUTPUT );
m_gllist.SetAllFlags(  FLAG_OUTPUT );
m_glxlist.SetAllFlags( FLAG_OUTPUT );
m_corearblist.SetAllFlags( FLAG_OUTPUT);
m_vendorlist.ClearAllFlags( FLAG_OUTPUT );
}

// --------------------------------------------------------------------------
// Count the number of selected extensions
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The number of selected extensions in each list is counted
// --------------------------------------------------------------------------                                                                                

void CExtensionHeaderFileSet::CountSelectedExtensions( void )
{
m_gllist.CountFunctions();
m_wgllist.CountFunctions();
m_glxlist.CountFunctions();
m_corearblist.CountFunctions();
}

// --------------------------------------------------------------------------
// Search all lists
// --------------------------------------------------------------------------

int CExtensionHeaderFileSet::SearchAllLists( int mode, const std::string &strsearch,
                        CHeaderFileDataSearchCallback &callback )
{
m_gllist.SearchString( mode, strsearch, callback );
m_glxlist.SearchString( mode, strsearch, callback );
m_wgllist.SearchString( mode, strsearch, callback );
m_corearblist.SearchString( mode, strsearch, callback );

return 1;
}

// --------------------------------------------------------------------------
// Save current state
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The current state is saved
//
// Bit 0 is current state
// Bits 1..23 are previous states
//
// Here we copy bit 0 to bit 1 and shuffle bits 1..23 upwards
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::SaveState( void )
{
if ( m_savedstates < 31 )
        {
        m_savedstates++;
        }

m_gllist.SaveState();
m_wgllist.SaveState();
m_glxlist.SaveState();
m_corearblist.SaveState();
}


// --------------------------------------------------------------------------
// Undo state
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The previous state is restored
//
// To undo the system, we shift the bits rightwards
// The current state is copied into bit 31
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::UndoState( void )
{
if ( 0 == --m_savedstates )
        {
        return;
        }

m_gllist.UndoState();
m_wgllist.UndoState();
m_glxlist.UndoState();
m_corearblist.UndoState();
}

// --------------------------------------------------------------------------
// Redo state
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The state is restored
//
// To redo the system, we rotate the bits leftwards.
// The current state is coped from bit 31
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::RedoState( void )
{
m_gllist.RedoState();
m_wgllist.RedoState();
m_glxlist.RedoState();
m_corearblist.RedoState();
}

// --------------------------------------------------------------------------
// Read the selected header files
//
// Inputs:  callback   - Progress callback
//          pglheader  - Pointer to GL header file path
//          pwglheader - Pointer to WGL header file path
//          pglxheader - Pointer to GLX header file path
//          replacemode - Replacement mode 
//
// Outputs: None
//
// Results: A combined result code of all three files
//
// Effects: The selected files are read
// --------------------------------------------------------------------------                                                                               

int CExtensionHeaderFileSet::ReadHeaderFiles(
                        CHeaderFileProgressCallback &callback,
                        const std::string &glheader, const std::string &wglheader,
                        const std::string &glxheader, const std::string &corearbheader,
			const int replacemode )
{
int resultgl, resultwgl, resultglx, resultcorearb;

resultgl = resultwgl = resultglx = resultcorearb = 0;

if ( replacemode == MODE_REPLACE )
        {
        Init();
        }

// ----- Read the main OpenGL header ---------------------------------------

resultgl  = m_gllist.ReadHeaderFile(
                glheader, callback, m_versionlist, m_vendorlist );

// ----- Read the WGL header -----------------------------------------------

resultwgl = m_wgllist.ReadHeaderFile(
                wglheader, callback, m_versionlist, m_vendorlist );

// ----- Read the GLX header -----------------------------------------------

resultglx = m_glxlist.ReadHeaderFile(
                glxheader, callback, m_versionlist, m_vendorlist );

// ----- Read the COREARB header -------------------------------------------

resultcorearb = m_corearblist.ReadHeaderFile(
                corearbheader, callback, m_versionlist, m_vendorlist );

// ------ Return final result ----------------------------------------------

return (resultwgl * FLAG_WGL)
        + (resultgl  * FLAG_GL)
        + (resultglx * FLAG_GLX) 
	+ (resultcorearb * FLAG_COREARB);
}

// --------------------------------------------------------------------------
// Given an extension name, find the relevant list and index
//
// Inputs: pstr - Pointer to extension name
//         rnewindex - Reference to index position
//         rnewlistid - Reference to list id
//
// Outputs: rnewindex - Index of extension in list
//          nrewlistid - List to update
//
// Results: None
//
// Effects: None
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::FindExtensionListIndex(
                         const char *pstr, int &newindex, int &newlistid)
{
newindex = -1;

if ( newindex == -1 )	
	{
	newindex = ListFindName( LIST_GL, (char *) pstr );
	newlistid = LIST_GL;
	}

if ( newindex == -1 )
        {
        newindex = ListFindName( LIST_GLX, (char *) pstr );
        newlistid = LIST_GLX;
        }

if ( newindex == -1 )
        {
        newindex = ListFindName( LIST_WGL, (char *) pstr );
        newlistid = LIST_WGL;
        }

if ( newindex == -1 )
	{
        newindex = ListFindName( LIST_COREARB, (char *) pstr );
        newlistid = LIST_COREARB;
	}

if ( newindex == -1 )
        {
        newindex = ListFindName( LIST_SYSTEM, (char *) pstr);
        newlistid = LIST_SYSTEM;
        }
}

// --------------------------------------------------------------------------
// Check extension download
// --------------------------------------------------------------------------

int CExtensionHeaderFileSet::CheckExtensionDownload(
                                        const std::string &extname, int mode )
{
int dodownload = false;

switch ( mode )
        {
        case DOWNLOAD_ALL:
                dodownload = true;
                break;

        case DOWNLOAD_SELECTED:
                if ( ListGetNameFlag( LIST_GL, extname.data(),
                                FLAG_OUTPUT ) >= 0 )
                        {
                                dodownload = true;
                        }

                if ( ListGetNameFlag( LIST_WGL, extname.data(),
                                FLAG_OUTPUT ) >= 0 )
                        {
                                dodownload = true;
                        }

                if ( ListGetNameFlag( LIST_GLX, extname.data(),
                                FLAG_OUTPUT ) >= 0 )
                        {
                                dodownload = true;
                        }

                if ( ListGetNameFlag( LIST_COREARB, extname.data(),
                                FLAG_OUTPUT ) >= 0 )
                        {
                                dodownload = true;
                        }
                break;

        case DOWNLOAD_NEW:
                if ( ListGetNameFlag( LIST_NEW, extname.data(),
                                FLAG_OUTPUT ) >= 0 )
                        {
                                dodownload = true;
                        }
                break;

        default:
                dodownload = false;
                break;
        }

return dodownload;
}

// --------------------------------------------------------------------------
// Ignore the extension in the new extensions list. This is achieved by
// copying the items to the ignored extensions list.
//
// Inputs:  None
//
// Outputs: None
//
// Results: None 
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------                                                                               

void CExtensionHeaderFileSet::IgnoreNewExtensions( void )
{
for ( std::vector <CExtensionEntry>::iterator it = m_newlist.begin(); it != m_newlist.end(); ++it)
        {
        m_ignorelist.Add( it->m_name.data() );
        }
}

// --------------------------------------------------------------------------
// Retrieve the list of new/unknown extensions
//
// Inputs: None
//
// Outputs: None
//
// Results: A character std::string listing the unknown extensions
//
// Effects: None
// --------------------------------------------------------------------------

char *CExtensionHeaderFileSet::GetNewExtensionString( void )
{
char *pnewext;
int len = 0;

for ( std::vector <CExtensionEntry>::iterator it = m_newlist.begin(); it != m_newlist.end(); ++it)
        {
        len += it->m_name.length() + 1;
        }

pnewext = (char *) calloc( len, sizeof(char) );

len = 0;

for ( std::vector <CExtensionEntry>::iterator it = m_newlist.begin(); it != m_newlist.end(); ++it)
        {
        strcpy( pnewext+len, it->m_name.data() );

        len += it->m_name.length() + 1;

        pnewext[len] = ' ';
        len++;
        }

pnewext[len] = '\0';                                                             

return pnewext;
}

// --------------------------------------------------------------------------
// Process a set of pixel format lists
//
// Inputs: pixelformatlist - List of pixel formats
//
// Outputs: None
//
// Results: None
//
// Effects: The pixel format list is used to examine all available pixel
//          modes
//
// Notes:
//
// For each pixel format, get the OpenGL extension std::string
// Then for each extension name, check for a match in the GL and WGL lists
// If an extension name does not exist in either of the GL or WGL lists
// it is added to the new extension list. Otherwise do nothing
//
// --------------------------------------------------------------------------

static int extension_table[5] =
        {
        EXTENSION_GL, EXTENSION_GLX, EXTENSION_GLXSERVER, EXTENSION_GLXCLIENT, EXTENSION_WGL,
        };

static int list_table[5] =
        {
        LIST_GL, LIST_GLX, LIST_GLX, LIST_GLX, LIST_WGL
        };

#define MAX_TABLE (sizeof(list_table)/sizeof(int) )

void CExtensionHeaderFileSet::ReadPixelFormatList(
                        CPixelFormatDescriptorList &pixelformatlist )
{
char *pstring;
std::string strdata;

pstring = new char[10240];
m_newlist.Deallocate();

#ifdef DEBUG
cout << "Number of items = " << pixelformatlist.GetCount2() << "\n";
cout << "Examining extension lists\n";
#endif

// For each extension GLX, GL, WGL
for ( unsigned int table = 0; table < MAX_TABLE; table++ )
	{
	// Get the GL extension std::string based upon the specified field
	pixelformatlist.GetExtensionString( 0, extension_table[table], pstring );

#ifdef DEBUG
cout << "Examining item " << ", table " << table << "|" << pstring << "|\n";
#endif

	// Add the entries to the selected list
	strdata = std::string(pstring);

	ListSelectExtensionString( list_table[table], strdata,
			FLAG_OUTPUT, MATCH_EXACTLY, UPDATE_NEWLIST );

	// Add extension std::string to the system list too
	m_systemlist.AddExtensionString( strdata );
	}

#ifdef DEBUG
cout << "Examining extension lists completed.\n";
#endif

delete [] pstring;
}

// --------------------------------------------------------------------------
// Return a reference to the selected list
// --------------------------------------------------------------------------

CExtensionHeaderFileFunc *CExtensionHeaderFileSet::ListFromIndex( int listid )
{
CExtensionHeaderFileFunc *plist;

switch (listid)
	{
	case LIST_WGL:
		plist = &m_wgllist;
		break;

	case LIST_GL:
		plist = &m_gllist;
		break;

	case LIST_GLX:
		plist = &m_glxlist;
		break;

	case LIST_COREARB:
		plist = &m_corearblist;
		break;

	case LIST_VENDOR:
		plist = &m_vendorlist;
		break;

	case LIST_NEW:
		plist = &m_newlist;
		break;

	case LIST_IGNORE:
		plist = &m_ignorelist;
		break;

	case LIST_SYSTEM:
		plist = &m_systemlist;
		break;

	default:
		plist = NULL;
	}

return plist;
}

// ==========================================================================
// THESE ARE ALL THE LIST SELECTOR FUNCTIONS
// ==========================================================================

void CExtensionHeaderFileSet::ListClearAllFlags( int listid )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncClearAllFlags();
}

// --------------------------------------------------------------------------
// Select all the extensions in the selected list
//
// Inputs: listid - Which list to select
//
// Outputs: None
//
// Results: None
//
// Effects: All the items in the selected list are selected
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::ListSetAllFlags( int listid )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncSetAllFlags();
}

// --------------------------------------------------------------------------
// Unselect the extensions which match the name
//
// Inputs:  listid - Which list
//          name   - Extension to match
//          flag   - Selection flag

// Outputs: None
//
// Results: None
//
// Effects: None
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::ListClearNameFlag( 
			int listid, const std::string &name, int flag )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncClearNameFlag(name, FLAG_OUTPUT);
}

// --------------------------------------------------------------------------
// Add the extension to the selected list
//
// Inputs:  listid - Which list 
//          name   - Selected extension
//
// Outputs: None
//
// Results: None
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------
           
void CExtensionHeaderFileSet::ListAddName( int listid, const std::string &name )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncAddName(name);
}

// --------------------------------------------------------------------------
// Remove or the extension to the selected list
//
// Inputs:  listid - Which list 
//          name   - Selected extension
//
// Outputs: None
//
// Results: None
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------
                                                                     
void CExtensionHeaderFileSet::ListRemoveName( int listid, const std::string &name )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncRemoveName(name);
}

// --------------------------------------------------------------------------
// Set the full name of the extension
//
// Inputs:  list - Which list 
//          name - Selected extension
//          matchmode - Which mode to use
// Outputs: None
//
// Results: None
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------
                                                                                
int CExtensionHeaderFileSet::ListSetFullNameFlag( 
		int listid, const std::string &name, int flag, int matchmode )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

return plist->FuncSetFullNameFlag(name, flag, matchmode);
}

// --------------------------------------------------------------------------
// Set the full name of the extension
//
// Inputs:  list - Which list 
//          name - Selected extension
//          matchmode - Which mode to use
// Outputs: None
//
// Results: None
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------
                                                                                
int CExtensionHeaderFileSet::ListGetCount( int listid )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

return plist->FuncGetCount();
}

// --------------------------------------------------------------------------
// Find the name of the extension
//
// Inputs:  list - Which list 
//          name - Selected extension
//
// Outputs: None
//
// Results: Index value of name in list, -1 if not found
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------

int CExtensionHeaderFileSet::ListFindName( int listid, const std::string &name )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

return plist->FuncFindName( name );
}

// --------------------------------------------------------------------------
// Set the variable name
//
// Inputs:  list - Which list
//          name - Name of extension
//          value - Ascii integer of variable to set
//
// Outputs: None
//
// Results: Index value of name in list, -1 if not found
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::ListSetVariable( int listid, 
					const std::string &name, const std::string &value )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncSetVariable( name, value );
}
                                                                               
// --------------------------------------------------------------------------
// Select list items by name
//
// Inputs:  list - Which list
//          name - Name of extension
//
// Outputs: None
//
// Results: Index value of name in list, -1 if not found
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::ListSelectByName( int listid, const std::string &name )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncSelectByName( name );
}
                                                                                
// --------------------------------------------------------------------------
// Get the output flag of an extension selected by index
//
// Inputs:  list - Which list
//	    pos  - Position 
//          name - Name of extension
//
// Outputs: None
//
// Results: Index value of name in list, -1 if not found
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------

int CExtensionHeaderFileSet::ListGetIndexFlag( int listid, int pos, int flag )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

return plist->FuncGetIndexFlag( pos, flag );
}

// --------------------------------------------------------------------------
// Get the output flag of an extension selected by name
//
// Inputs:  list - Which list
//	    pos  - Position 
//          name - Name of extension
//
// Outputs: None
//
// Results: Index value of name in list, -1 if not found
//
// Effects: None
// --------------------------------------------------------------------------
                                                                                
int CExtensionHeaderFileSet::ListGetNameFlag( int listid, 
						const char *name, int flag )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

return plist->FuncGetNameFlag( name, flag );
}
                                                                                
// --------------------------------------------------------------------------
// Get the output flag of an extension selected by name
//
// Inputs:  list - Which list
//	    pos  - Position 
//          name - Name of extension
//
// Outputs: None
//
// Results: None
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::ListSetIndexFlag( int listid, int pos, int flag )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncSetIndexFlag( pos, flag );
}

// --------------------------------------------------------------------------
// Select the extensions from an extension std::string
//
// Inputs:  list - Which list
//	    pextstring - Pointer to the ASCII extension std::string
//          ignorelist - List of ignored extensions
//          newlist    - List of new extensions
//          systemlist - List of extensions known to system
//          flag       - Flag used to select extensions
//          matchmode  - Mode used to match extensions
//
// Outputs: None
//
// Results: None 
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------                                                                               

void CExtensionHeaderFileSet::ListSelectExtensionString(         
	int listid, const std::string &extstring, int flag,
        int matchmode, int updatemode )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncSelectExtensionString( extstring, m_ignorelist, m_newlist, flag, matchmode, updatemode );
}

// --------------------------------------------------------------------------
// Unselect the extensions from an extension std::string
//
// Inputs:  list - Which list
//          pextstring - Pointer to the ASCII extension std::string
//          ignorelist - List of ignored extensions
//          newlist    - List of new extensions
//          systemlist - List of extensions known to system
//          flag       - Flag used to select extensions
//          matchmode  - Mode used to match extensions
//
// Outputs: None
//
// Results: None
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------                                                                                 

void CExtensionHeaderFileSet::ListUnselectExtensionString(
        int listid, const std::string &extstring, int flag, int matchmode )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncUnselectExtensionString( extstring, flag, matchmode);
}

// --------------------------------------------------------------------------
// Add the extensions contained with the extension std::string to the list
//
// Inputs: pextstring - Pointer to the ASCII character std::string
//
// Outputs: None
//
// Results: None
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------
                                                                                
void CExtensionHeaderFileSet::ListAddExtensionString( int listid, 
						const std::string &extstring )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncAddExtensionString( extstring );
}

// --------------------------------------------------------------------------
// Remove the extensions contained with the extension std::string from the list
//
// Inputs: pextstring - Pointer to the ASCII character std::string
//
// Outputs: None
//
// Results: None
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------

void CExtensionHeaderFileSet::ListRemoveExtensionString( int listid, 
						const std::string &extstring )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncRemoveExtensionString( extstring );
} 

// --------------------------------------------------------------------------
// Delete the selected extension from the list
//
// Inputs:  list - Which list
//	    index- Index of the extension
//
// Outputs: None
//
// Results: None 
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------                                                                               

void CExtensionHeaderFileSet::ListDeleteExtensionIndex( int listid, int index )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

plist->FuncDeleteIndex( index);
}

// --------------------------------------------------------------------------
// Delete the selected extension name from the list
//
// Inputs:  list - Which list
//	    pname - Which name
//
// Outputs: None
//
// Results: None 
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------                                                                               

int CExtensionHeaderFileSet::ListDeleteExtensionName( int listid, 
					const std::string &pname )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

return plist->FuncDeleteExtensionName( pname );
}

// --------------------------------------------------------------------------
// Return the extension entry selected by index
//
// Inputs:  listid - Which list
//          index  - Which index
//
// Outputs: None
//
// Results: None 
//
// Effects: The selected list is updated
// --------------------------------------------------------------------------                                                                               

CExtensionEntry *CExtensionHeaderFileSet::GetExtensionEntry( 
				int listid, int index )
{
if ( index < 0)
	{
	return NULL;
	}
                                                                                
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

return plist->FuncGetExtensionEntry( index);
}

// --------------------------------------------------------------------------
// Return the extension list information
//
// Inputs:   listid - Which list
//
// Outputs:  None
//
// Results:  None
//
// Effects:  None
// --------------------------------------------------------------------------

CExtensionEntryList *CExtensionHeaderFileSet::GetExtensionList( int listid )
{
if ( listid < 0 )
	{
	return NULL;
	}

CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

if (NULL != plist)
	{
	return plist->FuncGetExtensionList();
	}
else
	{
	return NULL;
	}
}

// --------------------------------------------------------------------------
// Return the number of items in the list
//
// Inputs:  listid - Which list
//
// Outputs: None
//
// Results: None
//
// Effects: None
// --------------------------------------------------------------------------

int CExtensionHeaderFileSet::GetExtensionListNum( int listid )
{
if ( listid < 0 )
	{
	return -1;
	}

CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

if (NULL != plist)
	{
	return plist->FuncGetExtensionListNum();
	}
else
	{
	return 0;
	}
}

// --------------------------------------------------------------------------
// Get Constant List
// --------------------------------------------------------------------------

CExtensionEntryList *CExtensionHeaderFileSet::GetConstantList( int listid )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

if (NULL != plist)
	{
	return plist->FuncGetConstantList();
	}
else
	{
	return NULL;
	}
}

// --------------------------------------------------------------------------
// Get Function list
// --------------------------------------------------------------------------

CExtensionEntryList *CExtensionHeaderFileSet::GetFunctionList( int listid )
{
CExtensionHeaderFileFunc *plist = ListFromIndex( listid );

if (NULL != plist )
	{
	return plist->FuncGetFunctionList();
	}
else
	{
	return NULL;
	}
}
