// --------------------------------------------------------------------------
// File:   io_byte.h
//
// Purpose: Routines to handle byteenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_BOOL_H_
#define _IO_BOOL_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemBoolean : virtual public CFileSystemPar,
			virtual public CFileSystemString,
			virtual public CFileSystemInteger
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

inline void ReadBool( std::ifstream &stream, bool &ivalue )
	{
	std::string buffer;
	int temp;

	ReadString( stream, buffer );

	if ( buffer.c_str()[0] == '0' )
        	{
        	if ( ( buffer.c_str()[1] == 'x' ) || (buffer.c_str()[1] == 'X' ) )
                	sscanf( buffer.c_str(), "%x", &temp );
        	else
                	sscanf( buffer.c_str(), "%o", &temp );
        	}
	else
        	{
        	sscanf( buffer.c_str(), "%d", &temp );
        	}

	ivalue = temp;
	}

// ----- Write routines -----------------------------------------------------

void WriteBool( std::ofstream &stream, bool value )
	{
	stream << value;
	}

void WriteNamedBool( std::ofstream &stream, int depth, const char *name,
                                                        bool value )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << name << " " << value << " }\n";
	}

void WriteNamedBool( std::ofstream &stream, int depth, std::string &strname,
                                                        bool value )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << strname.c_str() << " " << value << " }\n";
	}
};

#endif	// _IO_BOOL_H_
