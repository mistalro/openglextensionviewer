// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "extensionlib.h"

// --------------------------------------------------------------------------
// Initialiser
// --------------------------------------------------------------------------
                                                                                
void COutputFileSettings::Init( void )
{
m_classname        = "CExtensionManager";

m_classnamedcolon  = "%s::";
m_classnamedcolon += m_classname;

m_scriptfile       = "extcode.txt";                                                                                 
m_cppmode 	   = true;
                                                                                
m_outputheaderfile = "extmanager.h";
m_outputsourcefile = "extmanager.cpp";
};
