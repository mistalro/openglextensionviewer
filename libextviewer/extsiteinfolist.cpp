// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;
                                                                                
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
#ifdef DEBUG
// ----- SGI website --------------------------------------------------------

Begin( "SGI registry" );
SetItem( INFO_INDEXPAGELOCAL, "index.html" );
SetItem( INFO_INDEXPAGENET, "http://oss.sgi.com/projects/ogl-sample/registry/index.html" );
SetItem( INFO_INDEXDIRLOCAL, "registry" );

SetItem( INFO_GLHEADERNET,   "http://oss.sgi.com/projects/ogl-sample/ABI/glext.h" );
SetItem( INFO_GLHEADERLOCAL, "registry/glext.h" );

SetItem( INFO_GLXHEADERNET,  "http://oss.sgi.com/projects/ogl-sample/ABI/glxext.h" );
SetItem( INFO_GLXHEADERLOCAL, "registry/glxext.h" );

SetItem( INFO_WGLHEADERNET,  "http://oss.sgi.com/projects/ogl-sample/ABI/wglext.h" );
SetItem( INFO_WGLHEADERLOCAL, "registry/wglext.h" );

SetFlags( FLAG_DOWNLOADHEADERFILES );
SetFlags( FLAG_DOWNLOADREGISTRY );
SetFlags( FLAG_READHEADERFILES);
SetFlags( FLAG_READEXTENSIONSPEC );
End();

// ----- NVIDIA website -----------------------------------------------------

Begin( "nVidia registry" );
SetItem( INFO_INDEXPAGELOCAL, "index.html" );
SetItem( INFO_INDEXPAGENET, "http://developer.nvidia.com/object/nvidia_opengl_specs.html" );
SetItem( INFO_INDEXDIRLOCAL, "nvidia" );

SetItem( INFO_GLHEADERNET, "http://cvs1.nvidia.com/inc/GL/glext.h" );
SetItem( INFO_GLHEADERLOCAL, "nvidia/glext.h" );

SetItem( INFO_GLXHEADERNET, "http://cvs1.nvidia.com/inc/GL/glxext.h" );
SetItem( INFO_GLXHEADERLOCAL, "nvidia/glxext.h" );

SetItem( INFO_WGLHEADERNET, "http://cvs1.nvidia.com/inc/GL/wglext.h" );
SetItem( INFO_WGLHEADERLOCAL, "nvidia/wglext.h" );

SetFlags( FLAG_DOWNLOADHEADERFILES );
SetFlags( FLAG_DOWNLOADREGISTRY );
SetFlags( FLAG_READHEADERFILES);
SetFlags( FLAG_READEXTENSIONSPEC );
End();

// ----- ATI website ----------------------------------------------------

Begin( "ATI registry" );
SetItem( INFO_INDEXPAGELOCAL, "index.html" );

SetItem( INFO_INDEXPAGENET, "http://www.ati.com/developer/sdk/radeonSDK/html/info/Prog3D.html" );
SetItem( INFO_INDEXDIRLOCAL, "ati" );

SetItem( INFO_GLHEADERNET, "http://www.ati.com/developer/sdk/RADEONSDK/Html/Info/Extensions/glATI.h" );
SetItem( INFO_GLHEADERLOCAL, "ati/glATI.h" );

SetItem( INFO_GLXHEADERNET, "http://www.ati.com/developer/sdk/RADEONSDK/Html/Info/Extensions/glxATI.h" );
SetItem( INFO_GLXHEADERLOCAL, "ati/glxATI.h" );

SetItem( INFO_WGLHEADERNET, "http://www.ati.com/developer/sdk/RADEONSDK/Html/Info/Extensions/wglATI.h" );
SetItem( INFO_WGLHEADERLOCAL, "wglATI.h" );

SetFlags( FLAG_DOWNLOADHEADERFILES );
SetFlags( FLAG_DOWNLOADREGISTRY );
SetFlags( FLAG_READHEADERFILES);
SetFlags( FLAG_READEXTENSIONSPEC );
End();
#endif
}

