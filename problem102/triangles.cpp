#include <cstdio>

using namespace std;

const int N = 1000;

FILE *in = fopen( "triangles.txt", "r" );
int triangle[ 3 ][ 2 ], i, S;

long int CCW( int *A, int *B ) {
    return ( B[ 0 ] - A[ 0 ] ) * ( 0 - A[ 1 ] ) - ( B[ 1 ] - A[ 1 ] ) * ( 0 - A[ 0 ] );
}

int inTriangle( int *A, int*B, int *C ) {
    return ( CCW( A, B ) * CCW( B, C ) > 0 &&
            CCW( B, C ) * CCW( C, A ) > 0 );
}

int main() {
    for ( i = 1; i <= N; ++i ) {
        fscanf( in, "%d,%d,%d,%d,%d,%d", &triangle[ 0 ][ 0 ], &triangle[ 0 ][ 1 ], &triangle[ 1 ][ 0 ], &triangle[ 1 ][ 1 ], &triangle[ 2 ][ 0 ], &triangle[ 2 ][ 1 ] );
        if ( inTriangle( triangle[ 0 ], triangle[ 1 ], triangle[ 2 ] ) ) {
            ++S;
        }
    }
    printf( "%i\n", S );
    return 0;
}
