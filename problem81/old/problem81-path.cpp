#include <cstdio>
#include <stack>

using namespace std;

const int LEFT = 0;
const int UP = 1;

inline int min( int a, int b ) {
    if ( a < b ) {
        return a;
    }
    return b;
}

FILE *in = fopen( "problem81.in", "r" ), *out = fopen( "problem81.out", "w" );
int i, j, W[ 80 ][ 80 ], a, path[ 80 ][ 80 ], N;
stack< int > p;

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
                    path[ 0 ][ j ] = LEFT;
                }
            }
            else {
                if ( j == 0 ) {
                    W[ i ][ 0 ] = W[ i - 1 ][ 0 ] + a;
                    path[ i ][ 0 ] = UP;
                }
                else {
                    W[ i ][ j ] = min( W[ i - 1 ][ j ], W[ i ][ j - 1 ] ) + a;
                    if ( W[ i ][ j ] - a == W[ i - 1 ][ j ] ) {
                        path[ i ][ j ] = UP;
                    }
                    else {
                        path[ i ][ j ] = LEFT;
                    }
                }
            }
        }
    }

    j = N - 1;
    i = N - 1;
    while ( i > 0 || j > 0 ) {
       p.push( path[ i ][ j ] ); 
       if ( path[ i ][ j ] == LEFT ) {
           --j;
           continue;
       }
       --i;
    }
    while ( !p.empty() ) {
        if ( p.top() == UP ) {
            printf( "↓ " );
        }
        else {
            printf( "→ " );
        }
        p.pop();
    }

    printf( "\n%i\n", W[ N - 1 ][ N - 1 ] );
    return 0;
}
