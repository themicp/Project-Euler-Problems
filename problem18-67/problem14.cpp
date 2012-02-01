#include <cstdio>
#include <cstdlib>
#include <utility>

using namespace std;

int b[ 10 ];
int c[ 10 ];
int i, o, max, sum, counter, key, value, head, elems, current, k;

int main() {
    FILE *in = fopen( "in", "r" );
    FILE *out = fopen( "out", "w" );

    pair< int, int > a[ 10 ];
    fscanf( in, "%i", &head );
    b[ current ] = head;
    ++current;
    value = head;
    for ( i = 1; i < 4; ++i ) {
        k = value;
        for ( o = 0; o < i + 1; ++o ) {
            fscanf( in, "%i", &value );
            b[ current ] = value;
            c[ k ] = key;
            ++current;
            ++counter;
            if ( counter == 1 ) {
               a[ key ].first = value;
            }
            if ( counter == 2 ) {
               a[ key ].second = value;
               counter = 0;
               ++key;
               ++elems;
               if ( o < i ) {
                  a[ key ].first = value;
                  ++counter;
               }
            }
        }
        counter = 0;
    }
    
    for ( i = 0; i < 10; ++i ) {
        printf( "for %i\n%i %i\n", c[ i ], a[ c[ b[ i ] ] ].first, a[ c[ b[ i ] ] ].second );
    }
    system( "PAUSE" );
    return 0;
}
