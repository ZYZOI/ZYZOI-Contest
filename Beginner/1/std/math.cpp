#include <cstdio>

typedef long long lol;
int _w; FILE * _f;

int T;
lol a , b , x , y , g;

lol exgcd( lol a , lol b ) {
  if( !b ) { 
    x = 1 , y = 0;
    return a;
  }
  lol res = exgcd( b , a % b );
  lol tx = x;
  x = y , y = tx - a / b * y;
  return res;
}

int main( void ) {
  _f = freopen("math.in","r",stdin);
  _f = freopen("math.out","w",stdout);
  _w = scanf("%d",&T);
  while( T-- ) {
    _w = scanf("%lld%lld",&a,&b);
    g = exgcd( a , b );
    b /= g;
    x = ( x % b + b ) % b;
    printf("%lld\n",x);
  }
  return 0;
}

