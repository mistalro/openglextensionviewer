// --------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// --------------------------------------------------------------------------

#ifndef _DERIVEDLISTVIEWITEM_
#define _DERIVEDLISTVIEWITEM_

#include <Qt3Support>

class CDerivedListViewItem : public Q3ListViewItem
{
public:

CDerivedListViewItem( Q3ListView *parent) : Q3ListViewItem( parent) { };

CDerivedListViewItem( Q3ListView *parent, char *name) : Q3ListViewItem( parent,name) { };

virtual ~CDerivedListViewItem() { };

void Init( void ) { };

void Deallocate(void ) { };

void Display(void ) { };

void Duplicate( CDerivedListViewItem &item )
        {
        *this = item;
        };

int SortCompare( CDerivedListViewItem &item )
        {
        return( this < &item );
        };

int operator < (CDerivedListViewItem &item )
        {
        return( this < &item );
        };

int operator > (CDerivedListViewItem &item )
        {
        return( this > &item );
        };
};

#endif // _DERIVEDLISTVIEWITEM_
