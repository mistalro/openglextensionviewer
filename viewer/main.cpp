// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "viewer.h"

int main( int argc, char **argv )
{
QApplication a( argc, argv );
CMainWindowDialog w;

a.setStyle( QString( "Plastik" ) );

w.show();
a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );

return a.exec(); 
}
