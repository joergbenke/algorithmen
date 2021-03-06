#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int selectionsort( unsigned int *array_to_sort, unsigned int n )
{

    int min = 0, tmp = 0;
    
    for ( int i = 0; i < n; i++ )
    {
        
	min = i;

	for ( int j = i + 1; j < n; j++ )
	    if ( array_to_sort[ j ] < array_to_sort[ min ] )
		min = j;
        
	tmp = array_to_sort[ i ];
	array_to_sort[ i ] = array_to_sort[ min ];       
	array_to_sort[ min ] = tmp;
        
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

    /* for ( int i = 0; i < len; i++ ) */
    /*     printf( "%u ", array_to_sort[ i ] ); */
    /* printf( "\n" ); */

    
    selectionsort( array_to_sort, len );

    if ( test( array_to_sort, len ) == 0 )
	printf( "Array ist sortiert!\n") ;
    else
	printf( "Array ist nicht sortiert!\n") ;
    	    
    /* for ( int i = 0; i < len; i++ ) */
    /*     printf( "%u ", array_to_sort[ i ] ); */
    /* printf( "\n" ); */

    return 0;

}


