#include<bits/stdc++.h>
#define INF 1e10
#define N 55
#define ll long long
using namespace std;
ll n;
ll dis[N][N],x[N],y[N];
ll vst[N];
vector<ll> es[N];
inline ll mhtd(ll xa,ll ya,ll xb,ll yb){
	return labs(xa-xb)+labs(ya-yb);
}
void dfs(ll x){
	for(ll i=0;i<es[x].size();i++)
		if(!vst[es[x][i]]) vst[es[x][i]]=1,dfs(es[x][i]);
}
inline void wp(){
	memset(vst,0,sizeof(vst));
	for(ll i=1;i<=n;i++) es[i].clear();
}
bool ok(ll m){
	wp();
	for(ll i=1;i<=n;i++)
		for(ll j=i+1;j<=n;j++) if(dis[i][j]<=m*2) es[i].push_back(j),es[j].push_back(i);
	dfs(1);
	bool flag=1;
	for(ll i=1;i<=n;i++) if(!vst[i]) flag=0;
	return flag;
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		for(ll j=1;j<i;j++) dis[i][j]=dis[j][i]=mhtd(x[i],y[i],x[j],y[j]);
	}
	ll l=0,r=1e10;
	while(l<=r){
		ll mid=l+r>>1;
		if(ok(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}

