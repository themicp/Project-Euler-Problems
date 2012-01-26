#include <cstdio>
#include <cstdlib>

using namespace std;

const long long int N = 99999999;
const int D = 500;

long long int T( long long int N ) {
    return ( N*( N + 1 ) )/2;
}

int count[ N ];
bool triags[ N ];
long long int i,o;

int main() {
    for ( i = 0; i < N; ++i ){
        count[ i ] = 1;
    }
    i = 1;
    while ( T( i ) < N ) {
        triags[ T( i ) ] = true;
        ++i;
    }
    for ( i = 1; i < N; ++i ) {
        for ( o = 1; o * i < N; ++o ) {
            if ( triags[ o * i ] ) {
                ++count[ o * i ];
            }
        }
    }
    for ( i = 0; i < N; ++i ){
        if ( triags[ i ] ) {
            if ( count[ i ] > D ) {
                printf( "Found: %lli\n", i );
                break;
            }
        }
    }
    return 0;
}
