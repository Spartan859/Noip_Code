#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e5;
ll n;
ll cnt[N];
ll clr[N];
vector<ll> es[N];
ll son[N],sz[N],tim;
ll tI[N],tO[N],id[N];
ll ans[N];
ll nwmx,nwans;
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

void aNode(ll x){
	++cnt[clr[x]]; 
	if(cnt[clr[x]]==nwmx) nwans+=clr[x];
	if(cnt[clr[x]]==nwmx+1) ++nwmx,nwans=clr[x];
}

void aTree(ll x){
	for(ll i=tI[x];i<=tO[x];i++)
		aNode(id[i]);
}
void clrpt(){
	memset(cnt,0,sizeof(cnt));
	nwmx=0;
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
		aTree(y);
	}
	aNode(x);
	ans[x]=nwans;
	if(son[fa]==x) return;
	clrpt();
}
int main(){
	freopen("clr.in","r",stdin);
	freopen("clr.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",clr+i);
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u);
	}
	dfs_son(1,0);
	//cout<<1<<endl;
	dfs(1,0);
	for(ll i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}

