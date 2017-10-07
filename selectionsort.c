#include <stdio.h>
#include <stdlib.h>

int selectionsort( int *array_to_sort )
{

    int min = 0, tmp = 0;
    
    for ( int i = 0; i < 10; i++ )
    {
        
            min = i;
            for ( int j = i+1; j < 10; j++ )
                   if ( array_to_sort[ j ] < array_to_sort[ min ] )
                        min = j;
        
            tmp = array_to_sort[ i ];
            array_to_sort[ i ] = array_to_sort[ min ];       
    array_to_sort[ min ] = tmp;
        
    }

    return 0;

}

int main( int argc, char **argv )
{


    int array_to_sort[ 10 ] = { 1,5,2,7,1,9,2,3,5,0};
    
    selectionsort( array_to_sort );

    for ( int i = 0; i < 10; i++ )
        printf( "%d ", array_to_sort[ i ] );
    printf( "\n" );

    return 0;

}
