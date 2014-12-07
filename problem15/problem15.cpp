#include <cstdio>
#include <cstdlib>

using namespace std;

#define N 20

long int** C, i, j;

long int CountRoutes( int x, int y ) {
    if ( x == 0 && y == 0 ) {
        return 1;
    }
    long int cost = 0;
    if ( y > 0 ) {
        if ( C[ x ][ y - 1 ] == -1 ) {
            C[ x ][ y - 1 ] = CountRoutes( x, y - 1 );
        }

        cost += C[ x ][ y - 1 ];
    }
    if ( x > 0 ) {
        if ( C[ x - 1 ][ y ] == -1 ) {
            C[ x - 1 ][ y ] = CountRoutes( x - 1, y );
        }

        cost += C[ x - 1 ][ y ];
    }

    return cost;
}

int main() {
    C = ( long int** )malloc( ( N + 1 ) * sizeof( long int* ) );
    for ( i = 0; i <= N; ++i ) {
        C[ i ] = ( long int* )malloc( ( N + 1 ) * sizeof( long int ) );

        for ( j = 0; j <= N; ++j ) {
            C[ i ][ j ] = -1;
        }
    }

    printf( "Cost: %li\n", CountRoutes( N, N ) );
    return 0;
}
