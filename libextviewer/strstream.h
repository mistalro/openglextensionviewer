// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _STRSTREAM_H_
#define _STRSTREAM_H_

void strupcase( std::string &source);
void strlowercase( std::string &source);

bool ReadStream( std::ifstream &stream, std::string &strdata, int length );
bool ReadStream( std::string &strdata, std::string &strpath );

bool WriteStream( std::ofstream &stream, const std::string &strdata );
bool WriteStream( const std::string &strdata, const std::string &strpath );
bool WriteStream( const char *pdata, const std::string &strpath, int nbytes );

#endif
