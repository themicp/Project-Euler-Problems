#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

bool isTriangle ( char* word, int len, float* triangles ) {
    bool isTriangle = false;
    int sum = 0;
    int i;

    for ( i = 0; i < len; ++i ) {
        sum += ( (int)word[ i ] - 64 );
    }

    for ( i = 0; i < 100; ++i ) {
        if ( sum == triangles[ i ] ) {
            isTriangle = true;
            break;
        }
    }

    return isTriangle;
}

int count, counter;

int main() {
    FILE *in = fopen( "in", "r" );
    float triangles[ 100 ];
    int i, o;
    char a[ 50 ];
    char b;
    for ( i = 0; i < 100; ++i ) {
        triangles[ i ] = (0.5) * ( i + 1 ) * (i+2);
    }
    for ( i = 0; o < 1786; ++i ) {
        counter = 0;
        fscanf( in, "%c", &b );
        if ( (int)b !=  34 && (int)b != 44 ) {
            a[ counter ] = b;
            ++counter;
            fscanf( in, "%c", &b );
            while ( (int)b != 34 && (int)b != 44 ) {
                a[ counter ] = b;
                ++counter;
                fscanf( in, "%c", &b );
            }
            ++o;
            a[ counter ] = '\0';
            if ( isTriangle( a, counter, triangles ) ) { 
                ++count;
            }
        }
    }
    printf( "There are %i triangle words.\n", count );
    printf( "\n" );
    return 0;
}
