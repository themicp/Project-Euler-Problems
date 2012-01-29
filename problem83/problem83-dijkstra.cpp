#include <cstdio>
#include <queue>

using namespace std;

struct Node {
    int C;
    int W;
    int status;
};

const int N = 80;
const int INF = 987654321;
const int WHITE = 0;
const int BLACK = 1;
const int RED = 2;

int min( int a, int b ) {
    if ( a < b ) {
        return a;
    }
    return b;
}

void mark( priority_queue< pair< int, pair< int, int > > > &q, Node nodes[ N ][ N ], int i, int j ) {
    q.push( make_pair( -nodes[ i ][ j ].W, make_pair( i, j ) ) );
    nodes[ i ][ j ].status = RED;
}

int matrix[ N + 1 ][ N + 1 ], l, i, j, m, C, tempW;
pair< int, int > top;
FILE *in = fopen( "problem83.in", "r" ), *out = fopen( "problem83.out", "w" );
priority_queue< pair< int, pair< int, int > > > q;
Node nodes[ N ][ N ];

int main() {
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            fscanf( in, "%i,", &nodes[ i ][ j ].C );
            nodes[ i ][ j ].status = WHITE;
            nodes[ i ][ j ].W = INF;
        }
    }

    nodes[ 0 ][ 0 ].W = nodes[ 0 ][ 0 ].C;
    mark( q, nodes, 0, 0 );

    while ( !q.empty() ) {
        top = q.top().second;
        tempW = -q.top().first;
        q.pop();
        if ( top.first < N - 1 ) {
            if ( nodes[ top.first + 1 ][ top.second ].status == WHITE ) {
                nodes[ top.first + 1 ][ top.second ].W = tempW + nodes[ top.first + 1 ][ top.second ].C;
                mark( q, nodes, top.first + 1, top.second );
            }
        }
        if ( top.second < N - 1 ) {
            if ( nodes[ top.first ][ top.second + 1 ].status == WHITE ) {
                nodes[ top.first ][ top.second + 1 ].W = tempW + nodes[ top.first ][ top.second + 1 ].C;
                mark( q, nodes, top.first, top.second + 1 );
            }
        }
        if ( top.second > 0 ) {
            if ( nodes[ top.first ][ top.second - 1 ].status == WHITE ) {
                nodes[ top.first ][ top.second - 1 ].W = tempW + nodes[ top.first ][ top.second - 1 ].C;
                mark( q, nodes, top.first, top.second - 1 );
            }
        }
        if ( top.first > 0 ) {
            if ( nodes[ top.first - 1 ][ top.second ].status == WHITE ) {
                nodes[ top.first - 1 ][ top.second ].W = tempW + nodes[ top.first - 1 ][ top.second ].C;
                mark( q, nodes, top.first - 1, top.second );
            }
        }
        nodes[ top.first ][ top.second ].status = BLACK;
        if ( top.first == N - 1 && top.second == N - 1 ) {
            break;
        }
    }

    printf( "Solution: %i\n", nodes[ N - 1 ][ N - 1 ].W );

    return 0;
}
