#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5e3 + 5;
const int K = 1e3 + 5;
int _w; FILE * _f;

int val[N] , f[2][N] , n , k , d , que[N] , he , ta , now , ans;

int main( void ) {
  _f = freopen("classic.in","r",stdin);
  _f = freopen("classic.out","w",stdout);
  _w = scanf("%d%d%d",&n,&k,&d);
  for( int i = 1 ; i <= n ; ++i )
    _w = scanf("%d",val + i);
  f[0][0] = 0;
  for( int i = 1 ; i <= k ; ++i ) {
    now ^= 1;
    que[he = ta = 1] = i - 1;
    for( int j = i ; j <= n ; ++j ) {
      while( he <= ta && j - que[he] > d ) ++he;
      if( he <= ta ) {
        int u = que[he];
        f[now][j] = f[now ^ 1][u] + val[j];
      }
      while( he <= ta && f[now ^ 1][que[ta]] < f[now ^ 1][j] ) --ta;
      que[++ta] = j;
    }
    for( int j = 1 ; j <= n ; ++j )
      ans = max( ans , f[now][j] );
  }
  printf("%d",ans);
  return 0;
}

