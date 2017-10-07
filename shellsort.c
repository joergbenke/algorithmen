//
// Bemerkungen: Insertionsort ist ohne Optimierung in diesem Beispiel ca. 25 % langsamer, als Slectionsort, aber
//              mit O3 ist Selectionsort ca. 75 % langsamer als Insertionsort


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int shellsort( unsigned int *array_to_sort, unsigned int n )
{

    int tmp = 0;
    unsigned int h = 1;

    while ( h < n / 3 )
	h = 3 * h + 1;
        
    while ( h >= 1 )
    {

	for ( int i = h; i < n; i++ )
	    for ( int j = i; j >= h && ( array_to_sort[ j ] < array_to_sort[ j - h ] ); j = j - h )
		if ( array_to_sort[ j ] < array_to_sort[ j - h ] )
		{
		
		    tmp = array_to_sort[ j - h ];
		    array_to_sort[ j - h ] = array_to_sort[ j ];       
		    array_to_sort[ j ] = tmp;

		}

	h = h / 3;

    }
    
	
    return 0;
    
}

int test( unsigned int *array_to_sort, unsigned int n )
{

    unsigned short int success = 0;
    
    for ( int i = 0; i < n - 1; i++ )
	if ( array_to_sort[ i + 1 ] < array_to_sort[ i ] )
	    success = 1;
	    
    return success;
        
}


int main( int argc, char **argv )
{

    char **ptr = NULL;    

    unsigned int len = 0;
    unsigned int *array_to_sort;

    len = strtol( argv[ 1 ], ptr, 10 );
    array_to_sort = ( unsigned int *) malloc ( sizeof ( unsigned int ) * len );
    
    srand( time( NULL ) );

    for ( int i = 0; i < len; i++ )
	array_to_sort[ i ] = rand() % 1000;
        
    shellsort( array_to_sort, len );

    if ( test( array_to_sort, len ) == 0 )
	printf( "Array ist sortiert!\n") ;
    else
	printf( "Array ist nicht sortiert!\n") ;
    	    
    /* for ( int i = 0; i < len; i++ ) */
    /*     printf( "%d ", array_to_sort[ i ] ); */
    /* printf( "\n" ); */

    return 0;

}
