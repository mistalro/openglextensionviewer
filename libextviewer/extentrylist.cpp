// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "extensionlib.h"

// --------------------------------------------------------------------------
// Initialise the CExtensionEntryList class
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The object is initialised
// --------------------------------------------------------------------------

void CExtensionEntryList::Init( void )
{
m_sortmode = 0;
};

// --------------------------------------------------------------------------
// Find name that matches std::string
//
// Inputs: pname - The name to find
//
// Outputs: None
//
// Results: Negative if no match was found, Non-negative otherwise
//
// Effects: None
// --------------------------------------------------------------------------

int CExtensionEntryList::FindName(const std::string &pname )
{
int pn = 0, found = -1;

if(pname.length() == 0)
	{
	return -1;
	}

for ( iterator it = begin(); it != end() && (found==-1); it++, pn++ )
	{
    	if ( strcmp( it->m_name.data(), pname.data() ) == 0 )
		{
       		found = pn;
		}
	}

return found;
}

// --------------------------------------------------------------------------
// Find full name that matches std::string
//
// Inputs:  pname - Pointer to character std::string of name
//
// Outputs: None
//
// Results: Negative if no match could be found, Non-negative otherwise
//
// Effects: None
// --------------------------------------------------------------------------

int CExtensionEntryList::FindFullName( const char *pname )
{
int pn = 0, found = -1;

for (vector <CExtensionEntry>::iterator it = begin(); it != end() && (found == -1); it++, pn++ )
	{
    	if ( strstr( at(pn).m_name.data(), pname ) != NULL )
		{
        	found = pn;
		}
	}
    
return found;
};

// --------------------------------------------------------------------------
// Find value that matches std::string
//
// Inputs:  pvalue - Pointer to the character std::string representing the name
//
// Outputs: None
//
// Results: Negative if no match cound be found, Non-negative otherwise
//
// Effects:
// --------------------------------------------------------------------------

int CExtensionEntryList::FindValue(const char *pvalue )
{
int pn = 0, found = -1;

for (iterator it = begin(); it != end() && (found == -1); it++, pn++ )
	{
    	if ( it->m_value == pvalue )
		{
        	found = pn;
		}
	}
    
return found;
};

// --------------------------------------------------------------------------
// Find the matching procedure name
//
// Inputs:  pproc - Pointer to the procedure name
//
// Outputs: None
//
// Results: Negative if no match could be found, non-negative otherwise
//
// Effects: None
//
// Notes:   Searching backwards fixed a bug when sets of two registry header 
//          files are being read. If a forward search is implemented, then
//          the second set of functions are missed, causing gaps in the table
// --------------------------------------------------------------------------

int CExtensionEntryList::FindProc( const std::string &pproc )
{
int found = -1;

for ( int pn = size()-1; (pn>= 0) && (found==-1); pn-- )
	{
	if ( strcmp( at(pn).m_pfnproc.data(), pproc.data() ) == 0 )
		{
        	found = pn;
		}
	}
    
return found;
};

// --------------------------------------------------------------------------
// Add an item to the list
//
// Inputs:  name - Pointer to the name std::string
//
// Outputs: None 
//
// Results: Index value of the new item in the list
//
// Effects: The item is added to the list
// --------------------------------------------------------------------------

int CExtensionEntryList::Add( const char *name )
{
int pn = 0, found = -1;
CExtensionEntry entry;

for (iterator it = begin(); it != end() && (found == -1); it++)
	{
	if ( strcmp( it->m_name.data(), name ) == 0 )
		{
		found++;

		return pn;
		}
   	}
 
#ifdef DEBUG
cout << "ExtensionEntryList adding |" << name << "|\n";
#endif

entry.m_name = name;
entry.m_constnum = 0;
entry.m_funcnum = 0;

#ifdef DEBUG
cout << "Entry name = |" << entry.m_name << "|\n";
#endif

push_back(entry);

return size()-1;
};

int CExtensionEntryList::Add( const std::string &name )
{
int pn = 0, found = -1;
CExtensionEntry entry;

for (iterator it = begin(); it != end() && (found == -1); it++, pn++ )
	{
    	if ( strcmp( at(pn).m_name.data(), name.data() ) == 0 )
		{
        	found++;

        	return pn;
		}
	}

if ( found == -1 )
	{
	entry.m_name = name;
	entry.m_constnum = 0;
	entry.m_funcnum = 0;

	push_back(entry);
	}
                                                                               
return size()-1;
};
                                                                               
