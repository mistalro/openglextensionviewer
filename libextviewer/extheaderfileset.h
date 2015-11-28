// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#define LIST_MIN 0
// These are stored in m_headerlist
#define LIST_GL  0x0000
#define LIST_WGL 0x0001
#define LIST_GLX 0x0002
#define LIST_COREARB 0x0003

// These are stored in separate lists
#define LIST_VENDOR 0x0004
#define LIST_NEW    0x0005
#define LIST_IGNORE 0x0006
#define LIST_SYSTEM 0x0007

// Only the GL, WGL, GLX and COREARB arrays are stored in a list
#define LIST_MAX 4

#define FLAG_GL  0x0001
#define FLAG_WGL 0x0002
#define FLAG_GLX 0x0004
#define FLAG_COREARB 0x0008
#define FLAG_ALL (FLAG_GL|FLAG_WGL|FLAG_GLX|FLAG_COREARB)

// --------------------------------------------------------------------------
// Flags for reading OpenGL Extension string
// --------------------------------------------------------------------------
                                                                                
#define EXTENSION_GL        0x001
#define EXTENSION_GLX       0x002
#define EXTENSION_GLXSERVER 0x003
#define EXTENSION_GLXCLIENT 0x004
#define EXTENSION_WGL       0x005

// --------------------------------------------------------------------------
// Data derived from the extension files
// --------------------------------------------------------------------------
                                                                                
class CExtensionHeaderFileSet : virtual public CExtensionHeaderFileSetIO
{
public:
// ----- Constructor and Destructor -----------------------------------------
                                                                                
CExtensionHeaderFileSet( void )
        {
        Init();
        };
                                                                                
~CExtensionHeaderFileSet( void ) 
	{ 
	};
                                                                                
// ----- Functions and Procedures -------------------------------------------
                                                                                
void Init( void );
          
int  SavedStateCount( void )
	{
	return( m_savedstates );	
	}
                                                                      
int  SearchAllLists( int mode, const string &strsearch, 
			CHeaderFileDataSearchCallback &callback );

void ListClearNameFlag(   int listid, const string &name, int flag );
void ListAddName(         int listid, const string &name );
void ListRemoveName(      int listid, const string &name );
int  ListSetFullNameFlag( int listid, const string &name, int flag, int matchmode );

void ListClearAllFlags(   void );
void ListSetAllFlags(     void );
void ListSetAllFlags(     int listid );
void ListClearAllFlags(   int listid );
int  ListGetCount(        int listid );
int  ListFindName(        int listid, const string &name );
void ListSortAll( void );

void IgnoreNewExtensions(    void );
char *GetNewExtensionString( void );
                                                                                
CExtensionHeaderFileFunc *ListFromIndex( int listid);

void ListSetVariable(  int listid, const string &name, const string &value );
void ListSelectByName( int listid, const string &name );
int  ListGetIndexFlag( int listid, int pos, int flag );
int  ListGetNameFlag(  int listid, const char *name, int flag );
void ListSetIndexFlag( int listid, int pos, int flag );
void ListDeleteExtensionIndex( int listid, int index );

int  ListDeleteExtensionName( int listid, const string &name );

void ListSelectExtensionString( int listid, const string &extstring,
	int flag, int matchmode, int updatemode );                                                                  
void ListUnselectExtensionString( int listid, const string &extstring,
	int flag, int matchmode );

void ListAddExtensionString(    int listid, const string &extstring );
void ListRemoveExtensionString( int listid, const string &extstring );

// ----- Undo Operations -----------------
                                                                                
void SaveState( void );
void UndoState( void );
void RedoState( void );
                                                                                
// ----- Pixel format list ---------------
                                                                                
void ReadPixelFormatList( CPixelFormatDescriptorList &pixelformatlist );
                                                                                
void CountSelectedExtensions( void );

void ClearLists( int flags);

int CheckExtensionDownload( const string &extname, int mode );

int ReadHeaderFiles( CHeaderFileProgressCallback &callback, 
			const string &glheader, const string &pwglheader, 
			const string &glxheader, const string &corearbheader,
			int replacemode );

int ReadHeaderFile( char *filename,
        CHeaderFileProgressCallback &callback,
	CExtensionEntryList &extlist, 
	CExtensionEntryList &extconst, 
	CExtensionEntryList &extfunclist,
	const char *pextname, const char *pstart, const char *pfunc,
        CExtensionEntryList &versionlist, CExtensionEntryList &vendorlist );

// ----- Find Extension data ------------------------------------------------

CExtensionEntry *GetExtensionEntry( int listid, int index );

void FindExtensionListIndex(const char *pstr, int &newindex, int &newlistid);

int GetExtensionListNum( int listid );

CExtensionEntryList *GetExtensionList( int listid );
CExtensionEntryList *GetConstantList( int listid );
CExtensionEntryList *GetFunctionList( int listid );
};
