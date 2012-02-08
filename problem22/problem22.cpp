#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int cmp( const void* a, const void* b ) {
    string A = *( string* )a;
    string B = *( string* )b;
    return A.compare( B );
}

int ascii( string a ) {
    int len = (int)a.size();
    int i, score = 0;
    for ( i = 0; i < len; ++i ) {
        score += (int)a[ i ] - 64;
    }
    return score;
}

FILE *in = fopen( "names.txt", "r" );
string str, A[ 6000 ];
char temp[ 100 ];
int n, i;
long int score;
queue< string > names;

int main() {
    while ( fscanf( in, "\"%[^\"]\",", temp ) != EOF ) {
        str.assign( temp );
        names.push( str );
        ++n;
    }

    i = 0;
    while ( !names.empty() ) {
        A[ i ] = names.front();
        names.pop();
        ++i;
    }

    qsort( A, n, sizeof( string ), cmp );
    for ( i = 0; i < n; ++i ) {
        score += (long int)( ascii( A[ i ] ) * ( i + 1 ) );
    }

    printf( "Solution: %li\n", score );

    return 0;
}
