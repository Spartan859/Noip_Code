#include<bits/stdc++.h>
#define ll long long
#define N 2005
using namespace std;

ll n,m,fa[N],v[N];
ll fc[N],nc[N],md[N],siz[N],dp[N][N];
ll dfn[N],t,dl[N];
const ll zr=0;

inline void ass(ll x){ll f=fa[x]; if(f) nc[x]=fc[f],fc[f]=x;}

void dfs(ll p){
    siz[p]=1; dfn[p]=++t; dl[t]=p;
    for(ll c=fc[p];c;c=nc[c]){
        dfs(c);
		siz[p]+=siz[c];
    }
}
int main(){
	freopen("rescue.in","r",stdin);
	freopen("rescue.out","w",stdout);
    scanf("%lld %lld",&n,&m);
	m++;n++;
    for(ll i=2;i<=n;i++) scanf("%lld",fa+i),fa[i]++;
    for(ll i=2;i<=n;i++) scanf("%lld",v+i),ass(i);
    dfs(1);
    for(ll p=0;p<=m;p++) dp[n+1][p]=dp[n+2][p]=-2e9;
    dp[n+1][0]=0; 
    for(ll i=n;i>=1;i--){
        ll x=dl[i];
        for(ll p=0;p<=m;p++){
            if(p<1) dp[i][p]=max(dp[i+siz[x]][p],zr);
            else dp[i][p]=max(max(dp[i+siz[x]][p],dp[i+1][p-1]+v[x]),zr);
        }
    }
    printf("%lld\n",dp[1][m]);
    return 0;
}
