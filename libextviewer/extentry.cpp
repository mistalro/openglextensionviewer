// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;

#include "extensionlib.h"

// --------------------------------------------------------------------------
// Set the name and value of the entry
// --------------------------------------------------------------------------

void CExtensionEntry::SetNameValue( const char *name, const char *value)
{
m_name = name;

if( NULL != value )
        {
        m_value = value;
        }

m_pfnproc = string("PFN") + m_name + string("PROC");

strupcase( m_pfnproc );
}

// --------------------------------------------------------------------------
// Set the prefix, name and value of the entry
// --------------------------------------------------------------------------

void CExtensionEntry::SetPrefixNameValue( const char *prefix, const char *name, const char *value)
{
m_prefix  = prefix;
m_name    = name;
m_pfnproc = string("PFN") + m_name + string( "PROC" );

strupcase( m_pfnproc );
}

// --------------------------------------------------------------------------
// Set the prefix, name and header of the entry
// --------------------------------------------------------------------------

void CExtensionEntry::SetPrefixNameHeader( const string &prefix, const string &name, const string &header )
{

m_prefix  = prefix;
m_name    = name;
m_header  = header;
m_pfnproc = string("PFN") + m_name + string("PROC");

strupcase( m_pfnproc );
}

// --------------------------------------------------------------------------
// Set the prefix, name, value and prototype of the entry
// --------------------------------------------------------------------------

void CExtensionEntry::SetPrefixNameValueProto( const string &prefix, 
				const string &name, 
				const string &header, 
				const string &proto )
{
m_prefix  = prefix;
m_name    = name;
m_header  = header;
m_pfnproc = string("PFN") + m_name + string( "PROC" );

strupcase( m_pfnproc );

m_value = proto;
}
