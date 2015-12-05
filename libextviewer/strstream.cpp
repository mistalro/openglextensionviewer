// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "extensionlib.h"

void strupcase( std::string &source)
{
std::transform(
    source.begin(),
    source.end(),
    source.begin(),
    std::ptr_fun <int, int> ( std::toupper )
    );
}

void strlowercase( std::string &source)
{
std::transform(
    source.begin(),
    source.end(),
    source.begin(),
    std::ptr_fun <int, int> ( std::tolower )
    );
}



bool ReadStream( std::ifstream &stream, std::string &strdata, int length )
{
strdata.clear();
strdata.reserve(length);

stream.read( (char *) strdata.data(), length );

strdata[length] = '\0';

return true;
}

bool ReadStream( std::string &strdata, std::string &strpath )
{
struct stat statbuf;
std::ifstream stream;

int res = stat( strpath.data(), &statbuf );

if ( res == -1 )
        {
        strdata.clear();
        return false;
        }

stream.open( strpath.data(), std::ios::in );

strdata.reserve(statbuf.st_size+10);

if ( stream.is_open() )
        {
        ReadStream( stream, strdata, statbuf.st_size );

        stream.close();

        return true;
        }

return(0);
}

bool WriteStream( std::ofstream &stream, const std::string &strdata )
{
stream.write( strdata.data(), strdata.length() );

return true;
}

bool WriteStream( const std::string &strdata, const std::string &strpath )
{
std::ofstream stream;

stream.open( strpath.data() );

if ( stream.is_open() )
        {
        WriteStream( stream, strdata );

        stream.close();

        return true;
        }

return false;
}

bool WriteStream( const char *pdata, const std::string &strpath, int nbytes )
{
std::ofstream stream;

stream.open( strpath.data(), std::ios::binary );

if ( stream.is_open() )
	{
	stream.write( pdata, nbytes );

	stream.close();

	return true;
	}

return false;
}

