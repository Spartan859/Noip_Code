#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll num;
ll n,m,u,v,ans,dfn[100005],low[100005];
vector<ll> es[100005];
void tarjan(ll x,ll fa){
	dfn[x]=low[x]=++num;
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(!dfn[y]){
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
		}
		else if(y!=fa){
			low[x]=min(low[x],dfn[y]);
		}
		if(low[y]>dfn[x]) ans++;
	}
}
int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u);
	}
	tarjan(1,0);
	cout<<ans<<endl;
	return 0;
}
