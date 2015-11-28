// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;

#include "extensionlib.h"

// --------------------------------------------------------------------------
// Utility function for rotating a 32-bit integer
//
// Inputs: None
//
// Outputs: None
//
// Results: The rotated integer
//
// Effects: None
// --------------------------------------------------------------------------

unsigned int RotateBits( unsigned int value, int shift )
{
int bit;
                                                                                
while ( shift > 0 )
        {
        bit = value & 0x01;
                                                                                
        value >>= 1;
        value  |= bit << 31;
        shift--;
        }
                                                                                
while ( shift < 0 )
        {
        bit = (value >> 31) & 0x01;
                                                                                
        value <<= 1;
        value  |= bit;
        shift++;
        }
                                                                                
return( value );
}
