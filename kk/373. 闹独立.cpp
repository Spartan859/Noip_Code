#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll tot,dfn[N],l[N],r[N],w[N],f[N],n,v,lmax[N],rmax[N],vst[N];
vector<ll> es[N];
void dfs(ll x){
	dfn[++tot]=x;l[x]=tot;f[x]=w[x];vst[x]=1;
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(!vst[y]){
			dfs(y);
			f[x]=max(f[x],f[y]);
		}
	}
	r[x]=tot;
}
int main(){
	scanf("%lld",&n);
	for(ll i=2;i<=n;i++){
		scanf("%lld",&v);
		es[i].push_back(v);
		es[v].push_back(i);
	}
	for(ll i=1;i<=n;i++) scanf("%lld",w+i);
	dfs(1);
	for(ll i=1;i<=n;i++) lmax[i]=max(lmax[i-1],w[dfn[i]]);
	for(ll i=n;i>=1;i--) rmax[i]=max(rmax[i+1],w[dfn[i]]);
	for(ll i=2;i<=n;i++) cout<<f[i]*max(lmax[l[i]-1],rmax[r[i]+1])<<' ';
	return 0;
}
