// --------------------------------------------------------------------------
// File:   io_byte.h
//
// Purpose: Routines to handle byteenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_LONG_H_
#define _IO_LONG_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemLong : virtual public CFileSystemPar,
			virtual public CFileSystemString
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

void ReadLong( ifstream &stream, long &ivalue )
	{
	string buffer;

	ReadString( stream, buffer );

	if ( buffer.c_str()[0] == '0' )
        	{
        	if ( (buffer.c_str()[1] == 'x' ) || 
			(buffer.c_str()[1] == 'X' ) )
                	sscanf( buffer.c_str(), "%lx", &ivalue );
        	else
                	sscanf( buffer.c_str(), "%lo", &ivalue );
        	}
	else
       		{
        	sscanf( buffer.c_str(), "%ld", &ivalue );
        	}
	}


// ----- Write routines -----------------------------------------------------

// ----- Integer matrices ----------------------------------------------------

inline void WriteLong( ostream &stream, long value )
	{
	stream << value;
	}

inline void WriteNamedLong( ostream &stream, int depth, string &strname,
                                                long value )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << strname.c_str() << " " << value << " }\n";
	}

inline void WriteNamedLong( ostream &stream, int depth, const char *name,
                                                long value )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << name << " " << value << " }\n";
	}

};


#endif	// _IO_LONG_H_
