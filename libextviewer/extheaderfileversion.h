// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _EXTHEADERFILEFUNCVERSION_H_
#define _EXTHEADERFILEFUNCVERSION_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

// --------------------------------------------------------------------------
// A Generic "filler" class for the new list classes that will be defined
// --------------------------------------------------------------------------

class CExtensionHeaderFileFuncVersion : virtual public CExtensionEntryList,
                                        virtual public CExtensionHeaderFileFunc

{
public:

const CExtensionHeaderFileFuncVersion & operator = ( const CExtensionHeaderFileFuncVersion &src )
	{
	*( (CExtensionEntryList*) this) = src;

	return *this;
	}

void FuncInit( void )
	{
	SetListName( "version" );
	Deallocate();
	Allocate(MAX_VERSIONLIST);
	}

void FuncClearAllFlags( void ) 
	{
	ClearAllFlags( FLAG_OUTPUT );
	}

virtual void FuncSetAllFlags( void )
	{
	SetAllFlags( FLAG_OUTPUT );
	}

virtual void FuncClearNameFlag( const std::string & /*name */, int /* flag */ )
	{
	// Nothing to do here
	}

virtual void FuncAddName( const std::string & /* name */ ) 
	{
	// Nothing to do here
	}

virtual void FuncRemoveName( const std::string & /* name */ ) 
	{
	// Nothing to do here
	}

virtual int FuncSetFullNameFlag( const std::string & /* name */, int /* flag */, int /* matchcode */ ) 
	{
	// Nothing to do here
	return -1;
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
	int index = (atoi(value.data()) !=0) * FLAG_OUTPUT;

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

virtual void FuncAddExtensionString( const std::string & /* extstring */ ) 
	{
	// Nothing to do here 
	}

virtual void FuncRemoveExtensionString( const std::string & /* extstring */ ) 
	{
	// Nothing to do here
	}

virtual void FuncDeleteIndex( int /* index */ )
	{
	// Nothing to do here
	}

virtual int FuncDeleteExtensionName( const std::string & /* pname */ ) 
	{
	// Nothing to do here
	return -1;
	}

virtual CExtensionEntry *FuncGetExtensionEntry( unsigned int index ) 
	{
	if ( index < size() )
		{
		return &at(index);
		}	
	else		
		{
		return NULL;
		}
	}

virtual CExtensionEntryList *FuncGetExtensionList( void ) 
	{
	return this;
	}

virtual int FuncGetExtensionListNum( void )
	{
	return size();
	}

virtual CExtensionEntryList *FuncGetConstantList( void ) 
	{
	return NULL;
	}
	
virtual CExtensionEntryList *FuncGetFunctionList( void ) 
	{
	return NULL;
	}
};

#endif	// _EXTHEADERFILEFUNCVERSION_H_
