#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n;
vector<ll> es[N],esB[N];
ll dfn[N],zsl[N],zsr[N],tim,fa[N];
void dfs(ll x,ll y){
	dfn[x]=++tim;
	zsl[x]=tim+1;
	fa[x]=y;
	for(ll i=0;i<es[x].size();i++){
		ll to=es[x][i];
		if(to==y) continue;
		dfs(to,x);
	}
	zsr[x]=tim;
}

int main(){
	scanf("%lld",&n);
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u); 
	}
	dfs(1,0);
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		esB[u].push_back(v);
		esB[v].push_back(u);
	}
}