// --------------------------------------------------------------------------
// Add the selected item, with the specified function and constant start
// positions
//
// Inputs:  name       - Pointer to the character std::string
//          funcstart  - Starting index for the function list
//          conststart - Starting index for the constant list
//
// Outputs: None
//
// Results: Index position of the new item
//
// Effects: The selected item is added to the list
// --------------------------------------------------------------------------

int CExtensionEntryList::AddStart( const std::string &name, 
				int funcstart, int conststart )
{
int pn = 0, found = -1;
CExtensionEntry entry;

for (iterator it = begin(); it != end() && (found == -1); it++, pn++ )
	{
    	if ( strcmp( it->m_name.data(), name.data() ) == 0 )
		{
       		found++;
		}
	}
    
if ( found== -1 )
	{
	entry.m_name = name;
	entry.m_constnum = 0;
	entry.m_funcnum = 0;
	entry.m_conststart = conststart;
	entry.m_funcstart = funcstart;
	
	push_back(entry);
	}

return size()-1;
};

// --------------------------------------------------------------------------
// Add the selected name and value
//
// Inputs: name - Pointer to the name
//         value - Pointer to the value
//
// Outputs: None
//
// Results: None
//
// Effects: The selected item is added to the list
//
// Notes:   Name and Value can either be:
// 
//          (1)  #define <name>  <value>    OR
//          (2)  PFNG****PROC  with long parameter list
// --------------------------------------------------------------------------

int CExtensionEntryList::AddNameValue( const char *name, const char *value )
{
int found;
CExtensionEntry entry;

found = FindProc( name );

if ( found == -1 )
	{
	entry.SetNameValue( name, value );
	push_back(entry);
	found = size()-1;
	}

return found;
}

// --------------------------------------------------------------------------
// Add the selected prefix, name and header
//
// Inputs:  prefix - Pointer to prefix
//          name   - Pointer to name
//          header - Pointer to header
//
// Outputs: None
//
// Results: The index position of the new item in the list
//
// Effects: The selected items are added to the list
// --------------------------------------------------------------------------

int CExtensionEntryList::AddPrefixNameValue( const char *prefix, 
				const char *name, const char *header )
{
int found;
CExtensionEntry entry;

found = FindProc( name );

if ( found == -1 )
	{
	entry.SetPrefixNameValue( prefix, name, header );	
	push_back(entry);

	found = size()-1;
	}

return found;
}

// --------------------------------------------------------------------------
// Add the prefix, name, header and prototype to the list
//
// Inputs:  prefix - Pointer to the prefix std::string
//          name   - Pointer to the name std::string 
//          header - Pointer to the header std::string
//          proto  - Pointer to the prototype
//
// Outputs: None
//
// Results: The index position of the item in the list
//
// Effects: The selected items are added to the list
// --------------------------------------------------------------------------

int CExtensionEntryList::AddPrefixNameValue( const std::string &prefix,
                                const std::string &name,
                                const std::string &header )
{
int found;
CExtensionEntry entry;

found = FindProc( name.data() );

if ( found == -1 )
	{
	entry.SetPrefixNameHeader( prefix, name, header );
	push_back(entry);

	found = size()-1;
	}

return found;
}

int CExtensionEntryList::AddPrefixNameValueProto( const std::string &prefix, 
				const std::string &name, const std::string &header, 	
				const std::string &proto )
{
int found;
CExtensionEntry entry;

found = FindProc( name );

if ( found == -1 )
	{
	entry.SetPrefixNameValueProto( prefix, name, header, proto );
	push_back(entry);
	found = size()-1;
	}

return found;
}

// --------------------------------------------------------------------------
// Set the value associated with the prototype std::string
//
// Inputs:  proc - Pointer to the procedure name
//          value - Pointer to the value std::string
//
// Outputs: None
//
// Results: None
//
// Effects: The value associated with the prototype std::string is set
// --------------------------------------------------------------------------

void CExtensionEntryList::AddProtoVars( const char *name,const char *value )
{
int found;
CExtensionEntry entry;

found = FindProc( name );

if ( found == -1 )
	{
	entry.m_name = name;

	if ( value != NULL )
		{
		entry.m_value = value;
		}

	push_back(entry);
	}
}

