// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _EXTHEADERFILEFUNCWGL_H_
#define _EXTHEADERFILEFUNCWGL_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

// --------------------------------------------------------------------------
// A Generic "filler" class for the new list classes that will be defined
// --------------------------------------------------------------------------

class CExtensionHeaderFileFuncWGL : virtual public CExtensionHeaderFileData,
				    virtual public CExtensionHeaderFileFunc
{
public:
const CExtensionHeaderFileFuncWGL & operator = ( const CExtensionHeaderFileFuncWGL &src )
        {
 	(*(CExtensionHeaderFileData*) this) = src;

	return *this;
        }

void FuncInit( void )
	{
	const std::string str_prefix     = "WGL_";
	const std::string str_funcprefix = "wgl";
	const std::string str_proto      = "WGL_WGLEXT_PROTOTYPES";

	Init();

	SetParameters( str_prefix, str_funcprefix, str_proto );
	SetListName( str_funcprefix );
	}

void FuncClearAllFlags( void ) 
	{
	ClearAllFlags( FLAG_OUTPUT );
	}

virtual void FuncSetAllFlags( void )
	{
	SetAllFlags( FLAG_OUTPUT );
	}

virtual void FuncClearNameFlag( const std::string &name, int flag )
	{
	ClearNameFlag( name, flag );
	}

virtual void FuncAddName( const std::string & /* name */ ) 
	{
	// Nothing to do here
	}

virtual void FuncRemoveName( const std::string &name ) 
	{
	RemoveName( name );
	}

virtual int FuncSetFullNameFlag( const std::string &name, int flag, int matchcode ) 
	{
	return SetFullNameFlag( name, flag, matchcode );	
	}

virtual int FuncGetCount( void ) 
	{
	return GetCount();
	}

virtual int FuncFindName( const std::string &name ) 
	{	
	return FindName( name );
	}

virtual void FuncSetVariable( const std::string &name, const std::string &value ) 
	{
	int index = (atoi(value.data() ) !=0) * FLAG_OUTPUT;

	SetNameFlag( name, index );
	}

virtual void FuncSelectByName( const std::string &name ) 
	{
	SelectByName( name );
	}

virtual int FuncGetIndexFlag( int pos, int flag ) 
	{
	return GetIndexFlag( pos, flag );
	}

virtual int FuncGetNameFlag( const std::string &name, int flag ) 
	{
	return GetNameFlag( name, flag );
	}

virtual void FuncSetIndexFlag( int pos, int flag ) 
	{
	SetIndexFlag( pos, flag );
	}

virtual void FuncSelectExtensionString( const std::string &extstring, 
				CExtensionHeaderFileFuncIgnore &ignorelist, 
				CExtensionHeaderFileFuncNew &newlist,
				int flag, int matchmode, int updatemode ) 
	{
	SelectExtensionString( extstring, ignorelist, newlist, flag, matchmode, updatemode );
	}


virtual void FuncUnselectExtensionString( const std::string &extstring, int flag, int matchmode ) 
	{
	UnselectExtensionString( extstring, flag, matchmode );
	}

virtual void FuncAddExtensionString( const std::string &extstring ) 
	{
	AddExtensionString( extstring );	
	}

virtual void FuncRemoveExtensionString( const std::string &extstring ) 
	{
	RemoveExtensionString( extstring );
	}

virtual void FuncDeleteIndex( int index )
	{
	DeleteIndex(index);
	}

virtual int FuncDeleteExtensionName( const std::string &pname ) 
	{
	return DeleteName(pname);	
	}

virtual CExtensionEntry *FuncGetExtensionEntry( unsigned int index ) 
	{
	if ( index < m_extlist.size() )
		{
		return &m_extlist.at(index);
		}	

	return NULL;
	}

virtual CExtensionEntryList *FuncGetExtensionList( void ) 
	{
	return &m_extlist;
	}

virtual int FuncGetExtensionListNum( void )
	{
	return m_extlist.size();
	}

virtual CExtensionEntryList *FuncGetConstantList( void ) 
	{
	return &m_constlist;
	}
	
virtual CExtensionEntryList *FuncGetFunctionList( void ) 
	{
	return &m_funclist;
	}
};

#endif	// _EXTHEADERFILEFUNCWGL_H_
