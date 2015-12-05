// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include <cstdio>
#include <cstdlib>
#include <string>
#include <unistd.h>

#include "string.h"

// --------------------------------------------------------------------------
// Replacements for 'string' class
// --------------------------------------------------------------------------

void stl_strupr( std::string &str )
{
for (unsigned int pn = 0; pn < str.length(); pn++ )
        {
        str.at(pn) = toupper( str.at(pn) );
        }
}

void stl_strlwr( std::string &str )
{
for (unsigned int pn = 0; pn < str.length(); pn++ )
        {
        str.at(pn) = tolower( str.at(pn) );
        }
}

void stl_hostname( std::string &str )
{
char buffer[128];

gethostname( buffer, 128 );

str = std::string(buffer);
}

void stl_strdel( std::string &str, int delch )
{
std::string newstr;
int pn, len, ch;

len = str.length();

for ( pn = 0 ;pn < len; pn++ )
	{
	ch = str.at(pn);

	if ( ch != delch )
		{
		newstr += ch;
		}
	}

str = newstr;
}	

void stl_getusername( std::string &str )
{
str= getenv( "USER");
}

void stl_getcwd( std::string &str )
{
char buffer[1024];

getcwd( buffer,1023);

str = buffer;
}

void stl_itoa( std::string &str, int value )
{
char buffer[64];

sprintf( buffer, "%3d", value );

str = buffer;
}

// --------------------------------------------------------------------------
// Convert an entire std::string to upper case
// --------------------------------------------------------------------------

void strupr( char *chptr )
{
while (*chptr != 0 )
        {
        *chptr = toupper(*chptr);
        chptr++;
        }
}

// --------------------------------------------------------------------------
// Convert an entire std::string to lower case
// --------------------------------------------------------------------------

void strlwr( char *str )
{
while (*str )
        {
        *str = tolower(*str);
        str++;
        }
}

// --------------------------------------------------------------------------
// Delete the selected character from the std::string
// --------------------------------------------------------------------------

int strdel( char *str, char chdel )
{
int src, dst;
                                                                             
src = 0;
dst = 0;
                                                                             
while ( str[src] != '\0' )
    {
    if ( str[src] != chdel )
        str[dst++] = str[src];
                                                                             
    src++;
    }
                                                                             
str[dst] = '\0';
                                                                             
return(src);
}

// --------------------------------------------------------------------------
// Convert a HTTP path to a file path
// --------------------------------------------------------------------------

void ExtractServerPath( char *fullpath, char *server, char *path )
{
char *tptr = fullpath;

if ( strncmp( tptr, "http://", 7 ) == 0 )
    tptr += 7;

while (*tptr != '/' )
    *server++ = *tptr++;

*server = '\0';

while ( *tptr )
    *path++ = *tptr++;

*path = '\0';
}

