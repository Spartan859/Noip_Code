#include <cstdio>
#include <cstring>
#define N 1010
#define M N*N*2
 
int n, m;
bool c[N][N];
int qu[N], inq[N], dgr[N];
int stk[N], top;
 
void msc() {
    dgr[0] = -1;
    for( int i=n; i>=1; i-- ) {
        int s = 0;
        for( int u=1; u<=n; u++ ) 
            if( !inq[u] && dgr[u]>dgr[s] ) s=u;
        qu[i] = s;
        inq[s] = true;
        for( int u=1; u<=n; u++ )
            if( !inq[u] && c[s][u] ) dgr[u]++;
    }
}
bool check() {
    for( int i=n; i>=1; i-- ) {
        int s=qu[i];
        top = 0;
        for( int j=i+1; j<=n; j++ )
            if( c[s][qu[j]] ) stk[++top] = qu[j];
        if( top==0 ) continue;
        for( int j=2; j<=top; j++ )
            if( !c[stk[1]][stk[j]] ) return false;
    }
    return true;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof(c));
		memset(qu,0,sizeof(qu));
		memset(inq,0,sizeof(inq));
		memset(dgr,0,sizeof(dgr));
		scanf( "%d%d", &n, &m );
    	for( int i=1,u,v; i<=m; i++ ) {
        	scanf( "%d%d", &u, &v );
        	c[u][v] = c[v][u] = 1;
    	}
    	msc();
    	printf( "%s\n", check() ? "Kaopu" : "Wandan" );
	}
    return 0;
}
