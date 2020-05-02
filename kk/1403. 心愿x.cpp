#include<bits/stdc++.h>
#define ll long long
#define N 1005
using namespace std;
ll n,m,cnt,T;
ll vst[N],num[N],s[N];
ll g[N][N];
inline void bfs(ll n) {
    memset(vst,0,sizeof(vst));
    memset(num,0,sizeof(num));
    cnt=0;
    for(ll i=n; i>=1; i--) {
        ll id=1;
        for(ll j=1; j<=n; j++)
            if(!vst[j]&&num[id]<num[j])
                id=j;
        s[i]=id;
        vst[id]=1;
        for(ll j=1; j<=n; j++)
            if(id!=j&&g[id][j]&&!vst[j])
                num[j]++;
    }
}
inline bool psq(ll n) {
    for(ll i=1; i<=n; i++) {
        ll id;
        for(ll j=i+1; j<=n; j++)
            if(g[s[i]][s[j]]) {
                id=j;
                break;
            }
            
        for(ll j=i+1; j<=n; j++)
            if(g[s[i]][s[j]]&&id!=j&&g[s[id]][s[j]]==0)
                return 0;
    }
    return 1;

}
int main() {
	#ifdef ONLINE_JUDGE
	freopen("wish.in","r",stdin);
	freopen("wish.out","w",stdout);
	#endif
	scanf("%lld",&T);
    while(T--) {
    	scanf("%lld%lld",&n,&m);
        memset(g,0,sizeof(g));
        for(ll i=1,a,b; i<=m; i++) {
            scanf("%lld%lld",&a,&b);
            g[a][b]=g[b][a]=1;
        }
        bfs(n);
        if(psq(n)) puts("Kaopu");
        else puts("Wandan");
    }
    return 0;
}
