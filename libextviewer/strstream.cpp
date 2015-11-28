// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;

#include "extensionlib.h"

void strupcase( string &source)
{
std::transform(
    source.begin(),
    source.end(),
    source.begin(),
    std::ptr_fun <int, int> ( std::toupper )
    );
}

void strlowercase( string &source)
{
std::transform(
    source.begin(),
    source.end(),
    source.begin(),
    std::ptr_fun <int, int> ( std::tolower )
    );
}



bool ReadStream( ifstream &stream, string &strdata, int length )
{
strdata.clear();
strdata.reserve(length);

stream.read( (char *) strdata.data(), length );

strdata[length] = '\0';

return true;
}

bool ReadStream( string &strdata, string &strpath )
{
struct stat statbuf;
ifstream stream;
int res;

res = stat( strpath.data(), &statbuf );

if ( res == -1 )
        {
        strdata.clear();
        return false;
        }

stream.open( strpath.data(), ios::in );

strdata.reserve(statbuf.st_size+10);

if ( stream.is_open() )
        {
        ReadStream( stream, strdata, statbuf.st_size );

        stream.close();

        return true;
        }

return(0);
}

bool WriteStream( ofstream &stream, const string &strdata )
{
stream.write( strdata.data(), strdata.length() );

return true;
}

bool WriteStream( const string &strdata, const string &strpath )
{
ofstream stream;

stream.open( strpath.data() );

if ( stream.is_open() )
        {
        WriteStream( stream, strdata );

        stream.close();

        return true;
        }

return false;
}

bool WriteStream( const char *pdata, const string &strpath, int nbytes )
{
ofstream stream;

stream.open( strpath.data(), ios::binary );

if ( stream.is_open() )
	{
	stream.write( pdata, nbytes );

	stream.close();

	return true;
	}

return false;
}

