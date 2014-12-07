#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N;
int **S, **A, i, j, maxsum = 0;
FILE *in = fopen( "problem81.in", "r" );

int MinPath( int x, int y ) {
    if ( x == 0 && y == 0 ) {
        S[ 0 ][ 0 ] = A[ 0 ][ 0 ];
        return S[ 0 ][ 0 ];
    }
    int cost = 0;
    int minSum = maxsum;
    if ( y > 0 ) {
        if ( S[ x ][ y - 1 ] == -1 ) {
            S[ x ][ y - 1 ] = MinPath( x, y - 1 );
        }

        minSum = min( minSum, S[ x ][ y - 1 ] );
    }
    if ( x > 0 ) {
        if ( S[ x - 1 ][ y ] == -1 ) {
            S[ x - 1 ][ y ] = MinPath( x - 1, y );
        }

        minSum = min( minSum, S[ x - 1 ][ y ] );
    }

    return A[ x ][ y ] + minSum;
}

int main() {
    fscanf( in, "%i", &N );

    S = ( int** )malloc( ( N + 1 ) * sizeof( int* ) );
    A = ( int** )malloc( ( N + 1 ) * sizeof( int* ) );
    for ( i = 0; i < N; ++i ) {
        S[ i ] = ( int* )malloc( ( N + 1 ) * sizeof( int ) );
        A[ i ] = ( int* )malloc( ( N + 1 ) * sizeof( int ) );

        for ( j = 0; j < N; ++j ) {
            fscanf( in, "%i,", &A[ i ][ j ] );
            maxsum += A[ i ][ j ];
            S[ i ][ j ] = -1;
        }
    }

    printf( "Min Path Sum: %i\n", MinPath( N - 1, N - 1 ) );
    return 0;
}
