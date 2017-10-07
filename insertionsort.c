#include <stdio.h>
#include <stdlib.h>

int insertionsort( int *array_to_sort )
{

    int min = 0, tmp = 0;
    
    for ( int i = 0; i < 10; i++ )
    {
            for ( int j = i; j > 0; j-- )
                   if ( array_to_sort[ j ] < array_to_sort[ j -1 ] )
                   {
            tmp = array_to_sort[ j-1 ];
            array_to_sort[ j-1 ] = array_to_sort[j ];       
    array_to_sort[ j ] = tmp;
                   }
    }

    return 0;

}

int main( int argc, char **argv )
{


    int array_to_sort[ 10 ] = { 1,5,2,7,1,9,2,3,5,0};
    
    insertionsort( array_to_sort );

    for ( int i = 0; i < 10; i++ )
        printf( "%d ", array_to_sort[ i ] );
    printf( "\n" );

    return 0;

}
