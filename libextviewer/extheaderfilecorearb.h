// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _EXTHEADERFILEFUNCCOREARB_H_
#define _EXTHEADERFILEFUNCCOREARB_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

// --------------------------------------------------------------------------
// A Generic "filler" class for the new list classes that will be defined
// --------------------------------------------------------------------------

class CExtensionHeaderFileFuncCoreARB : virtual public CExtensionHeaderFileData,
                                    virtual public CExtensionHeaderFileFunc

{
public:
const CExtensionHeaderFileFuncCoreARB & operator = ( const CExtensionHeaderFileFuncCoreARB &src )
        {
        (*(CExtensionHeaderFileData*) this) = src;

        return *this;
        }

void FuncInit( void )
	{
        const string str_prefix     = "GL_";
        const string str_funcprefix = "gl_";
        const string str_proto      = "GL_GLEXT_PROTOTYPES";
	const string str_listname   = "corearb";
	Init();

	SetParameters(str_prefix, str_funcprefix, str_proto);
	SetListName( str_listname );
	}

void FuncClearAllFlags( void ) 
	{
	ClearAllFlags( FLAG_OUTPUT );
	}

virtual void FuncSetAllFlags( void )
	{
	SetAllFlags( FLAG_OUTPUT );
	}

virtual void FuncClearNameFlag( const string &name, int flag )
	{
	ClearNameFlag( name, flag );
	}

virtual void FuncAddName( const string &/* name */) 
	{
	// Nothing to do here
	}

virtual void FuncRemoveName( const string &name ) 
	{
	RemoveName( name );
	}

virtual int FuncSetFullNameFlag( const string &name, int flag, int matchcode ) 
	{
	return SetFullNameFlag( name, flag, matchcode );	
	}

virtual int FuncGetCount( void ) 
	{
	return GetCount();
	}

virtual int FuncFindName( const string &name ) 
	{
	return FindName( name );
	}

virtual void FuncSetVariable( const string &name, const string &value ) 
	{
	int index = (atoi(value.data() ) !=0) * FLAG_OUTPUT;

	SetNameFlag( name, index );
	}

virtual void FuncSelectByName( const string &name ) 
	{
	SelectByName( name );
	}

virtual int FuncGetIndexFlag( int pos, int flag ) 
	{
	return GetIndexFlag( pos, flag );
	}

virtual int FuncGetNameFlag( const string &name, int flag ) 
	{
	return GetNameFlag( name, flag );
	}

virtual void FuncSetIndexFlag( int pos, int flag ) 
	{
	SetIndexFlag( pos, flag );
	}

virtual void FuncSelectExtensionString( const string &extstring, 
				CExtensionHeaderFileFuncIgnore &ignorelist, 
				CExtensionHeaderFileFuncNew &newlist,
				int flag, int matchmode, int updatemode ) 
	{
	SelectExtensionString( extstring, ignorelist, newlist, flag, matchmode, updatemode );
	}


virtual void FuncUnselectExtensionString( const string &extstring, int flag, int matchmode ) 
	{
	UnselectExtensionString( extstring, flag, matchmode );
	}

virtual void FuncAddExtensionString( const string &extstring ) 
	{
	AddExtensionString( extstring );	
	}

virtual void FuncRemoveExtensionString( const string &extstring ) 
	{
	RemoveExtensionString( extstring );
	}

virtual void FuncDeleteIndex( int index ) 
	{
	DeleteIndex(index);
	}

virtual int FuncDeleteExtensionName( const string &pname ) 
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

#endif	// _EXTHEADERFILEFUNCCOREARB_H_
