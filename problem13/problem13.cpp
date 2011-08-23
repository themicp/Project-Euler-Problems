#include <cstdio>
#include <cstdlib>

using namespace std;

void addition( char a[ 1000 ], int start, int n ) {
    int sum = ( a[ start ] - '0' ) + n;
    if ( start >= 0 && sum > 9 ) {
        a[ start ] = ( sum % 10 ) + '0';
        addition( a, start - 1, sum/10 );
    }
    else {
        a[ start ] = n + '0';
    }
    printf( "n = %i sum = %i\n", n, sum );
}

void add( char a[ 1000 ], int j, int k, char n[ 50 ] ) {
    int sum;
    int i = 49;
    char x[ 1 ];
    sum = ( a[ j ] - '0' ) + ( n[ k ] - '0' );
    if ( sum > 9 && k >= 0 ) {
        a[ j ] = ( sum % 10 ) + '0';
        sum = sum/10;
        x[ 0 ] = sum + '0';
        add( a, j - 1, 0, x );
    }
    else {
        a[ j ] = sum + '0';
    }
}

char num[ 1000 ];
char n[ 50 ];
int i, o;

int main() {
    FILE *in = fopen( "in", "r" );
    int b = 53;
    int pos;
    int start = 49;
    for ( i = 0; i < 1000; ++i ) {
        num[ i ] = 0 + '0';
        if ( i < 50 ) {
            n[ i ] = 0 + '0';
        }
    }
    for ( i = 0; i < 100; ++i ) {
        fscanf( in, "%s", n );
        printf( "%s\n", n );
        for ( o = 49; o >= 0; --o ) {
            pos = 1000 - ( 50 - o );
            add( num, pos, o, n );
        }
    }
    printf( "%s\n", num );
    return 0;
}
