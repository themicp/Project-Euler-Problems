#include <cstdio>
#include <algorithm>

using namespace std;

int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int i, a, b, c, S;
bool visited[ 1000000 ];

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
    while ( next_permutation( array, array + 9 ) ) {
        // x * xxxx = xxxx
        a = arraytoint( array, 1 );
        b = arraytoint( array + 1, 4 );
        c = arraytoint( array + 5, 4 );
        if ( a * b == c ) {
            if ( !visited[ c ] ) {
                S += c;
                visited[ c ] = 1;
            }
        }
        //xx * xx = xxxxx
        a = arraytoint( array, 2 );
        b = arraytoint( array + 2, 2 );
        c = arraytoint( array + 4, 5 );
        if ( a * b == c ) {
            if ( !visited[ c ] ) {
                S += c;
                visited[ c ] = 1;
            }
        }
        // xxx * xx = xxxx
        a = arraytoint( array, 3 );
        b = arraytoint( array + 3, 2 );
        c = arraytoint( array + 5, 4 );
        if ( a * b == c ) {
            if ( !visited[ c ] ) {
                S += c;
                visited[ c ] = 1;
            }
        }
    }
    printf( "%i\n", S );

    return 0;
}
