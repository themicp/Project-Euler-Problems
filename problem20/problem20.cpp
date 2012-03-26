#include <cstdio>
#include <string>

using namespace std;

const int N = 200;
const int n = 100;

int max( int a, int b ) {
    if ( a > b ) {
        return a;
    }
    return b;
}

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

string multiply( string a, string b ) {
    int i, j, left, product;
    string temp = "";
    string c = "";
    for ( i = (int)a.size() - 1; i >= 0; --i ) {
        left = 0;
        temp = "";
        for ( j = (int)a.size() - 1; j > i; --j ) {
            temp.insert( 0, toString( 0 ) );
        }
        for ( j = (int)b.size() - 1; j >=0; --j ) {
            product = ( a[ i ] - '0' ) * ( b[ j ] - '0' ) + left;
            if ( product > 0 ) {
                temp.insert( 0, toString( product % 10 ) );
                left = product/10;
            }
            else {
                temp.insert( 0, toString( product ) );
                left = 0;
            }
        }
        if ( left != 0 ) {
            temp.insert( 0, toString( left ) );
        }
        c = add( c, temp );
    }
    return c;
}

string subtract( string a, string b ) {
    int i, left = 0, j, k;
    string c;
    if ( a.size() < b.size() ) {
        while ( a.size() < b.size() ) {
            a.insert( 0, "0" );
        }
    }
    else {
        while ( b.size() < a.size() ) {
            b.insert( 0, "0" );
        }
    }

    for ( i = (int)a.size() - 1; i >= 0; --i ) {
        j = b[ i ] - '0';
        k = a[ i ] - '0';
        j += left;
        left = 0;
        if ( j > k ) {
            k += 10;
            left = 1;
        }
        c.insert( 0, toString( k - j ) );
    }
    return c;
}

string str = toString( n );
int i;
long long int sum;

int main() {
    for ( i = n - 1; i > 0; --i ) {
        str = multiply( str, toString( i ) );    
    }
    for ( i = 0; i < (int)str.size(); ++i ) {
        sum += str[ i ] - '0';
    }
    printf( "Solution: %lli\n", sum );
    printf( "Subtract: %s\n", subtract( "199", "199" ).c_str() );
    return 0;
}
