// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _STRSTREAM_H_
#define _STRSTREAM_H_

void strupcase( string &source);
void strlowercase( string &source);

bool ReadStream( ifstream &stream, string &strdata, int length );
bool ReadStream( string &strdata, string &strpath );

bool WriteStream( ofstream &stream, const string &strdata );
bool WriteStream( const string &strdata, const string &strpath );
bool WriteStream( const char *pdata, const string &strpath, int nbytes );

#endif
