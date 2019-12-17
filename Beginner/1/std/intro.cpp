#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

namespace IO {
  const int IN_LEN = 1 << 18 | 1;
  static char buf[IN_LEN] , *s , *t;
  inline int Getchar( void ) { return s == t && ( t = ( s = buf ) + fread( buf , 1 , IN_LEN , stdin ) ) , s == t ? -1 : *s++; }
  template <class T> inline void read( T & x ) {
    static int c , f;
    c = Getchar() , x = f = 0;
    while( c < '0' || c > '9' ) { if( c == '-' ) f = 1; c = Getchar(); }
    while( c <= '9' && c >= '0' ) x = x * 10 + c - 48 , c = Getchar();
    x = f ? -x : x;
  }
}using IO::read;

using namespace std;

typedef long long lol;
const int N = 2e5 + 5;
const int M = 2e6 + 5;
const int BASE = 360360;
FILE * _f;

struct node {
  int u , k;
  lol w;
  bool operator < ( const node & rhs ) const {
    return w > rhs.w;
  }
}nd; 
priority_queue<node> Q;
int n , m , head[N] , eidx , st , ed;
lol dis[N][2];
struct Edge {
  int nxt , to;lol val;
} edge[M << 1];

inline void addedge( const int & u , const int & v , const lol & w ) {
  edge[++eidx] = (Edge) { head[u] , v , w }; head[u] = eidx;
  edge[++eidx] = (Edge) { head[v] , u , w }; head[v] = eidx;
}

void dij( void ) {
  static int u , k , w;
  memset( dis , 0x3f , sizeof dis );
  dis[st][0] = 0;
  nd.w = dis[st][0] , nd.u = st , nd.k = 0;
  Q.push( nd );
  while( !Q.empty() ) {
    nd = Q.top(); Q.pop();
    u = nd.u , k = nd.k , w = nd.w;
    if( dis[u][k] != w ) continue;
    for( int i = head[u] , v ; i ; i = edge[i].nxt ) {
      v = edge[i].to;
      if( dis[v][1] <= dis[u][k] + edge[i].val ) continue;
      if( dis[v][0] > dis[u][k] + edge[i].val ) {
        dis[v][0] = dis[u][k] + edge[i].val;
        nd.w = dis[v][0] , nd.u = v , nd.k = 0;
        Q.push( nd );
      } else {
        dis[v][1] = dis[u][k] + edge[i].val;
        nd.w = dis[v][1] , nd.u = v , nd.k = 1;
        Q.push( nd );
      }
    }
  }
}

int main( void ) {
  _f = freopen("intro.in","r",stdin);
  _f = freopen("intro.out","w",stdout);
  read( n ) , read( m ) , read( st ) , read( ed );
  int u , v , a , b;
  while( m-- ) {
    read( u ) , read( v ) , read( a ) , read( b );
    a = a * BASE / b;
    addedge( u , v , a );
  }
  dij();
  printf("%lld\n",dis[ed][1]/BASE);
  return 0;
}
