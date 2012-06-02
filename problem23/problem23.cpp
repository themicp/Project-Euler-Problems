#include <cstdio>

using namespace std;

const int MAX = 28123;

int i, j, sum, abundants[ MAX ], k;
bool a[ 28130 ];

int main() {
    for ( i = 1; i <= MAX; ++i ) {
        sum = 0;
        for ( j = 1; j < i; ++j ) {
            if ( i % j == 0 ) {
                sum += j;
            }
        }
        if ( sum > i ) {
            abundants[ k ] = i;
            ++k;
        }
    }
    for ( i = 0; i < k; ++i ) {
        for ( j = 0; j < k; ++j ) {
            sum = abundants[ i ] + abundants[ j ];
            if ( sum <= MAX ) {
                a[ sum ] = true;
            }
        }
    }
    sum = 0;
    for ( i = 0; i <= MAX; ++i ) {
        sum += a[ i ] == false ? i : 0; 
    }
    printf( "%i\n", sum );
    return 0;
}