// --------------------------------------------------------------------------
// Delete the selected index from the list
//
// Inputs:   Index number of the entry to delete
//
// Outputs:  None
//
// Results:  None
//
// Effects:  The selected item is deleted from the list
// --------------------------------------------------------------------------

void CExtensionEntryList::DeleteIndex(unsigned int index )
{
if ( index < 0 || index >= size() )      // Sanity check
	{
    	return;
	}

erase(begin()+index);
}

// --------------------------------------------------------------------------
// Delete the selected extension name from the list
//
// Inputs:   pname - Pointer to the selected name to delete
//
// Outputs:  None
//
// Results:  Negative if no match could be found, non-negative otherwise
//
// Effects:  The selected item is deleted from the list
// --------------------------------------------------------------------------

int CExtensionEntryList::DeleteName( const std::string &name )
{
int find;

if (0 == name.size() )
	{
	return -1; 
	}

find = FindName( name );

if ( find != -1 )
	{
    	DeleteIndex( find );
	}

return find;
}

// --------------------------------------------------------------------------
// Delete the selected range of items from the list
// --------------------------------------------------------------------------

void CExtensionEntryList::DeleteRange( int start, int num )
{
erase(begin()+start, begin()+start+num-1);
}

// --------------------------------------------------------------------------
// Set the flags for all entries in the list
//
// Inputs:  mode - The value to set
//
// Outputs: None
//
// Results: None
//
// Effects: For all entries in the list, the selected flag is set
// --------------------------------------------------------------------------

void CExtensionEntryList::SetAllFlags( int mode )
{
for (iterator it = begin(); it != end(); it++ )
	{
    	it->EntrySetFlag( mode );
	}
}

// --------------------------------------------------------------------------
// Clear the flags for all entries in the list
//
// Inputs:  mode - Which mode 
//
// Outputs: None
//
// Results: None
//
// Effects: For all entries in the list, the selected flag is cleared
// --------------------------------------------------------------------------

void CExtensionEntryList::ClearAllFlags( int mode )
{
for ( iterator it = begin(); it != end(); it++ )
	{
    	it->EntryClearFlag( mode );
	}
}

// --------------------------------------------------------------------------
// Clear the selected flag for the selected name
//
// Inputs:  name - Pointer to the name std::string
//          mode - Flag to clear
//
// Outputs: None
//
// Results: Negative if no match can be found, non-zero otherwise
//
// Effects: None
// --------------------------------------------------------------------------

int CExtensionEntryList::ClearNameFlag( const std::string &name, int mode )
{
int find;

if ( (find = FindName( name ) ) != -1 )
	{
    	at(find).EntryClearFlag( mode ); 
	}

return find;
}

// --------------------------------------------------------------------------
// Get the value of the flag associated with the selected name
//
// Inputs:  name - Character pointer to the std::string to match
//          mode - The value of the flag to match
//
// Outputs: None
//
// Results: Negative if no match was made, non-negative otherwise
//
// Effects: None
// --------------------------------------------------------------------------

int CExtensionEntryList::GetNameFlag(const std::string &name, int mode )
{
int find;

if (name.size() == 0 )
	{
	return -1;
	}

if ( (find = FindName( name ) ) != -1 )
	{
    	return at(find).EntryGetFlag( mode );
	}

return -1;
}

// --------------------------------------------------------------------------
// Set the value of the flag associated with the selected name
//
// Inputs:  name - Character pointer to the std::string to match
//          flag - The value of the flag to match
//          
// Outputs: None
//
// Results: Negative if no match was made, non-negative otherwise
//
// Effects: If the name can be matched, the value of the flag is set
// --------------------------------------------------------------------------

int CExtensionEntryList::SetNameFlag(const std::string &name, int mode )
{
int find;

if ( (find = FindName( name ) ) != -1 )
	{
    	at(find).EntrySetFlag( mode );
	}

return find;
}

// --------------------------------------------------------------------------
// Set the value of the flag associated with the selected name
//
// Inputs:  name      - Pointer to the character std::string
//          flag      - Value of the flag to be set
//          matchmode - Which mode to match std::strings
//
//                 - MATCH_EXACTLY   - Exact std::string match 
// 		   - MATCH_BEGINNING - Match beginning of std::string
// 		   - MATCH_SUBSTRING - Match substring
//
// Outputs: None
//
// Results: Negative if no match could be found, non-negative otherwise
//
// Effects: If the name can be matched, then the value of the flag is set
//
// --------------------------------------------------------------------------

