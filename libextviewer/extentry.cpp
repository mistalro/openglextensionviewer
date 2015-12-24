// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

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

m_pfnproc = std::string("PFN") + m_name + std::string("PROC");

strupcase( m_pfnproc );
}

// --------------------------------------------------------------------------
// Set the prefix, name and value of the entry (used for functions)
// --------------------------------------------------------------------------

void CExtensionEntry::SetPrefixNameValue( const char *prefix, const char *name, const char *value, unsigned int funcnumparams )
{
m_prefix  = prefix;
m_name    = name;
m_pfnproc = std::string("PFN") + m_name + std::string( "PROC" );
m_funcnumparams = funcnumparams;

strupcase( m_pfnproc );
}

// --------------------------------------------------------------------------
// Set the prefix, name and header of the entry
// --------------------------------------------------------------------------

void CExtensionEntry::SetPrefixNameHeader( const std::string &prefix, const std::string &name, const std::string &header, unsigned int funcnumparams )
{

m_prefix  = prefix;
m_name    = name;
m_header  = header;
m_pfnproc = std::string("PFN") + m_name + std::string("PROC");
m_funcnumparams = funcnumparams;

strupcase( m_pfnproc );
}

// --------------------------------------------------------------------------
// Set the prefix, name, value and prototype of the entry
// --------------------------------------------------------------------------

void CExtensionEntry::SetPrefixNameValueProto( const std::string &prefix, 
				const std::string &name, 
				const std::string &header, 
				const std::string &proto )
{
m_prefix  = prefix;
m_name    = name;
m_header  = header;
m_pfnproc = std::string("PFN") + m_name + std::string( "PROC" );

strupcase( m_pfnproc );

m_value = proto;
}
