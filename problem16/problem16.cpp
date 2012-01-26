#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000;

void Product( char *n, int a, int end ) {
    int hold = 0, i, temp;
    for ( i = end - 1; i >= 0; --i ) {
        temp = ( n[ i ] - '0' )*a;
        if ( temp > 9 ) {
            n[ i ] = ( temp % 10 + hold ) + '0';
            hold = 1;
        }
        else {
            n[ i ] = ( temp + hold ) + '0';
            hold = 0;
        }
    }
}

char n[ N ];
int i, sum;

int main() {
    for ( i = 0; i < N; ++i ) {
        n[ i ] = 0 + '0';
    }
    n[ N - 1 ] = 1 + '0';
    n[ 0 ] = 0 + '0';

    for ( i = 0; i < 1000; ++i ) {
        Product( n, 2, N );
    }

    for ( i = 0; i < N; ++i ) {
        sum += n[ i ] - '0';
    }
    printf( "%i\n", sum );

    return 0;
}
