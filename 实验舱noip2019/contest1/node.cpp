#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll n,val[N];
vector<ll> es[N];
ll fa[N],sons[N][2];
ll dpth[N];

ll ans_left[N],ans_right[N];
void dfs(ll x){//«Û…Ó∂» 
	dpth[sons[x][0]]=dpth[sons[x][1]]=dpth[x]+1;
	if(sons[x][0]) dfs(sons[x][0]);
	if(sons[x][1]) dfs(sons[x][1]);
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",val+i);
	for(ll i=1,a,b;i<=n;i++){
		scanf("%lld%lld",&a,&b);
		sons[i][0]=a;sons[i][1]=b;
		fa[a]=fa[b]=i;
	}
	dfs(1);
	for(ll i=1;i<=n;i++){
		if(val[i]>dpth[i]) continue;
		ll fns=i,fn;
		for(ll j=1;j<=val[i]-1;j++) fns=fa[fns];
		fn=fa[fns];
		if(fns==sons[fn][0]) ans_left[fn]++;
		else ans_right[fn]++;
	}
	for(ll i=1;i<=n;i++){
		printf("%lld %lld\n",ans_left[i],ans_right[i]);
	}
	return 0;
}
