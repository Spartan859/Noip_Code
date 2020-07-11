#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e5;
ll n;
ll cnt[N];
ll clr[N];
vector<ll> es[N];
vector<ll> q[N];
ll son[N],sz[N],tim;
ll tI[N],tO[N],id[N];
ll ans[N];
ll nwans;
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
inline void upd(ll c,ll tp){
	if(tp&&cnt[c]==1) ++nwans;
	if(!tp&&cnt[c]==0) --nwans;
} 
void aNode(ll x,ll tp){
	if(tp) ++cnt[clr[x]],upd(clr[x],tp);
	else --cnt[clr[x]],upd(clr[x],tp);
}

void aTree(ll x,ll tp){
	for(ll i=tI[x];i<=tO[x];i++)
		aNode(id[i],tp);
}
void dfs(ll x,ll fa){
	//cout<<x<<endl;
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
	for(ll i=0;i<q[x].size();i++) ans[q[x][i]]=nwans;
	if(son[fa]==x) return;
	memset(cnt,0,sizeof(cnt));
	nwans=0;
}
int main(){
	//freopen("color.in","r",stdin);
	//freopen("color.out","w",stdout);
	scanf("%lld",&n);
	
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u);
	}
	for(ll i=1;i<=n;i++) scanf("%lld",clr+i);
	ll m;scanf("%lld",&m);
	for(ll i=1,u;i<=m;i++){
		scanf("%lld",&u);
		q[u].push_back(i);
	}
	dfs_son(1,0);
	//cout<<1<<endl;
	dfs(1,0);
	for(ll i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}

