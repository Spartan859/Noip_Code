#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e5;
ll n;
ll cnt[N];
ll clr[N];
vector<ll> es[N];
struct qk{
	ll c,id;
};
vector<qk> q[N];
ll son[N],sz[N],tim;
ll tI[N],tO[N],id[N];
ll ans[N];
void dfs_son(ll x,ll fa){
	sz[x]=1;
	tI[x]=++tim;id[tim]=x;
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(y==fa) continue;
		dfs_son(y,x);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]]) son[x]=y;
	}
	tO[x]=tim;
}
void aNode(ll x,ll tp){
	if(tp) ++cnt[clr[x]];
	else --cnt[clr[x]];
}

void aTree(ll x,ll tp){
	for(ll i=tI[x];i<=tO[x];i++)
		aNode(id[i],tp);
}
void dfs(ll x,ll fa){
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(y==fa||y==son[x]) continue;
		dfs(y,x);
	}
	if(son[x]) dfs(son[x],x);
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(y==fa||y==son[x]) continue;
		aTree(y,1);
	}
	aNode(x,1);
	for(ll i=0;i<q[x].size();i++){
		qk c=q[x][i];
		ans[c.id]=cnt[c.c];
	}
	if(son[fa]==x) return;
	aTree(x,0);
}
int main(){
	freopen("colortree.in","r",stdin);
	freopen("colortree.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",clr+i);
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u);
	}
	ll m;scanf("%lld",&m);
	for(ll i=1,u,c;i<=m;i++){
		scanf("%lld%lld",&u,&c);
		q[u].push_back((qk){c,i});
	}
	dfs_son(1,0);
	dfs(1,0);
	for(ll i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}