int CExtensionEntryList::SetFullNameFlag( const std::string &name, 
					int flag, int matchmode )
{
int find, pn;

find = -1;

switch ( matchmode )
	{
	case MATCH_EXACTLY:	// Strings must match exactly
		pn = 0;

		for ( iterator it = begin(); it != end(); it++, pn++ )
			{
			if ( it->m_name == name )
				{
    				it->EntrySetFlag( flag );
				find = pn;
				}
			}
		break;

	case MATCH_BEGINNING:	// Strings must match at beginning
		pn = 0;

		for ( iterator it = begin(); it != end(); it++, pn++ )
			{
			if ( strncmp( it->m_name.data(), name.data(), 
					name.length() ) == 0 )
				{
    				it->EntrySetFlag( flag );
				find = pn;
				}
			}
		break;

	case MATCH_SUBSTRING:	// Strings must match somewhere
		pn = 0;

		for ( iterator it = begin(); it != end(); it++, pn++ )
			{
			if ( strstr( it->m_name.data(), name.data() ) != NULL )
				{
    				it->EntrySetFlag( flag );
				find = pn;
				}
			}
		break;

	default:
		break;
	}

return find;
}

// --------------------------------------------------------------------------
// Clear the value of the flag associated with the selected name
//
// Inputs:  name      - Pointer to the character std::string
//          flag      - Value of the flag to be set
//          matchmode - Which mode to match std::strings
//
//                 - MATCH_EXACTLY   - Exact std::string match 
// 		   - MATCH_BEGINNING - Match beginning of std::string
// 		   - MATCH_SUBSTRING - Match substring
//
// Outputs: None
//
// Results: Negative if no match could be found, non-negative otherwise
//
// Effects: If the name can be matched, then the value of the flag is set
//
// --------------------------------------------------------------------------

int CExtensionEntryList::ClearFullNameFlag( const std::string &name, 
					int flag, int matchmode )
{
int find, pn;
                                                                                
find = -1;
                                                                                
switch ( matchmode )
        {
        case MATCH_EXACTLY:     // Strings must match exactly
		pn = 0;
		for ( iterator it = begin(); it != end(); it++, pn++ )
			{
                        if ( strcmp( it->m_name.data(), name.data() ) == 0 )
                                {
                                it->EntryClearFlag( flag );
                                find = pn;
                                }
			}
                break;
                                                                                
        case MATCH_BEGINNING:   // Strings must match at beginning
		pn = 0;
		for ( iterator it = begin(); it != end(); it++, pn++ )
			{
                        if ( strncmp( it->m_name.data(), name.data(),
                                       name.size() ) == 0 )
                                {
                                it->EntryClearFlag( flag );
                                find = pn;
                                }
			}
                break;
                                                                                
        case MATCH_SUBSTRING:   // Strings must match somewhere
		pn = 0;
		for ( iterator it = begin(); it != end(); it++, pn++ )
			{
                        if ( strstr( it->m_name.data(), name.data() ) != NULL )
                                {
                                it->EntryClearFlag( flag );
                                find = pn;
                                }
                        }
                break;
                                                                                
        default:
                break;
        }
                                                                                
return find;
}

// --------------------------------------------------------------------------
// Toggle the value of the flag associated with the selected name
//
// Inputs:  idno - Index of the entry to be matched
//          mode - Value of the flag to be set
//
// Outputs: None
//
// Results: Negative if no match could be found, non-negative otherwise
//
// Effects: If the name can be matched, then the value of the flag is set
// --------------------------------------------------------------------------

int CExtensionEntryList::ToggleNameFlag( const std::string &name, int mode )
{
int find;

if ( (find = FindName( name ) ) != -1 )
	{
    	at(find).EntryToggleFlag( mode );
	}

return find;
}

// --------------------------------------------------------------------------
// Set the value of the flag associated with the selected index
//
// Inputs:  idno - Index of the entry to be matched
//          mode - Value of the flag to be set
//
// Outputs: None
//
// Results: None
//
// Effects: The value of the flag is set
// --------------------------------------------------------------------------

