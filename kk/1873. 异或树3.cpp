#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll n;
ll fa[N][25]; 
ll path[N]; 
ll son[N],sz[N],dpth[N];
ll cnt[N];//第k层（绝对位置） 节点数量 
ll ans;
vector<pair<ll,ll> > q[N];
struct qxx{
	ll to,nxt;
}es[N*4];ll hd[N],tot;
ll tI[N],tO[N],id[N],tim;
void adde(ll u,ll v){
	es[++tot]=(qxx){v,hd[u]};
	hd[u]=tot;
}
void dfs_son(ll x,ll fat){
	path[x]=path[fat]^x;
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

void prebz(){
	for(ll i=1;i<=20;i++)
		for(ll j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1]; 
	//cout<<fa[4][1]<<endl;
}
inline ll LA(ll u,ll k){
	for(ll i=20;i>=0;i--)
		if(k&(1<<i)){
			k^=(1<<i);
			u=fa[u][i];
		}
	return u;		
} 
inline ll LCA(ll u,ll v){
	if(dpth[u]<dpth[v]) swap(u,v);
	if(dpth[u]!=dpth[v]) u=LA(u,dpth[u]-dpth[v]);
	for(ll i=20;i>=0;i--){
		if(fa[u][i]==fa[v][i]) continue;
		u=fa[u][i];v=fa[v][i];
	}
	return fa[u][0];
}


inline void uNode(ll x,ll lca){ans+=cnt[lca^path[x]];}
void uTree(ll x,ll lca){
	for(ll i=tI[x];i<=tO[x];i++)
		uNode(id[i],lca);
}
inline void aNode(ll x,ll tag){
	if(tag) ++cnt[path[x]];
	else --cnt[path[x]];
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
		uTree(y,x); aTree(y,1);
	}
	uNode(x,x);
	aNode(x,1);
	if(son[fa[x][0]]==x) return;
	aTree(x,0);
}
int main(){
	freopen("xor3.in","r",stdin);
	freopen("xor3.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		adde(u,v);adde(v,u);
	}
	dfs_son(1,0);
	//prebz();
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}

