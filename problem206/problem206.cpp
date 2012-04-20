#include <cstdio>

using namespace std;

long long int a = 1100000000, b = 1389026700;

bool valid( long long int n ) {
    int i, t;
    for ( i = 10; i > 0; --i ) {
        t = i % 10;
        if ( n % 10 != t ) {
            return false;
        }
        n /= 100;
    }
    return true;
}

int main() {
    for ( ; a <= b; ++a ) {
        if ( valid( a * a ) ) {
            printf( "%lli^2 = %lli\n", a, a * a );
            return 0;
        }
    }
    return 0;
}
