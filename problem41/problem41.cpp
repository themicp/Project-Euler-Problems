#include <cstdio>
#include <algorithm>

using namespace std;

int i, temp, array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, maxprime;
bool primes[ 1000000001 ];

void Sieve( bool *A, int N ) {
    int i, o;

    for ( i = 2; i*i < N; ++i ) {
        o = 2;
        while ( o * i <= N ) {
            A[ o * i ] = false;
            if ( o * i == 3 ) {
                printf( "test\n" );
            }
            ++o;
        }
    }
}

int arraytoint( int *a, int k ) {
    int i, n;
    n = a[ 0 ];
    for ( i = 1; i < k; ++i ) {
        n *= 10;
        n += a[ i ];
    }
    return n;
}

int main() {
    for ( i = 3; i <= 1000000000; ++i ) {
        primes[ i ] = true;
    }
    printf( "Running Sieve...\n" );
    Sieve( primes, 987654400 );
    printf( "Done.\n" );
    for ( i = 9; i > 0; --i ) {
        while ( next_permutation( array, array + i ) ) {
            temp = arraytoint( array, i );
            if ( primes[ temp ] ) {
                maxprime = max( maxprime, temp );
            }
        }
    }
    printf( "%i\n", maxprime );
    return 0;
}
