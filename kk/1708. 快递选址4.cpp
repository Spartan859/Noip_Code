#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
ll n;
vector<ll> es[N];
ll sz[N];//×ÓÊ÷
ll dp[N],dpt[N]={-1};
void dfs(ll x,ll fa){
	dpt[x]=dpt[fa]+1;dp[1]+=dpt[x];
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(y==fa) continue;
		dfs(y,x);
		sz[x]+=sz[y];
	}
	++sz[x];
}
/*void dfs_d(ll x,ll fa){
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(y==fa) continue;
		dp[y]=dp[x]+n-sz[y]-sz[y];
		dfs_d(y,x);
	}
}*/
void bfs(){
	queue<pair<ll,ll> > q;
	q.push(make_pair(1,0));
	while(!q.empty()){
		ll x=q.front().first,fa=q.front().second;q.pop();
		for(ll i=0;i<es[x].size();i++){
			ll y=es[x][i];
			if(y==fa) continue;
			dp[y]=dp[x]+n-sz[y]-sz[y];
			q.push(make_pair(y,x));
		}
	}
}
int main(){
	scanf("%lld",&n);
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u);
	}
	dfs(1,0);
	bfs();
	ll maxe=0,maxi;
	for(ll i=1;i<=n;i++)
		if(dp[i]>maxe) maxe=dp[i],maxi=i;
	printf("%lld\n",maxi);
	return 0;
}

