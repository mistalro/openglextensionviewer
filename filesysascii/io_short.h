// --------------------------------------------------------------------------
// File:   io_byte.h
//
// Purpose: Routines to handle byteenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_SHORT_H_
#define _IO_SHORT_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemShort : virtual public CFileSystemPar,
			virtual public CFileSystemString
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

inline void ReadShort( ifstream &stream, short &ivalue )
	{
	string buffer;

	ReadString( stream, buffer );

	if ( buffer.c_str()[0] == '0' )
        	{
        	if ( ( buffer.c_str()[1] == 'x' ) || (buffer.c_str()[1] == 'X' ) )
                	sscanf( buffer.c_str(), "%hx", &ivalue );
        	else
                	sscanf( buffer.c_str(), "%ho", &ivalue );
        	}
	else
        	sscanf( buffer.c_str(), "%hd", &ivalue );
	}

// ----- Write routines -----------------------------------------------------

// ----- Short data -------------------------------------------------------

inline void WriteShort( ostream &stream, short value )
	{
	stream << " " << value;
	}

inline void WriteNamedShort( ostream &stream, int depth, const char *name,
                                                        short value )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << name << " " << value << " }\n";
	}

inline void WriteNamedShort( ostream &stream, int depth, string &strname,
                                                        short value )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << strname.c_str() << " " << value << " }\n";
	}
};

#endif	// _IO_SHORT_H_