void CExtensionEntryList::SetIndexFlag( unsigned int idno, int mode )
{
if ( (idno >= 0) && (idno < size()) )
	{
    	at(idno).EntrySetFlag( mode );
	}
}

// --------------------------------------------------------------------------
// Get the value of the flag associated with the selected index
//
// Inputs:  idno - Index of the entry to be matched
//          mode - Value of the flag to be set
//
// Outputs: None
//
// Results: None
//
// Effects: The value of the flag is set
// --------------------------------------------------------------------------

int CExtensionEntryList::GetIndexFlag( unsigned int idno, int mode )
{
if ( (idno >= 0) && (idno < size()) )
	{
    	return at(idno).EntryGetFlag( mode );
	}	

return false;
}

// --------------------------------------------------------------------------
// Clear the value of the flag associated with the selected index
//
// Inputs:  idno - Index of the entry to be matched
//          mode - Value of the flag to be set
//
// Outputs: None
//
// Results: None
//
// Effects: The value of the flag is cleared
// --------------------------------------------------------------------------

void CExtensionEntryList::ClearIndexFlag(unsigned int idno, int mode )
{
if ( (idno >= 0) && (idno < size()) )
	{
    	at(idno).EntryClearFlag( mode );
	}
}

// --------------------------------------------------------------------------
// Toggle the value of the flag associated with the selected index
//
// Inputs:  idno - Index of the entry to be matched
//          mode - Value of the flag to be set
//
// Outputs: None
//
// Results: None
//
// Effects: The value of the flag is toggled
// --------------------------------------------------------------------------

void CExtensionEntryList::ToggleIndexFlag( unsigned int idno, int mode )
{
if ( (idno >= 0) && (idno < size()) )
	{
    	at(idno).EntryToggleFlag( mode );
	}
}

// --------------------------------------------------------------------------
// Add items to the list from an extension std::string
//
// Inputs; pextstring - Pointer to the ASCII extension std::string
//
// Outputs: None
//
// Results: None
//
// Effects: The individual extensions are added to the list
// --------------------------------------------------------------------------

void CExtensionEntryList::AddExtensionString( const std::string &pextstring )
{
std::string tempbuf;
const char *ptemp;
                                                 
#ifdef DEBUG
cout << "||" << pextstring.data() << "||" << endl;
#endif

ptemp = pextstring.data();

if ( !ptemp )
	{
        return;
	}
           
while ( ptemp && (*ptemp != '\0') )
        {
        while ( isspace( *ptemp ) )
		{
                ptemp++;
		}
                
        if ( *ptemp )
                {
		tempbuf.clear();

                while (!isspace( *ptemp)  && (*ptemp != '\0') )
			{
                        tempbuf += *ptemp++;
			}

                Add( tempbuf );      // Add to system list
                }
        }
}

// --------------------------------------------------------------------------
// Remove items to the list from an extension std::string
//
// Inputs; pextstring - Pointer to the ASCII extension std::string
//
// Outputs: None
//
// Results: None
//
// Effects: The individual extensions are removed from the list
// --------------------------------------------------------------------------
                                                                                
void CExtensionEntryList::RemoveExtensionString( const std::string &extstring )
{
char tempbuf[1024];
int  bufpos;
const char *pextstring = extstring.data();
                                                                                
if ( extstring.length() == 0 )
	{
        return;
	}
                                                                                
while ( pextstring && (*pextstring != '\0') )
        {
        while ( isspace( *pextstring ) )
                pextstring++;
                                                                                
        if ( *pextstring )
                {
                bufpos = 0;
                                                                                
                while (!isspace( *pextstring)  && (*pextstring != '\0') )
                        tempbuf[bufpos++] = *pextstring++;                                                                                 
                tempbuf[bufpos] = '\0'; // Get extension std::string
                                                                                
                DeleteName( tempbuf ); // Add to system list
                }
        }
}

// --------------------------------------------------------------------------
// Select items in the list according to the extension std::string
//
// Inputs:  pextstring - Pointer to the extension std::string
//          ignorelist - Reference to the list of ignored extensions
//          newextlist - Reference to the list of new extensions
//          flag       - Which flag to set
//          matchmode  - Mode used to match 
//
// Outputs: newextlist - Updated to include those extensions not found in
//                       the existing extension list
//
// Results: None
//
// Effects: The extensions that match the extension std::string are selected
// --------------------------------------------------------------------------

