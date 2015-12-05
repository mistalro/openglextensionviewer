// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _EXTHEADERFILEFUNCNEW_H_
#define _EXTHEADERFILEFUNCNEW_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

// --------------------------------------------------------------------------
// A Generic "filler" class for the new list classes that will be defined
// --------------------------------------------------------------------------

class CExtensionHeaderFileFuncNew : virtual public CExtensionEntryList,
                                        virtual public CExtensionHeaderFileFunc

{
public:

void FuncInit( void )
	{
	SetListName( "new" );
	Deallocate();
	}

void FuncClearAllFlags( void ) 
	{
	ClearAllFlags( FLAG_OUTPUT );
	}

virtual void FuncSetAllFlags( void )
	{
	// Nothing to do here
	}

virtual void FuncClearNameFlag( const std::string &name, int flag )
	{
	ClearNameFlag( name, flag );
	}

virtual void FuncAddName( const std::string &name ) 
	{
	Add( name );
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

virtual void FuncSelectExtensionString( const std::string & /* extstring */, 
				CExtensionHeaderFileFuncIgnore &/* ignorelist */, 
				CExtensionHeaderFileFuncNew & /* newlist */,
				int /* flag */, int /* matchmode */, int /*updatemode */) 
	{
	// Nothing to do here
	}

virtual void FuncUnselectExtensionString( const std::string &/* extstring */, int /* flag */, int /* matchmode */ ) 
	{
	// Nothing to do here
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

#endif	// _EXTHEADERFILEFUNCNEW_H_
