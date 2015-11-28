// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Template class for quicksort and bubblesort
// --------------------------------------------------------------------------

#ifndef _TEMPLATE_QUICKSORT_H_
#define _TEMPLATE_QUICKSORT_H_

template <class T> class TSortFuncs
{
public:

void Swap(T *px,T *py)
	{
	T temp;

	temp = *px;
	*px  = *py;
	*py  =  temp;
	}

void QuickSort_Range(T *list,int m,int n,
                int (*pcompfunc)(const T &ta, const T &tb)  )
	{
	int i,j,k;
	T key;

	if( m >= n)
        	{
        	return;
        	}

	k = (m+n)/2;
	Swap(list+m,list+k);
	key = list[m];

	i = m+1;
	j = n;

	while(i <= j)
        	{
        	while((i <= n) && ( (*pcompfunc)(list[i], key)<= 0) )
                	{
                	i++;
                	}

        	while((j >= m) && ( (*pcompfunc)(list[j], key)>0))
                	{
                	j--;
                	}

        	if( i < j)
                	{
                	Swap(list+i, list+j);
                	}
        	}

	Swap(list+m, list+j);   // Swap two elements

	// Recursively sort the two sub-lists
	QuickSort_Range(list,m,j-1, pcompfunc); 
	QuickSort_Range(list,j+1,n, pcompfunc);
	}

// High level interface for the quick sort method
void QuickSort( T *base, int num,
                int (*pcompfunc)(const T &ta, const T &tb)  )

{
        QuickSort_Range( base, 0, num-1, pcompfunc);
}

// High level interface for the bubble sort method
void BubbleSort( T *base, int num,
                int (*pcompfunc)(const T &ta, const T &tb)  )
	{
	for ( int i = 0; i < num-1; i++ )
        	{
        	for ( int j=i+1; j < num; j++)
                	{
                	if ( (*pcompfunc)(base[i], base[j]) > 0 )
                        	{
                                swap(base +i, base+j );
                        	}
                	}
        	}
	}

};
#endif	// _TEMPLATE_QUICKSORT_H_