void CExtensionEntryList::SelectExtensionString( const std::string &extstring, 
				CExtensionEntryList &ignorelist, 
				CExtensionEntryList &newextlist,
				int flag, int matchmode, int update )
{
char tempbuf[1024];
int found, bufpos;

const char *pextstring = extstring.data();

if ( !pextstring )
	{
	return;
	}

while ( (pextstring != NULL) && (*pextstring != '\0') )
	{
        while ( isspace( *pextstring ) )
		{
		pextstring++;
		}
                                                                                
	if ( *pextstring != '\0' )
		{
		bufpos = 0;

		while (!isspace( *pextstring)  && (*pextstring != '\0') )
			tempbuf[bufpos++] = *pextstring++;                                                                                 
		tempbuf[bufpos] = '\0';		// Get extension std::string

						// In list?
		found = SetFullNameFlag( tempbuf, flag, matchmode );

		if ( update )
			{
			if ( found == -1 )		
				{		// No, In ignored list?
				found = ignorelist.FindName( tempbuf );
		
				if ( found == -1 ) // No, so add to new list
					newextlist.Add( tempbuf );
				}
			}
		}
	}
}

// --------------------------------------------------------------------------
// Unselect items in the list according to the extension std::string
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extensions that match the extension std::string are unselected
// --------------------------------------------------------------------------
                                                                                
void CExtensionEntryList::UnselectExtensionString( const std::string &extstring,
                                int flag, int matchmode )
{
char tempbuf[1024];
int bufpos;

const char *pextstring = extstring.data();                                                                                
if ( extstring.length() == 0 )
	{
        return;
	}
                                                                                
while ( pextstring && (*pextstring != '\0') )
        {
        while ( isspace( *pextstring ) )
		{
                pextstring++;
		}
                                                                                
        if ( *pextstring )
                {
                bufpos = 0;
                                                                                
                while (!isspace( *pextstring)  && (*pextstring != '\0') )
                        tempbuf[bufpos++] = *pextstring++;                                                                                 
                tempbuf[bufpos] = '\0';         // Get extension std::string
                                                                                
                                                // In list?
                ClearFullNameFlag( tempbuf, flag, matchmode );
                }
        }
}

// --------------------------------------------------------------------------
// Save the state of the system
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The state is saved
// --------------------------------------------------------------------------

void CExtensionEntryList::SaveState( void )
{
for ( unsigned int pn = 0; pn < size(); pn++ )
	{
    	at(pn).EntrySaveState( FLAG_OUTPUT );
	}
}

// --------------------------------------------------------------------------
// Undo the state of the system
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: The state of the system is undone
// --------------------------------------------------------------------------

void CExtensionEntryList::UndoState( void )
{
for ( unsigned int pn = 0; pn < size(); pn++ )
	{
	at(pn).EntryUndoState();
	}
}

// --------------------------------------------------------------------------
// Restore the state of the system
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: The state of the system is restored
// --------------------------------------------------------------------------

void CExtensionEntryList::RedoState( void )
{
for ( unsigned int pn = 0; pn < size(); pn++ )
	{
    	at(pn).EntryRedoState();
	}
}

// --------------------------------------------------------------------------
// Select items in the list that match the selected name
//
// Inputs:  name - Character pointer to the name std::string
//
// Outputs: None
//
// Results: None
//
// Effects: Those entries which matched the name, have the output flag set
// --------------------------------------------------------------------------

void CExtensionEntryList::SelectByName(const std::string &name )
{
for ( unsigned int pn = 0; pn < size(); pn++ )
	{
    	if ( strncmp( at(pn).m_name.data(), name.data(), name.size() ) == 0 )
		{
       		at(pn).EntrySetFlag( FLAG_OUTPUT);
		}
	}
}

// --------------------------------------------------------------------------
// Unselect items in the list which match the name
//
// Inputs:  name - Character pointer to the name std::string
//
// Outputs: None
//
// Results: None
//
// Effects: Those entries which match the name have the output flag cleared
// --------------------------------------------------------------------------

void CExtensionEntryList::RemoveName( const std::string &name )
{
for ( unsigned int pn = 0; pn < size(); pn++ )
	{
    	if ( strncmp( at(pn).m_name.data(), name.data(), name.length() ) == 0 )
		{
        	at(pn).EntryClearFlag( FLAG_OUTPUT);
		}
	}
}

