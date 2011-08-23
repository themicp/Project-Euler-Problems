#include <cstdio>
#include <cstdlib>

using namespace std;

int productOfFive( int start, char string[ 1001 ] ) {
    int i;
    int product = 1;
    for ( i = start; i < start + 5; ++i ) {
        product *= string[ i ] - '0';
    }
    
    return product;
}

int main() {
    FILE *in = fopen( "in", "r" );
    char string[ 1001 ];
    fscanf( in, "%s", string );
    int max = 0;
    int temp;
    int i = 0;
    
    while ( i < 995 ) {
          temp = productOfFive( i, string );
          if ( temp > max ) {
             max = temp;   
          }
          ++i;
    }
    
    printf( "Result: %i", max );
    system( "PAUSE" );
    return 0;
}
