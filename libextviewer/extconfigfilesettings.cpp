// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;
                                                                                
#include "extensionlib.h"
                                                                                
// --------------------------------------------------------------------------
// Initialiser
// --------------------------------------------------------------------------
                                                                                
void CConfigurationFileSettings::Init( void )
{
m_configfile          = "config.txt";
m_autoreadheaderflags = 0; // Use MODE_AUTOREADHEADERS to enable
m_autoloadconfigflags = MODE_AUTOLOADCONFIG;
m_autosaveconfigflags = MODE_AUTOSAVECONFIG;
}
