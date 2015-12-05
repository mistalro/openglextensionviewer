// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _EXTENTRY_
#define _EXTENTRY_

extern unsigned int RotateBits( unsigned int value, int shift );

// --------------------------------------------------------------------------
// Extension entry class
// --------------------------------------------------------------------------
                                                                                
class CExtensionEntry : virtual public CExtensionEntryIO
{
public:
CExtensionEntry( void ) { Init(); };
~CExtensionEntry( void ) { };
                                                                                
void Init( void )
        {
        m_funcstart = 0;
        m_funcnum = 0;
        m_flags = 0;
        m_conststart = 0;
        m_constnum = 0;
        };
                                                                                
void Duplicate( CExtensionEntry &entry )
	{
	*this = entry;
	};

void Deallocate( void )
	{
	std::cout << "ExtensionEntry::Deallocate\n";
	};

void Display( void )
	{

	};

void SetNameValue( const char *pname, const char *pvalue );
void SetPrefixNameValue( const char *prefix, const char *name, const char *value);
void SetPrefixNameHeader( const std::string &prefix, const std::string &name, const std::string &header );
void SetPrefixNameValueProto( const std::string &prefix,
                                const std::string &name,
                                const std::string &header,
                                const std::string &proto );

inline void EntrySetFlag(   int mode )
        {
        m_flags |= mode;
        };
                                                                                
inline int  EntryGetFlag(   int mode )
        {
        return m_flags & mode;
        };
                                                                                
inline void EntryClearFlag( int mode )
        {
        m_flags &= ~mode;
        };
                                                                                
inline void EntryToggleFlag( int mode )
        {
        m_flags ^= mode;
        };
                                                                                
inline void EntrySaveState( int mode )
        {
        int flags = m_flags;
                                                                                
        m_flags = ((flags & mode) * 3) | (flags & ~mode) << 1;
        };
                                                                                
inline void EntryUndoState( void )
        {
        m_flags = RotateBits( m_flags, 1 );
        };
                                                                                
inline void EntryRedoState( void )
        {
        m_flags = RotateBits( m_flags, -1 );
        };
                                                                                
inline void EntryGetConstInfo( int &start, int &num )
        {
        start = m_conststart;
        num = m_constnum;
        };
                                                                                
inline void EntryGetFuncInfo( int &start, int &num )
        {
        start = m_funcstart;
        num = m_funcnum;
        };
                                                                                
inline int EntryGetFuncCount( void )
        {
        return m_funcnum;
        };
                                                                                
inline int EntryGetConstCount( void )
        {
        return m_constnum;
        };

inline int SortCompare( CExtensionEntry &entry )
	{
	return( m_funcnum - entry.m_funcnum );
	};

inline int operator < ( const CExtensionEntry &entry )
	{
	return( m_funcnum < entry.m_funcnum );
	};

inline int operator > ( const CExtensionEntry &entry )
	{
	return( m_funcnum > entry.m_funcnum );
	};
};
                                                                                
#endif
