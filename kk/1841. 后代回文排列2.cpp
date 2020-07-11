#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll n;
ll fa[N][25]; 
ll path[N];//根到u的状态压缩 
ll son[N],sz[N],dpth[N];
ll mx[N];//满足i=path[u]的最深节点 
ll ans[N];
ll clr[N];//u节点向父节点的这条边的颜色 
vector<pair<ll,ll> > q[N];
struct qxx{
	ll to,nxt;
}es[N*4];ll hd[N],tot;
ll tI[N],tO[N],id[N],tim;
inline void upd(ll &a,ll b){if(a<b) a=b;}
void adde(ll u,ll v){
	es[++tot]=(qxx){v,hd[u]};
	hd[u]=tot;
}
void dfs_son(ll x){
	path[x]=path[fa[x][0]]^(1<<clr[x]);
	dpth[x]=dpth[fa[x][0]]+1;
	tI[x]=++tim;id[tim]=x;
	sz[x]=1;
	for(ll i=hd[x];i;i=es[i].nxt){
		ll y=es[i].to;
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


inline void uNode(ll x,ll lca){
	ll ansa=mx[path[x]];ll lcax=LCA(ansa,x);
	if(lcax!=ansa) ans[lca]= 
	
}
void uTree(ll x,ll lca){
	for(ll i=tI[x];i<=tO[x];i++)
		uNode(id[i],lca);
}
inline void aNode(ll x,ll tag){
	if(tag)
		if(dpth[mx[path[x]]]<dpth[x]) mx[path[x]]=x;
	else mx[path[x]]=0;
}
void aTree(ll x,ll tag){
	for(ll i=tI[x];i<=tO[x];i++) 
		aNode(id[i],tag);
}
void dfs(ll x){
	for(ll i=hd[x];i;i=es[i].nxt){
		ll y=es[i].to;
		if(y==son[x]) continue;
		dfs(y);
		upd(ans[u],ans[y]);
	}
	if(son[x]) dfs(son[x],x),upd(ans[u],ans[son[x]]);
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
	for(ll i=2;i<=n;i++){
		scanf("%lld%lld",&fa[i][0],&clr[x]);
		adde(fa[i][0],i);
		clr[x]-='a';
	}
	dfs_son(1,0);
	prebz();
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}

