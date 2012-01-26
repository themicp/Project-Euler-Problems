#include <cstdio>

using namespace std;

const int N = 1000;

int a, b, c;

int main() {
    for ( a = 1; a < 1000; ++a ) {
        for ( b = 1; b < 1000 - a; ++b ) {
            c = 1000 - a - b;
            if ( c * c == a*a + b*b ) {
                printf( "abc = %lli\n", a*b*c );
                return 0;
            }
        }
    }
    return 0;
}
