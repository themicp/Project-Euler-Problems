#include <cstdio>

using namespace std;

const int N = 10000;

int D( int n ) {
    int i, sum = 0;
    for ( i = 1; i < n; ++i ) {
        if ( n % i == 0 ) {
            sum += i;
        }
    }
    return sum;
}

int d[ 100001 ], i, j, sum;

int main() {
    for ( i = 1; i < N; ++i ) {
        d[ i ] = D( i );
    }
    for ( i = 1; i < N; ++i ) {
        if ( d[ i ] != i ) {
            if ( d[ d[ i ] ] == i ) {
                sum += d[ i ];
                sum += i;
                d[ d[ i ] ] = 0;
            }
        }
    }
    printf( "Solution: %i\n", sum );
    return 0;
}
