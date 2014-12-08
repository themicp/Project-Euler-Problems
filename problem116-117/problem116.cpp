#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define L 50

int i, j, tiles;
long long int ways = 0;
long long int **W;

long long int countWays ( int length, int tiles ) {
    if ( length == tiles ) {
        return 1;
    }
    if ( length < tiles ) {
        return 0;
    }

    long long int ways = 0;
    int i;
    for ( i = tiles; i <= length; ++i ) {
        if ( W[ length - i ][ tiles ] == -1 ) {
            W[ length - i ][ tiles ] = countWays( length - i, tiles );
        }
        ways += 1 + W[ length - i ][ tiles ]; 
    }

    return ways;
}

int main() {
    W = ( long long int ** )malloc( L * sizeof( long long int * ) );
    for ( i = 0; i < L; ++i ) {
        W[ i ] = ( long long int * )malloc( 6 * sizeof( long long int ) );

        for ( j = 0; j <= 5; ++j ) {
            W[ i ][ j ] = -1;
        }
    }
    tiles = 2;
    while ( tiles < 5 ) {
        ways += countWays( L, tiles );
        ++tiles;
    }
    printf( "Solution: %lli\n", ways );
    return 0;
}