// --------------------------------------------------------------------------
// Callback function for sorting lists by name
//
// Inputs:  ptra - First item
//          ptrb - Second item
// 
// Outputs: None
//
// Results: The result from the std::string comparision function
//
// Effects: None
// --------------------------------------------------------------------------

int CExtensionEntryList::SortByName( CExtensionEntry const &entrya, CExtensionEntry const &entryb )
{
return strcmp( entrya.m_name.data(), entryb.m_name.data() );
}

// --------------------------------------------------------------------------
// Callback function for sorting lists by name reversed
//
// Inputs:  ptra - First item
//          ptrb - Second item
// 
// Outputs: None
//
// Results: The result from the std::string comparision function
//
// Effects: None
// --------------------------------------------------------------------------

int CExtensionEntryList::SortByNameReversed( CExtensionEntry const &entrya, CExtensionEntry const &entryb )
{
return -strcmp( entrya.m_name.data(), entryb.m_name.data() );
}

// --------------------------------------------------------------------------
// Callback function for sorting lists by value
//
// Inputs:  ptra - First item
//          ptrb - Second item
// 
// Outputs: None
//
// Results: The result from the std::string comparision function
//
// Effects: None
// --------------------------------------------------------------------------

int CExtensionEntryList::SortByValue( CExtensionEntry const &entrya, CExtensionEntry const &entryb )
{
return strcmp( entrya.m_value.data(), entryb.m_value.data() );
}

// --------------------------------------------------------------------------
// Callback function for sorting lists by value reversed
//
// Inputs:  ptra - First item
//          ptrb - Second item
// 
// Outputs: None
//
// Results: The result from the std::string comparision function
//
// Effects: None
// --------------------------------------------------------------------------

int CExtensionEntryList::SortByValueReversed( CExtensionEntry const &entrya, CExtensionEntry const &entryb )
{
return -strcmp( entrya.m_value.data(), entryb.m_value.data() );
}

// --------------------------------------------------------------------------
// Callback function for sorting lists by prefix
//
// Inputs:  ptra - First item
//          ptrb - Second item
// 
// Outputs: None
//
// Results: The result from the std::string comparision function
//
// Effects: None
// --------------------------------------------------------------------------

int CExtensionEntryList::SortByPrefix( CExtensionEntry const &entrya, CExtensionEntry const &entryb )
{
return strcmp( entrya.m_prefix.data(), entryb.m_prefix.data() );
}

// --------------------------------------------------------------------------
// Callback function for sorting lists by prefix reversed
//
// Inputs:  ptra - First item
//          ptrb - Second item
// 
// Outputs: None
//
// Results: The result from the std::string comparision function
//
// Effects: None
// --------------------------------------------------------------------------

int CExtensionEntryList::SortByPrefixReversed( CExtensionEntry const &entrya, CExtensionEntry const &entryb )
{
return -strcmp( entrya.m_prefix.data(), entryb.m_prefix.data() );
}

// --------------------------------------------------------------------------
// Toggle the list sorting mode
//
// Inputs:  mode - The mode to toggle
//          
// Outputs: None
//
// Results: None
//
// Effects: The sorting function is modified
// --------------------------------------------------------------------------

void CExtensionEntryList::ToggleSortMode( int mode )
{
if ( (mode & ~LIST_SORTREVERSED) == m_sortmode )
	{
    	m_sortmode ^= LIST_SORTREVERSED;
	}
else
	{
    	m_sortmode = mode;
	}
}

// --------------------------------------------------------------------------
// Sort the list according to the specified mode
// 
// Inputs:  start - Where to start in the list
//          num   - Number of items to sort in the list
//
// Outputs: None
//
// Results: None
//
// Effects: The selected range of the list is sorted
//
// Notes:   We use the template version of QuickSort, as the STL version
//          goes a bit wonky
// --------------------------------------------------------------------------

