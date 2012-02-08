#include <cstdio>
#include <string>

using namespace std;

const int N = 1000;

int letters( int n, string* A, string* B, string* C ) {
    int size, a, b, c;
    if ( n < 20 ) {
        size = (int)A[ n - 1 ].size();
    }
    if ( n >= 20 && n < 100 ) {
        b = n % 10;
        size = letters( b, A, B, C );
        a = n / 10;
        size += (int)B[ a - 1 ].size();
    }
    if ( n >= 100 && n < 1000 ) {
        if ( n % 100 == 0 ) {
            a = n / 100;
            size = letters( a, A, B, C );
            size += (int)C[ 0 ].size();
        }
        else {
            c = n % 10;
            b = ( n / 10 ) % 10;
            a = n / 10 / 10;

            size = letters( ( b * 10 ) + c, A, B, C );
            size += letters( a * 100, A, B, C );
            size += (int)C[ 2 ].size();
        }
    }
    if ( n == 1000 ) {
        size = (int)A[ 0 ].size();
        size += (int)C[ 1 ].size();
    }
    return size;
}

string A[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"  };
string B[] = { "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
string C[] = { "hundred", "thousand", "and" };
int i, sum;

int main() {
    for ( i = 1; i <= N; ++i ) {
        sum += letters( i, A, B, C );
    }
    printf( "Solution: %i\n", sum );
    return 0;
}
