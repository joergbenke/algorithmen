#include <stdio.h>
#include <stdlib.h>

int fakultaet( int k )
{

    if ( k == 1 )
        return 1;

    return k * fakultaet( k - 1 );

}


int main( int argc, char **argv )
{

    int n = 0;

    n = fakultaet ( 10 );

    printf( "Fakultaet von 10: %d\n", n );

    return 0;

}
