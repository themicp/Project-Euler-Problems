#include <cstdio>

using namespace std;

int i, o, max, n;

bool isPalindrome( int num ) {
    int temp = num;
    int newNum = 0;
    int rest;
    while ( num > 0 ) {
        rest = num%10;
        num = num/10;
        newNum *= 10;
        newNum += rest;
    }
    return newNum == temp;
}

int main() {
    for ( i = 999; i > 99; --i ) {
        for ( o = i; o > 99; --o ) {
            if ( o * i > max && isPalindrome( o * i ) ) {
                max = o * i;
            }
        }
    }
    printf( "%i\n", max );
    return 0;
}