void CExtensionEntryList::SortRange( int start, int num )
{
if (0 == size() )
	{
	return;
	}

switch ( m_sortmode )
    {
    case LIST_SORTNAME:
	QuickSort( &at(0), size()-1, SortByName );
        //std::sort( begin()+start, begin()+start+num, SortByName );
        break;

    case LIST_SORTVALUE:
	QuickSort( &at(0), size()-1, SortByValue );
        //std::sort( begin()+start, begin()+start+num, SortByValue );
        break;

    case LIST_SORTPREFIX:
	QuickSort( &at(0), size()-1, SortByPrefix );
        //std::sort( begin()+start, begin()+start+num, SortByPrefix );
        break;

    case LIST_SORTNAMEREVERSED:
	QuickSort( &at(0), size()-1, SortByNameReversed );
        //std::sort( begin()+start, begin()+start+num, SortByNameReversed );
        break;

    case LIST_SORTVALUEREVERSED:
	QuickSort( &at(0), size()-1, SortByValueReversed );
        //std::sort( begin()+start, begin()+start+num, SortByValueReversed );
        break;

    case LIST_SORTPREFIXREVERSED:
	QuickSort( &at(0), size()-1, SortByPrefixReversed );
        //std::sort( begin()+start, begin()+start+num, SortByPrefixReversed );
        break;

    default:    
        break;
    }    
}

// --------------------------------------------------------------------------
// Search for a std::string
//
// Inputs: mode - search mode
//         std::string - search std::string
//         callback - callback function
//
// Outputs: callback is called
//
// Results: None
// --------------------------------------------------------------------------

long strtolong( const std::string &str )
{
long result;
const char *pstr;
char ch;

pstr = str.data();

result = 0;

if ( strncmp( pstr, "0x", 2 ) == 0 )
	{
	pstr += 2;

	while ( *pstr != '\0' )
		{
		result <<= 4;
		ch = *pstr;
		
		if ( ch >= 'A' && ch <= 'F' )
			{
			result += ch -'A'+10;
			}
		else
			if ( ch >= '0' && ch <= '9' )
				{
				result += ch - '0';
				}
		else
			{
			return 0;
			}

		pstr++;
		}			
	}
else
	if ( strncmp( pstr, "0", 1 ) == 0 )
		{
		while ( *pstr != '\0' )
			{
			result <<= 3;
			ch = *pstr;

			if ( ch >= '0' && ch <= '7')
				{
				result += ch - '0';
				}
			else
				{
				return 0;
				}
	
			pstr++;
			}
		}
else
	while ( *pstr != '\0' )
		{
		result *= 10;
		ch = *pstr;

		if ( ch >= '0' && ch <= '9' )
			{
			result += ch - '0';
			}
		else
			{
			return 0;
			}

		pstr++;
		}

return result;
}

void CExtensionEntryList::SearchConstants( const std::string &strdata,
			CHeaderFileDataSearchCallback &callback )
{
vector <CExtensionEntry>::iterator iter;
long value;

value = strtolong( strdata );

for (iter = begin(); iter < end(); iter++)
	{
	if ( strstr( iter->m_name.data(), strdata.data() ) != NULL ||
		strstr( iter->m_value.data(), strdata.data() ) != NULL )
		{
		callback.HeaderFileDataSearchCallback(
			SEARCH_CONSTANTS, iter->m_name, iter->m_value );
		}
	}

if ( value > 0 )
	{
	for (iter = begin(); iter < end(); iter++)
		{
		if ( value == strtolong( iter->m_value.data() ) )
			{
			callback.HeaderFileDataSearchCallback(
				SEARCH_CONSTANTS, iter->m_name, iter->m_value );
			}

		}
	}
}

void CExtensionEntryList::SearchFunctions( const std::string &strdata,
			CHeaderFileDataSearchCallback &callback )
{
std::vector <CExtensionEntry>::iterator iter;

for (iter = begin(); iter < end(); iter++)
	{
	if ( strstr( iter->m_name.data(), strdata.data() ) ||
	     strstr( iter->m_value.data(),strdata.data() ) )
		{
		callback.HeaderFileDataSearchCallback(
			SEARCH_FUNCTIONS, iter->m_name, iter->m_value );
		}
	}
}

void CExtensionEntryList::SearchString( int mode, const std::string &strdata,
                        CHeaderFileDataSearchCallback &callback )
{
switch ( mode )
	{
	case SEARCH_CONSTANTS:
		SearchConstants( strdata, callback );
		break;

	case SEARCH_FUNCTIONS:
		SearchFunctions( strdata, callback );
		break;

	default:
		// Should never get here
		break;
	}
}
