// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------
                                                                                
#include "extensionlib.h"
                                                                                
// --------------------------------------------------------------------------
// Check for a match between the different websites
// --------------------------------------------------------------------------
                                                                                
int CExtensionSiteInfoList::WebsiteMatch( CExtensionSiteInfo &info )
{
for (unsigned int pos = 0; pos < size(); pos++ )
	{
        if ( at(pos).WebsiteMatch( info ) )
		{
                return( true );
		}
        }                                                                        
return( false );
}

// --------------------------------------------------------------------------
// Initialise with default websites
// --------------------------------------------------------------------------

void CExtensionSiteInfoList::WebsiteInit( void )
{
// ----- Site lists ---------------------------------------------------------

clear();
}

