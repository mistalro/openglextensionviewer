// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _EXTHEADERFILEFUNC_H_
#define _EXTHEADERFILEFUNC_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

class CExtensionHeaderFileFuncIgnore;
class CExtensionHeaderFileFuncNew;

// --------------------------------------------------------------------------
// The base class for all extension lists
// --------------------------------------------------------------------------

class CExtensionHeaderFileFunc
{
public:

virtual void FuncClearAllFlags( void ) = 0;
virtual void FuncSetAllFlags( void ) = 0;
virtual void FuncClearNameFlag( const string &name, int flag ) = 0;
virtual void FuncAddName( const string &name ) = 0;
virtual void FuncRemoveName( const string &name ) = 0;
virtual int FuncSetFullNameFlag( const string &name, int flag, int matchcode ) = 0;
virtual int FuncGetCount( void ) = 0;
virtual int FuncFindName( const string &name ) = 0;
virtual void FuncSetVariable( const string &name, const string &value ) = 0;
virtual void FuncSelectByName( const string &name ) = 0;
virtual int  FuncGetIndexFlag( int pos, int flag ) = 0;
virtual int  FuncGetNameFlag( const string &name, int flag ) = 0;
virtual void FuncSetIndexFlag( int pos, int flag ) = 0;

virtual void FuncSelectExtensionString( const string &extstring, 
                                CExtensionHeaderFileFuncIgnore &ignorelist,
                                CExtensionHeaderFileFuncNew &newlist,
				int flag, int matchmode, int updatemode ) = 0;

virtual void FuncUnselectExtensionString( const string &extstring, 
				int flag, int matchmode ) = 0;

virtual void FuncAddExtensionString( const string &extstring ) = 0;

virtual void FuncRemoveExtensionString( const string &extstring ) = 0;
virtual void FuncDeleteIndex( int index ) = 0;

virtual int FuncDeleteExtensionName( const string &pname ) = 0;

virtual CExtensionEntry *FuncGetExtensionEntry( unsigned int index ) = 0;
virtual CExtensionEntryList *FuncGetExtensionList( void ) = 0;

virtual int FuncGetExtensionListNum( void )= 0;
virtual CExtensionEntryList *FuncGetConstantList( void ) = 0;
virtual CExtensionEntryList *FuncGetFunctionList( void ) = 0;

};

#endif	// _EXTHEADERFILEFUNC_H_
