#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll n;
ll fa[N][25]; 
ll son[N],sz[N],dpth[N];
ll cnt[N];//第k层（绝对位置） 节点数量 
ll ans[N];
vector<pair<ll,ll> > q[N];
struct qxx{
	ll to,nxt;
}es[N*2];ll hd[N],tot;
ll tI[N],tO[N],id[N],tim;
void adde(ll u,ll v){
	es[++tot]=(qxx){v,hd[u]};
	hd[u]=tot;
}
void dfs_son(ll x){
	dpth[x]=dpth[fa[x][0]]+1;
	tI[x]=++tim;id[tim]=x;
	sz[x]=1;
	for(ll i=hd[x];i;i=es[i].nxt){
		ll y=es[i].to;
		dfs_son(y);
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
void aNode(ll x,ll tag){
	if(tag) ++cnt[dpth[x]];
	else --cnt[dpth[x]];
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
	}
	if(son[x]) dfs(son[x]);
	for(ll i=hd[x];i;i=es[i].nxt){
		ll y=es[i].to;
		if(y==son[x]) continue;
		aTree(y,1);
	}
	aNode(x,1);
	for(ll i=0;i<q[x].size();i++){
		ll k=q[x][i].first;
		ans[q[x][i].second]=cnt[k+dpth[x]]-1;
	}
	if(son[fa[x][0]]==x) return;
	aTree(x,0);
}
int main(){
	freopen("bro.in","r",stdin);
	freopen("bro.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&fa[i][0]);
		if(fa[i][0]) adde(fa[i][0],i);
	}
	dfs_son(1);
	prebz();
	ll m;scanf("%lld",&m);
	for(ll i=1,u,k;i<=m;i++){
		scanf("%lld%lld",&u,&k);
		q[LA(u,k)].push_back(make_pair(k,i));
		//cout<<LA(u,k)<<endl;
	}
	dfs(1);
	for(ll i=1;i<=m;i++)
		printf("%lld ",ans[i]);
	return 0;
}

