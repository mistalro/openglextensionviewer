// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _SOCKETSTREAM_
#define _SOCKETSTREAM_

#include <fcntl.h>
#include <sys/io.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define STREAM_BUFFER 1024

// --------------------------------------------------------------------------
// The CSocketStream class
// --------------------------------------------------------------------------

class CSocketStream
{
public:
int  m_socketid;                // Which socket
char *m_pbuffer;                // Buffer
int  m_bufmax;                  // Maximum size
int  m_bufpos;                  // Current position
int  m_bufnum;                  // Number of items in buffer
int  m_bufleft;                 // Number of items left
// ----- Constructor and destructor -----------------------------------------
                                                                                
CSocketStream( void ) { Init(); };
~CSocketStream( void ) { Deallocate(); };
                                                                                
// ----- Functions and procedures -------------------------------------------
                                                                                
void SetSocket( int sockid ) { m_socketid = sockid; };

void Deallocate( void ) { };                                                                                
void Init( void )
        {
        m_socketid = -1;
        m_bufmax = STREAM_BUFFER;
        m_bufpos = 0;
        m_bufnum = 0;
        m_bufleft = 0;
        m_pbuffer = new char[m_bufmax];
        }
                                                                                
void ReadBuffer( void )
        {
        m_bufnum = recv( m_socketid, m_pbuffer, m_bufmax, 0 );
        m_bufpos = 0;
        m_bufleft = m_bufnum;
        }
                                                                                
int GetChar( void )
        {
        int result;
                                                                                
        if (m_bufleft == 0 )
                ReadBuffer();
                                                                                
        result = m_pbuffer[m_bufpos];
        m_bufpos++;
        m_bufleft--;
                                                                                
        return( result );
        }
                                                                                
int GetString( char *pstring, int bufmax )
        {
        int done = 0;
        int len = 0;
                                                                                
        while ( !done )                 // While no \n character received
                {
                                        // While characters remaining
                while ( m_bufleft && (len < bufmax) && !done )
                        {
                        *pstring = m_pbuffer[m_bufpos]; // Copy char
                                                                                
                        if (*pstring == '\n' )  // Newline?
                                done++;         // So finished
                                                                                
                        m_bufpos++;             // Increment position
                        m_bufleft--;            // Decrement remaining chars
                                                                                
                        len++;                  // Increment length
                                                                                
                        if (len==bufmax)
                                done++;
                                                                                
                        pstring++;              // Update destination string
                        }
                                                                                
                if ( !done && (!m_bufleft) )    // Not finished and no data?
                        ReadBuffer();           // Refresh buffer
                }
                                                                                
        *pstring = '\0';                        // Terminate string
                                                                                
        return(len);
        }
                                                                                
int FlushBuffer( char *ptr )
        {
        int result = m_bufleft;
                                                                                
        memcpy( ptr, m_pbuffer+m_bufpos, m_bufleft );
        m_bufleft = 0;
        m_bufpos += m_bufleft;
                                                                                
        return( result );
        }

void Close( void )
	{
	close( m_socketid );
	}
};


#endif
