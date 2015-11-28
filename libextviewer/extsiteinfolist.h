// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _EXTSITEINFOLIST_H_
#define _EXTSITEINFOLIST_H_

#include <iostream>
#include <algorithm>
#include <vector>

#define MODE_UPDATEREGISTRY 0x0001      // Update the registry
#define MODE_UPDATEHEADERS  0x0002      // Update the header files
#define MODE_READREGISTRY   0x0004      // Read the registry
#define MODE_READHEADERS    0x0008      // Read the header files
#define MODE_IGNORETHESE    0x0010      // Ignore the extensions

// --------------------------------------------------------------------------
// Define the class used to represent a list of site info
// --------------------------------------------------------------------------
                                                                                
class CExtensionSiteInfoList : virtual public CExtensionSiteInfoListIO
{
public:
CExtensionSiteInfo m_curitem;
int 		   m_curitemactive;
int 		    m_updatemode;
                                                                                
// ----- Constructor and destructor -----------------------------------------
                                                                                
CExtensionSiteInfoList( void )
        {
	Init();
        };
                                                                                
// ----- Functions and procedures -------------------------------------------
                                                                                
void Init( void )
        {
	m_curitemactive = 0;
	m_updatemode = MODE_UPDATEREGISTRY|MODE_UPDATEHEADERS
       	             | MODE_READREGISTRY|MODE_READHEADERS;
        };
                                                                                
void Deallocate( void )
	{
	clear();
	}

void Duplicate( CExtensionSiteInfoList &infolist )
	{
	clear();
	CExtensionSiteInfo item;

	for ( unsigned int pn = 0; pn < infolist.size(); pn++ )
		{
		item = infolist.at(pn);
		push_back( item);
		}

	m_updatemode = infolist.m_updatemode;
	m_curitemactive = 0;
	};

void Delete( unsigned int pos )
	{
	erase( begin() + pos );
	}

void Begin( void )
        {
        if ( 0 == m_curitemactive)
                {
		m_curitemactive = 1;
                }
        };
                                                                                
void Begin( const char *name )
        {
        if ( 0 == m_curitemactive)
                {
                m_curitem.SetInfo( INFO_DESCRIPTION, name );
		m_curitemactive = 1;
                }
        };
                                                                                
void End( void )
        {
        if ( 1 == m_curitemactive )
                {
		push_back( m_curitem );
		m_curitemactive = 0;	
                }
        };
                                                                                
void SetItem( int item, const char *pinfo )
        {
        if ( 1 == m_curitemactive )
		{
                m_curitem.SetInfo( item, pinfo );
		}
        };

void SetFlags( int flags )
	{
	if ( 1 == m_curitemactive )
		{
		m_curitem.SetFlags( flags );
		}
	};                                                                                

CExtensionSiteInfo *GetSiteInfo( unsigned int site )
        {
	if ( site >= size() )
		{
		return( NULL );
		}
	else
		{
        	return( &at(site) );
		}
        };

int FindExtensionLocalPath( unsigned int site, 	
			string &pextpath,
			string &pextname )
	{
	if ( site < size() )
		{
		return( at(site).FindExtensionLocalPath(pextpath, pextname) ); 	
		}

	return(0);
	}

int FindSite( string &path )
	{
	for ( unsigned int site = 0; site < size(); site++ )
		{
		if ( at(site).m_description == path )
			{
			return site;
			}
		}

	return -1;
	}

int FindExtensionLocalPath( string &pextpath,
			    string &pextname )
	{
	for ( unsigned int site = 0; site < size(); site++ )
		{
		if ( at(site).GetFlags( FLAG_READEXTENSIONSPEC ) )
			{
			if ( FindExtensionLocalPath( site, pextpath, pextname ) )
				{
				return( 1 );
				}
			}
		}

	return(0);
	}                                                                                
int FindRegistryExtensionPathIndex( unsigned int site,
			const string &regbuf,
			string &pextname,
			string &pextpath,
                       	int index )
	{
	if ( site < size() )
		{
		return( at(site).FindRegistryExtensionPathIndex(
			regbuf, pextname, pextpath, index ) ); 
		}
	}

int GetCount( void )
	{
	return size();
	}

void DumpData( void )
	{
	cout << "List Dump Data ---------------------------------" << endl;

	for ( unsigned int pos = 0; pos < size(); pos++ )	
		{
		at(pos).DumpData();
		}

	cout << "------------------------------------------------" << endl;
	}

int WebsiteMatch( CExtensionSiteInfo &info );

void WebsiteInit( void );

// ----- Update mode --------------------------------------------------------
                                                                                
void SetUpdateMode( int mode )
        {
        m_updatemode = mode;
        };
                                                                                
int GetUpdateMode( void )
        {
        return m_updatemode;
        };
};

#endif 	/* _EXTSITEINFOLIST_H_ */
