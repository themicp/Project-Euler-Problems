#include <cstdio>

using namespace std;

const int N = 80;
const int INF = 987654321;

int min( int a, int b ) {
    if ( a < b ) {
        return a;
    }
    return b;
}

int W[ N + 2 ][ N + 2 ], matrix[ N + 1 ][ N + 1 ], l, i, j, m, C;
FILE *in = fopen( "problem83.in", "r" ), *out = fopen( "problem83.out", "w" );

int main() {
    for ( i = 1; i <= N; ++i ) {
        for ( j = 1; j <= N; ++j ) {
            fscanf( in, "%i,", &matrix[ i ][ j ] );
        }
    }
    for ( i = 0; i <= N + 1; ++i ) {
        for ( j = 0; j <= N + 1; ++j ) {
            W[ i ][ j ] = INF;
        }
    }

    W[ 1 ][ 1 ] = matrix[ 1 ][ 1 ];
    for ( l = 1; l <= N * N; ++l ) {
        for ( i = 1; i <= N; ++i ) {
            for ( j = 1; j <= N; ++j ) {
                m = W[ i ][ j ];
                C = matrix[ i ][ j ];
                m = min( m, W[ i - 1 ][ j ] + C );
                m = min( m, W[ i + 1 ][ j ] + C );
                m = min( m, W[ i ][ j - 1 ] + C );
                m = min( m, W[ i ][ j + 1 ] + C );
                W[ i ][ j ] = m;
            }
        }
    }

    printf( "Solution: %i\n", W[ N ][ N ] );

    return 0;
}
