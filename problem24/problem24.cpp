#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

char str[ ] = "0123456789";
int i;

int main() {
    for ( i = 0; i < 1000000 - 1; ++i ) {
        next_permutation( str, str + 10 );
    }
    printf( "%s\n", str );
    return 0;
}
