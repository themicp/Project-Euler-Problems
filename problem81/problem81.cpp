#include <cstdio>

using namespace std;

const int N = 80;

inline int min( int a, int b ) {
    if ( a < b ) {
        return a;
    }
    return b;
}

int w( int matrix[ N ][ N ], int i, int j, int W[ N ][ N ] ) {
    if ( i != 0 && j != 0 ) {
        if ( W[ i - 1 ][ j ] == 0 ) {
            W[ i - 1 ][ j ] == w( matrix, i - 1, j, W );
        }
        if ( W[ i ][ j - 1 ] == 0 ) {
            W[ i ][ j - 1 ] = w( matrix, i, j - 1, W );
        }
        W[ i ][ j ] = min( W[ i ][ j - 1 ], W[ i - 1 ][ j ] ) + matrix[ i ][ j ];
        return W[ i ][ j ];
    }

    if ( i == 0 && j != 0 ) {
        if ( W[ i ][ j - 1 ] == 0 ) {
            W[ i ][ j - 1 ] = w( matrix, i, j - 1, W );
        }
        W[ i ][ j ] = W[ i ][ j - 1 ] + matrix[ i ][ j ];
        return W[ i ][ j ];
    }

    if ( i != 0 && j == 0 ) {
        if ( W[ i - 1 ][ j ] == 0 ) {
            W[ i - 1 ][ j ] = w( matrix, i - 1, j, W );
        }
        W[ i ][ j ] = W[ i - 1 ][ j ] + matrix[ i ][ j ];
        return W[ i ][ j ];
    }

    return matrix[ i ][ j ];
}

FILE *in = fopen( "problem81.in", "r" ), *out = fopen( "problem81.out", "w" );
int matrix[ N ][ N ], i, o, W[ N ][ N ];

int main() {
    for ( i = 0; i < N; ++i ) {
        for ( o = 0; o < N; ++o ) {
            fscanf( in, "%i", &matrix[ i ][ o ] );
            if ( o < N - 1 ) {
                fscanf( in, "," );
            }
        }
    }

    printf( "S = %i\n", w( matrix, N - 1, N - 1, W ) );
    return 0;
}
