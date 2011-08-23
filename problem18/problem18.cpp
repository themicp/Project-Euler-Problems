#include <cstdio>
#include <cstdlib>
#include <utility>

using namespace std;

int path[ 120 ];
int data[ 15 ][ 15 ];
int i, o, max, sum, counter, key, value, head, elems, current, k;
bool done;

int pos ( int y, int x ) {
    int i, o, position = 0;
    for ( i = 1; i <= y; ++i ) {
        position += i;
    }
    position += x;

    return position; 
}

void Path( int* array, int key ) {
    int i;
    if ( array[ key ] == 0 ) {
        array[ key ] = 1;
    }
    else {
        array[ key ] = 0;
        Path( array, key - 1 );
    }
}

int main() {
    FILE *in = fopen( "in", "r" );
    FILE *out = fopen( "out", "w" );

    fscanf( in, "%i", &head );
    sum = head;
    data[ 0 ][ 0 ] = head;
    for ( i = 1; i < 15; ++i ) {
        for ( o = 0; o < i + 1; ++o ) {
            fscanf( in, "%i", &data[ i ][ o ] );
        }
    }
    
    i = 0;
    o = 0;
    while( !done ) {
        printf( "\n" );
        i = 0;
        o = 0;
        sum = head;
        while ( i < 14 ) { 
            if ( path[ pos( i, o ) ]  == 0 ) {
                sum += data[ i + 1 ][ o ];
            }
            else {
                sum += data[ i + 1 ][ o + 1 ];
                ++o;
            }
            ++i;
        }
        if ( sum > max ) {
            max = sum;
        }
        done = true;
        for ( i = 0; i < 120; ++i ) {
            if ( path[ i ] == 0 ) {
                done = false;
                break;
            }
        }
        Path( path, 14 );
    }
    for ( i = 0; i < 15; ++i ) {
        for ( o = 0; o < i + 1; ++o ) {
            printf( "%i ", data[ i ][ o ] );
        }
        printf( "\n" );
    }
    printf( "sum = %i\n", max );

    return 0;
}
