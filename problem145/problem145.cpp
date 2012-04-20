#include <cstdio>
#include <cmath>

using namespace std;

int N = 1000000000, i, sum, S, reversed;


int reverse( int n ) {
    int temp = n, j = n % 10;
    n /= 10;
    while ( n > 0 ) {
        j *= 10;
        j += n % 10;
        n /= 10;
    }
    return j;
}

bool odd( int n ) {
    while ( n > 0 ) {
        if ( ( n % 10 ) % 2 == 0 ) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {
    for ( i = 1; i < N; ++i ) {
        reversed = reverse( i );
        if ( floor( log10( i ) ) != floor( log10( reversed ) ) ) {
            continue;
        }
        sum = i + reversed;
        if ( odd( sum ) ) {
            ++S;
        }
    }
    printf( "%i\n", S );
    return 0;
}
