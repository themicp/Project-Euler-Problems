#include <cstdio>
#include <string>

using namespace std;

const int N = 1000;

string toString( int n ) {
    int i, key;
    char str[ N ];
    string str1 = "";

    i = N - 1;
    if ( n == 0 ) {
        str[ 0 ] = 0 + '0';
        str[ 1 ] = '\0';
        str1 = str;
        return str1;
    }
    while ( n > 0 ) {
        str[ i ] = n%10 + '0';
        n /= 10;
        --i;
    }

    key = 0;
    for ( i = i + 1; i < N; ++i ) {
        str[ key ] = str[ i ];
        ++key;
    }
    str[ key ] = '\0';

    str1 = str;

    return str1;
}

string add( string a, string b ) {
    int i, sum, length, left = 0;

    length = max( (int)a.size(), (int)b.size() );
    if ( length == (int)a.size() ) {
        i = length - (int)b.size();
        while ( i > 0 ) {
            b.insert( 0, "0" );
            --i;
        }
    }
    else {
        i = length - (int)a.size();
        while ( i > 0 ) {
            a.insert( 0, "0" );
            --i;
        }
    }

    string c = "";
    for ( i = length - 1; i >= 0; --i ) {
        sum = ( a[ i ] - '0' ) + ( b[ i ] - '0' ) + left;
        if ( sum > 9 ) {
            c.insert( 0, toString( sum % 10 ) ); 
            left = 1;
        }
        else {
            if ( sum > 9 ) {
                c.insert( 0, toString( sum % 10 ) );
                left = 1;
            }
            else {
                c.insert( 0, toString( sum ) ); 
                left = 0;
            }
        }
    }
    if ( left == 1 ) {
        c.insert( 0, toString( left ) );
    }
    return c;
}

string A = "1";
string prev = "1";
string temp = "";
int counter;

int main() {
    counter = 2;
    while ( A.size() != N ) {
        temp = A;
        A = add( A, prev );
        prev = temp;
        ++counter;
    }
    printf( "Solution: %i\n", counter );
    return 0;
}
