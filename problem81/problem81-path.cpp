#include <cstdio>
#include <stack>

using namespace std;


inline int min( int a, int b ) {
    if ( a < b ) {
        return a;
    }
    return b;
}

FILE *in = fopen( "problem81.in", "r" ), *out = fopen( "problem81.out", "w" );
int i, j, W[ 80 ][ 80 ], a, path[ 80 ][ 80 ], N;
stack< int > path;

int main() {
    fscanf( in, "%i", &N );
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            fscanf( in, "%i", &a );
            if ( j < N - 1 ) {
                fscanf( in, "," );
            }
            if ( i == 0 ) {
                if ( j == 0 ) {
                    W[ 0 ][ 0 ] = a;
                }
                else {
                    W[ 0 ][ j ] = W[ 0 ][ j - 1 ] + a;
                    path[ 0 ][ j ] = 0;
                }
            }
            else {
                if ( j == 0 ) {
                    W[ i ][ 0 ] = W[ i - 1 ][ 0 ] + a;
                    path[ i ][ 0 ] = 1;
                }
                else {
                    W[ i ][ j ] = min( W[ i - 1 ][ j ], W[ i ][ j - 1 ] ) + a;
                    if ( W[ i ][ j ] - a == W[ i - 1 ][ j ] ) {
                        path[ i ][ j ] = 1;
                    }
                    else {
                        path[ i ][ j ] = 0;
                    }
                }
            }
        }
    }

    printf( "%i\n", W[ N - 1 ][ N - 1 ] );
    return 0;
}
