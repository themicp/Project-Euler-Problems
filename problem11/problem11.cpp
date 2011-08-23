#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    FILE *in = fopen( "in", "r" );
    FILE *out = fopen( "out", "w" );
    int a[ 20 ][ 20 ];
    int i, o, j;
    long long int max = 1, sum = 0, temp;
    
    for ( i = 0; i < 20; ++i ) {
        for ( o = 0; o < 20; ++o ) {
            fscanf( in, "%i", &a[ i ][ o ] );
        }
    }
    for ( i = 0; i < 20; ++i ) {
        max = 1;
        for ( o = 0; o < 20; ++o ) {
            max = 1;
            if ( o < 16 && i < 16 ) {
               for ( j = o; j < o + 4; ++j ) {
                   max *= a[ i ][ j ];
               }
               if ( max > sum ) {
                    temp = sum;
                    sum = max;
                    printf( "( %i, %i ) method %i %lli > %lli\n", o, i, 1, sum, temp );
               }
               max = 1;
               for ( j = i; j < i + 4; ++j ) {
                   max *= a[ j ][ o ];
               }
               if ( max > sum ) {
                    temp = sum;
                    sum = max;
                    printf( "( %i, %i ) method %i %lli > %lli\n", o, i, 2, sum, temp );
               }
               max = 1;
               for ( j = i; j < i + 4; ++j ) {
                   max *= a[ j ][ o + ( j - i ) ];
               }
               if ( max > sum ) {
                    temp = sum;
                    sum = max;
                    printf( "( %i, %i ) method %i %lli > %lli\n", o, i, 3, sum, temp );
               }
               max = 1;
               if ( o > 4 ) {
                   for ( j = i; j < i + 4; ++j ) {
                       max *= a[ j ][ o - ( j - i ) ];
                   }
                   if ( max > sum ) {
                        temp = sum;
                        sum = max;
                        printf( "( %i, %i ) method %i %lli > %lli\n", o, i, 4, sum, temp );
                   }
                   max = 1;
               }
            }
        }
    }
    
    fprintf( out, "%lli\n", sum );
    
    fclose( in );
    system( "PAUSE" );
    return 0;
}
