// --------------------------------------------------------------------------
// File:   io_byte.h
//
// Purpose: Routines to handle byteenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_INTEGER_H_
#define _IO_INTEGER_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemInteger : virtual public CFileSystemPar,
			virtual public CFileSystemString
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

void ReadInteger( ifstream &stream, int &ivalue )
	{
	string buffer;

	ReadString( stream, buffer );

#ifdef DEBUG
	cout << "***** " << buffer.c_str() << " *****\n";
#endif

	if ( buffer.c_str()[0] == '0' )
        	{
        	if ( ( buffer.c_str()[1] == 'x' ) || 
			(buffer.c_str()[1] == 'X' ) )
                	sscanf( buffer.c_str(), "%x", &ivalue );
        	else
                	sscanf( buffer.c_str(), "%o", &ivalue );
        	}
	else
		{
        	sscanf( buffer.c_str(), "%d", &ivalue );
		}
	}


// ----- Write routines -----------------------------------------------------

// ----- Integer data -------------------------------------------------------

void WriteInteger( ostream &stream, int value )
	{
	stream << value << " ";
	}

void WriteNamedInteger( ostream &stream, int depth, const char *pname,
                                                        int value )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << pname << " " << value << " }\n";
	}

void WriteNamedInteger( ostream &stream, int depth, string &strname,
                                                        int value )	
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << strname.c_str() << " " << value << " }\n";
	}

};

#endif	// _IO_INTEGER_H_
