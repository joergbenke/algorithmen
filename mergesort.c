#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int merge( unsigned int *array_to_sort, unsigned int l, unsigned int r, unsigned m, unsigned int n )
{

    unsigned int *aux = ( unsigned int * ) malloc ( sizeof ( unsigned int ) * n );
    unsigned int i = l, j = m + 1;
    
    if ( aux == NULL )
    {

	perror ( "Not enough space left in RAM\n" );

	return 1;

    }
    
	
    for ( int k = l; k <= r; k++ )
	aux[ k ] = array_to_sort[ k ];
    
    for (int k = l; k <= r; k++)
    {

	if ( i > m )
	    array_to_sort[ k ] = aux[ j++ ];
	else if ( j > r )
	    array_to_sort[ k ] = aux[ i++ ];
	else if ( aux[ j ] < aux[ i ] )
	    array_to_sort[ k ] = aux[ j++ ];
	else
	    array_to_sort[ k ] = aux[ i++ ];

    }

    return 0;

}


int mergesort( unsigned int *array_to_sort, unsigned int l, unsigned int r, unsigned int n )
{

    unsigned int m = l + (r - l)/ 2;

    if ( r <= l )
	return 1;
	
    mergesort( array_to_sort, l, m, n );
    mergesort( array_to_sort, m+1, r, n );

    if ( array_to_sort[ m + 1 ] >= array_to_sort[ m ] )
	return 0;
    
    merge( array_to_sort, l, r, m, n );
    
    
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

    
    mergesort( array_to_sort, 0, len - 1, len );

    if ( test( array_to_sort, len ) == 0 )
	printf( "Array ist sortiert!\n") ;
    else
	printf( "Array ist nicht sortiert!\n") ;
    	    
    /* for ( int i = 0; i < len; i++ ) */
    /*     printf( "%u ", array_to_sort[ i ] ); */
    /* printf( "\n" ); */

    return 0;

}


