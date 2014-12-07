#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define H 15
/* Problem 67
#define H 100
*/

using namespace std;

int i, j;
int** A;
int** S;
FILE* in = fopen( "problem18.in", "r" );

int MAXSUM( int x, int y ) {
    if ( y == 0 ) {
        S[ 0 ][ 0 ] = A[ 0 ][ 0 ];
        return S[ 0 ][ 0 ];
    }
    if ( S[ y - 1 ][ x ] == -1 ) {
        S[ y - 1 ][ x ] = MAXSUM( x, y - 1 );
    }
    if ( x > 0 ) {
        if ( S[ y - 1 ][ x - 1 ] == -1 ) {
            S[ y - 1 ][ x - 1 ] = MAXSUM( x - 1, y - 1 );
        }

        return A[ y ][ x ] + max( S[ y - 1 ][ x - 1 ], S[ y - 1 ][ x ] );
    }

    return A[ y ][ x ] + S[ y - 1 ][ x ];
}

int main() {
    A = ( int** )malloc( H * sizeof( int* ) );
    S = ( int** )malloc( H * sizeof( int* ) );
    for ( i = 0; i < H; ++i ) {
        A[ i ] = ( int* )malloc( H * sizeof( int ) );
        S[ i ] = ( int* )malloc( H * sizeof( int ) );

        for ( j = 0; j < H; ++j ) {
            A[ i ][ j ] = 0;
            S[ i ][ j ] = -1;
        }
    }

    for ( i = 0; i < H; ++i ) {
        for ( j = 0; j <= i; ++j ) {
            fscanf( in, "%d", &A[ i ][ j ] );
        }
    }

    int maxsum = 0;
    for ( i = 0; i < H; ++i ) {
        maxsum = max( maxsum, MAXSUM( i, H - 1 ) );
    }
    printf( "Max sum: %i\n", maxsum );

    return 0;
}
