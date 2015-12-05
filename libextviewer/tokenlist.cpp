// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "tokenlist.h"

#define MIN(A,B)   (((A)<(B)) ? (A) : (B) )

static int SortProcName( CToken const &tokena, CToken const &tokenb )
        {
        return strcmp( tokena.m_name.data(), tokenb.m_name.data() );
        };

static int SortProcNameReversed( CToken const &tokena, CToken const &tokenb )
        {
        return -strcmp( tokena.m_name.data(), tokenb.m_name.data() );
        };

static int SortProcCount( CToken const &tokena, CToken const &tokenb )
        {
        return tokenb.m_tokencount - tokena.m_tokencount;
        };

static int SortProcCountReversed( CToken const &tokena, CToken const &tokenb )
        {
        return tokena.m_tokencount - tokenb.m_tokencount;
        };


void CTokenList::TokenToggleSortmode( int mode )
        {
        if ( (mode & ~TOKEN_SORTREVERSED) == m_sortmode )
		{
                m_sortmode ^= TOKEN_SORTREVERSED;
		}
        else
		{
                m_sortmode = mode;
		}
        }

void CTokenList::TokenSort( void )
        {
	CToken *pbase = &at(0);

        switch ( m_sortmode )
                {
                case TOKEN_SORTNAME:
			QuickSort( pbase, size()-1, SortProcName);
                        break;

                case TOKEN_SORTVALUE:
			QuickSort( pbase, size()-1, SortProcCount);
                        break;

                case TOKEN_SORTNAMEREVERSED:
			QuickSort( pbase, size()-1, SortProcNameReversed);
                        break;

                case TOKEN_SORTVALUEREVERSED:
			QuickSort( pbase, size()-1, SortProcCountReversed);
                        break;

                default:
                        break;
                }
        }

void CTokenList::TokenAdd( const char *name, int tokenid )
        {
        CToken token( name, tokenid );

        push_back( token );
        };

CToken *CTokenList::TokenFind( const std::string &name )
        {
        for ( unsigned int pn = 0; pn < size(); pn++ )
        {
                if ( at(pn).Compare( name ) )
                {
                        return &at(pn);
                }
        }

        return NULL;
        };

CToken *CTokenList::TokenFind( int tokenid )
        {
        for ( unsigned int pn = 0; pn < size(); pn++ )
                {
                if ( at(pn).m_tokenid == tokenid )
                        {
                        return &at(pn);
                        }
                }

        return NULL;
        };


void CTokenList::ResetCount( void )
        {
        for ( unsigned int pn = 0; pn < size(); pn++ )
                {
                at(pn).ResetCount();
                }
        }

void CTokenList::WriteStats(const std::string &path)
	{
        std::ofstream stream;

        stream.open( path.data() );

        if ( stream.is_open() )
                {
                for ( unsigned int pn = 0; pn < size(); pn++ )
                        {
                        stream << at(pn).m_name << " - " << at(pn).m_tokencount;
                        }

                stream.close();
                }
	}
