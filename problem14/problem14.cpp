#include <cstdio>

using namespace std;

int chain( long long int n ) {
    int count = 1;
    while ( n > 1 ) {
        if ( n % 2 == 0 ) {
            n = n/2;
        }
        else {
            n = ( 3*n ) + 1;
        }
        ++count;
    }
    return count;
}

long long int max, i, n, temp;

int main() {
    for ( i = 2; i < 1000000; ++i ) {
        temp = chain( i );
        if ( temp > max ) {
            max = temp;
            n = i;
        }
    }
    printf( "%lli\n", n );
    return 0;
}
