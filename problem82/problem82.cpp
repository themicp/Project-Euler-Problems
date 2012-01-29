#include <cstdio>
#include <stack>

using namespace std;

const int N = 80;
const bool debug = false;
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;

long long int min( long long int a, long long int b ) {
    if ( a < b ) {
        return a;
    }
    return b;
}

void W( long long int w[ N ][ N ], long long int matrix[ N ][ N ], int i, int j ) {
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

int i, j, x, y;
long long minim;
long long matrix[ N ][ N ], w[ N ][ N ], solution;
FILE *in = fopen( "problem82.in", "r" ), *out = fopen( "problem82.out", "w" );
stack< int > p;

int main() {
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            fscanf( in, "%lli,", &matrix[ i ][ j ] );
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
                printf( "%lli ", w[ i ][ j ] );
            }
            printf( "\n" );
        }
    }

    solution = w[ N - 1 ][ N - 1 ];
    for ( i = 0; i < N; ++i ) {
        if ( w[ i ][ N - 1 ] < solution ) {
            solution = w[ i ][ N - 1 ];
            y = i;
        }
    }

    x = N - 1;
    while ( x > 0 ) {
        if ( y == 0 ) {
            if ( w[ y + 1 ][ x ] < w[ y ][ x - 1 ] ) {
                p.push( UP );
                ++y;
            }
            else {
                p.push( RIGHT );
                --x;
            }
        }
        else if ( y == N - 1 ) {
            if ( w[ y - 1 ][ x ] < w[ y ][ x - 1 ] ) {
                p.push( DOWN );
                --y;
            }
            else {
                p.push( RIGHT );
                --x;
            }
        }
        else {
            minim = min( w[ y - 1 ][ x ], min( w[ y ][ x - 1 ], w[ y + 1 ][ x ] ) );
            if ( minim == w[ y - 1 ][ x ] ) {
                p.push( DOWN );
                --y;
            }
            if ( minim == w[ y ][ x - 1 ] ) {
                p.push( RIGHT );
                --x;
            }
            if ( minim == w[ y + 1 ][ x ] ) {
                p.push( UP );
                ++y;
            }
        }
    }
    while ( !p.empty() ) {
        switch ( p.top() ) {
            case RIGHT:
                printf( "Right\n" );
                break;
            case DOWN:
                printf( "Down\n" );
                break;
            case UP:
                printf( "UP\n" );
                break;
        }
        p.pop();
    }
    fprintf( out, "%lli\n", solution );
}
