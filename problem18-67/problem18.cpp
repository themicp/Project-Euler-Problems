#include <cstdio>
#include <cstdlib>

using namespace std;

const int HEIGHT = 15;
const int N = ( HEIGHT * ( HEIGHT + 1 ) )/2;

int max( int a, int b ) {
    if ( a > b ) {
        return a;
    }
    return b;
}

FILE *in = fopen( "problem18.in", "r" ), *out = fopen( "problem18.out", "w" );
int i, j, A[ N ][ N ], maxSum;

int main() {
    for ( i = 0; i < HEIGHT; ++i ) {
        for ( j = 0; j < i + 1; ++j ) {
            fscanf( in, "%d", &A[ i ][ j ] );
        }
    }

    i = 0;
    while ( i != HEIGHT ) {
        for ( j = 0; j < i + 1; ++j ) {
            if ( i != 0 ) {
                if ( j != 0 && j != i ) {
                    A[ i ][ j ] += max( A[ i - 1 ][ j ], A[ i - 1 ][ j - 1 ] );
                }
                else if ( j == i ) {
                    A[ i ][ j ] += A[ i - 1 ][ j - 1 ];
                }
                else if ( j == 0 ) {
                    A[ i ][ j ] += A[ i - 1 ][ j ];
                }
            }
        }
        ++i;
    }


    for ( j = 0; j < HEIGHT; ++j ) {
        if ( A[ HEIGHT - 1 ][ j ] > maxSum ) {
            maxSum = A[ HEIGHT - 1 ][ j ];
        }
    }

    printf( "Solution: %i\n", maxSum );

    return 0;
}
