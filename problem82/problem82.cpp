#include <cstdio>

using namespace std;

const int N = 80;
const bool debug = false;

int min( int a, int b ) {
    if ( a < b ) {
        return a;
    }
    return b;
}

void W( unsigned long long int w[ N ][ N ], unsigned long long int matrix[ N ][ N ], int i, int j ) {
    int k, l = 0, minPath = 0, sum;
    while ( l < N ) {
        sum = w[ l ][ j - 1 ];
        if ( l < i ) {
            for ( k = l; k < i; ++k ) {
                sum += matrix[ k ][ j ]; 
            }
        }
        else if ( l > i ) {
            for ( k = l; k > i; --k ) {
                sum += matrix[ k ][ j ]; 
            }
        }
        minPath = ( minPath == 0 ? sum : min( sum, minPath ) );
        ++l;
    }
    w[ i ][ j ] = minPath + matrix[ i ][ j ];
}

int i, j;
unsigned long long matrix[ N ][ N ], w[ N ][ N ], solution;
FILE *in = fopen( "problem82.in", "r" ), *out = fopen( "problem82.out", "w" );

int main() {
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            fscanf( in, "%i,", &matrix[ i ][ j ] );
            if ( j == 0 ) {
                w[ i ][ j ] = matrix[ i ][ j ];
            }
        }
    }
    for ( j = 1; j < N; ++j ) {
        for ( i = 0; i < N; ++i ) {
            W( w, matrix, i, j );
        }
    }

    if ( debug ) {
        for ( i = 0; i < N; ++i ) {
            for ( j = 0; j < N; ++j ) {
                printf( "%i ", w[ i ][ j ] );
            }
            printf( "\n" );
        }
    }

    solution = w[ N - 1 ][ N - 1 ];
    for ( i = 0; i < N; ++i ) {
        if ( w[ i ][ N - 1 ] < solution ) {
            solution = w[ i ][ N - 1 ];
        }
    }
    fprintf( out, "%lli\n", solution );
}
