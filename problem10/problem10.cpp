#include <cstdio>
#include <cstdlib>

using namespace std;

bool isPrime( int N, int* primes, int* len ) {
    int i;
    bool prime = true;
    if ( N % 2 == 0 && N > 2 ) {
       return false;   
    }
    
    i = 0;
    while ( primes[ i ] < N && i < N ) {
        if ( i < *len ) {
           if ( N % primes[ i ] == 0 ) {
              prime = false;
               break;
           }
        }
        else {
             if ( N % i == 0 ) {
                prime = false;
                break;
             }
        }
        ++i;
    }
    if ( prime && N > primes[ ( *len ) - 1 ] ) {
       primes[ *len ] = N; 
       ++*len;
    }
    
    return prime;
}

int primes[ 2000000 ];

int main() {
    FILE *in = fopen( "primes", "r" );
    int N;
    int len = 0;
    long long int sum = 0;
    int i;
    int current = 0, progress;
    
    fscanf( in, "%i", &N );
    
    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i", &primes[ i ] );
        ++len;
    }
    
    for ( i = 2; i < 2000000; ++i ) {
        printf( "%i %i\n", i, len );
        progress = ( i/2000000 ) * 100;
        if ( progress > current ) {
           //printf( "%i %\n", progress );   
        }
        if ( isPrime( i, primes, &len ) ) {
           //printf( "sum %i\n", i );
           sum += i;
        }
        current = progress;
    }
    
    printf( "The sum of all the primes below two million equas %i\n", sum );
    
    system( "PAUSE" );
    return 0;
}
