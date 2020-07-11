#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll n;
ll clr[N];
ll fa[N][25]; 
ll son[N],sz[N],dpth[N];
ll cnt[N];
ll ans[N];
ll q[N];
ll cntAll[N];
ll res;
struct qxx{
	ll to,nxt;
}es[N*4];ll hd[N],tot;
ll tI[N],tO[N],id[N],tim;
pair<ll,ll> esx[N];
void adde(ll u,ll v){
	es[++tot]=(qxx){v,hd[u]};
	hd[u]=tot;
}
void dfs_son(ll x,ll fat){
	++cntAll[clr[x]];
	fa[x][0]=fat;
	dpth[x]=dpth[fat]+1;
	tI[x]=++tim;id[tim]=x;
	sz[x]=1;
	for(ll i=hd[x];i;i=es[i].nxt){
		ll y=es[i].to;
		if(y==fat) continue;
		dfs_son(y,x);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]]) son[x]=y;
	}
	tO[x]=tim;
}

inline void aNode(ll x,ll tag){
	if(tag){
		++cnt[clr[x]];
		if(cnt[clr[x]]==1) ++res;
		if(cnt[clr[x]]==cntAll[clr[x]]) --res;
	} 
	else --cnt[clr[x]];
}
void aTree(ll x,ll tag){
	for(ll i=tI[x];i<=tO[x];i++) 
		aNode(id[i],tag);
}
void dfs(ll x,ll fat){
	for(ll i=hd[x];i;i=es[i].nxt){
		ll y=es[i].to;
		if(y==son[x]||y==fat) continue;
		dfs(y,x);
	}
	if(son[x]) dfs(son[x],x);
	for(ll i=hd[x];i;i=es[i].nxt){
		ll y=es[i].to;
		if(y==son[x]||y==fat) continue;
		aTree(y,1);
	}
	aNode(x,1);
	ans[q[x]]=res;
	if(son[fa[x][0]]==x) return;
	aTree(x,0);
	res=0;
}
int main(){
	freopen("ctree.in","r",stdin);
	freopen("ctree.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",clr+i);
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		adde(u,v);adde(v,u);
		esx[i]=make_pair(u,v);
	}
	dfs_son(1,0);
	for(ll i=1,u,v;i<=n-1;i++){
		u=esx[i].first;v=esx[i].second;
		if(fa[u][0]==v) q[u]=i;
		else q[v]=i;
	}
	//prebz();
	dfs(1,0);
	for(ll i=1;i<=n-1;i++) printf("%lld ",ans[i]);
	return 0;
}

