// --------------------------------------------------------------------------
// File:    filesysascii.h
//
// Purpose: Main interface header file for the file I/O system in Ascii
//
// Author:  Michael S. A. Robb
//
// Date:    30th July 2005
// --------------------------------------------------------------------------

#ifndef _FILEIOLIB_H_
#define _FILEIOLIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

extern int g_verbose;

typedef unsigned char BYTE;

#include "tokenentry.h"

#include "io_par.h"
#include "io_string.h"

#include "io_byte.h"
#include "io_bytearray.h"

#include "io_integer.h"
#include "io_intarray.h"

#include "io_bool.h"
#include "io_boolarray.h"

#include "io_short.h"
#include "io_shortarray.h"

#include "io_long.h"
#include "io_longarray.h"

#include "io_float.h"
#include "io_floatarray.h"

#include "io_double.h"
#include "io_doublearray.h"

// ------ Main header files -----

#include "io_system.h"

#include "virtualfsascii.h"

#endif	// _FILEIOLIB_H_
