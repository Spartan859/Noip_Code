#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll num;
ll n,m,u,v,ans,dfn[100005],low[100005];
ll opt[100005];
bool notperfect=0;
vector<ll> es[100005];
void tarjan(ll x,ll fa){
	dfn[x]=low[x]=++num;
	ll children=0;
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(!dfn[y]){
			children++;
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]&&x!=1) opt[x]=1;
		}
		else if(y!=fa){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(x==1&&children>=2) opt[x]=1;
}
int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u);
	}
	tarjan(1,0);
	for(ll i=1;i<=n;i++)
		if(opt[i]) cout<<i<<endl,notperfect=1;
	if(!notperfect) cout<<"perfect"<<endl;
	return 0;
}
