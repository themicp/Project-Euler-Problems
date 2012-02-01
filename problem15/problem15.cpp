#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2;

int i, A[ 2*N ];

int main() {
    for ( i = 0; i < N; ++i ) {
        A[ i ] = 0;
        A[ i + N ] = 1;
    }

    i = 1;
    while ( next_permutation( A, A + 2 * N ) ) {
        for ( i = 0; i < 2 * N; ++i ) {
            printf( "%i ", A[ i ] );
        }
        printf( "\n" );
        ++i;
    }

    printf( "Solution: %i\n", i );

    return 0;
}
