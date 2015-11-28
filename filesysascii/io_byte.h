// --------------------------------------------------------------------------
// File:   io_byte.h
//
// Purpose: Routines to handle byte data
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_BYTE_H_
#define _IO_BYTE_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemByte : virtual public CFileSystemPar,
			virtual public CFileSystemString
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

void ReadByte( ifstream &stream, BYTE &ivalue )
	{
	string buffer;
	int bvalue;

	ReadString( stream, buffer );

	if ( buffer.c_str()[0] == '0' )
        	{
        	if ( ( buffer.c_str()[1] == 'x' ) || (buffer.c_str()[1] == 'X' ) )
                	sscanf( buffer.c_str(), "%hhx", &ivalue );
        	else
                	sscanf( buffer.c_str(), "%hho", &ivalue );
        	}
	else
        	{
        	sscanf( buffer.c_str(), "%d", &bvalue );
        	ivalue = bvalue;
        	}
	}

// ----- Write routines -----------------------------------------------------

// ----- Byte data ---------------------------------------------------------

void WriteByte( ostream &stream, bool value )
	{
	stream << value;
	}

void WriteNamedByte( ostream &stream, unsigned int depth, const char *name,
                                                        BYTE value )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << name << " " << value << " }\n";
	}


void WriteNamedByte( ostream &stream, unsigned int depth, string &strname,
                                                        BYTE value )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << strname.c_str() << " " << value << " }\n";
	}

};

#endif	// _IO_BYTE_H_
