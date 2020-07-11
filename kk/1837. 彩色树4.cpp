#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e5;
ll n,k;
ll cnt[N],res[N];
ll clr[N];
vector<ll> es[N];
ll son[N],sz[N],tim;
ll tI[N],tO[N],id[N];
ll ans[N];
ll lsh[N],szx;
struct qk{
	ll c,id;
};
vector<qk> q[N];
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
	--res[cnt[clr[x]]];
	++cnt[clr[x]];
	++res[cnt[clr[x]]];
}

void aTree(ll x){
	for(ll i=tI[x];i<=tO[x];i++)
		aNode(id[i]);
}
void clrpt(){
	memset(cnt,0,sizeof(cnt));
	memset(res,0,sizeof(res));
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
	
	for(ll i=0;i<q[x].size();i++) ans[q[x][i].id]=res[k];
	
	if(son[fa]==x) return;
	clrpt();
}
int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",clr+i);
		lsh[i]=clr[i];
	} 
	sort(lsh+1,lsh+n+1);
	szx=unique(lsh+1,lsh+n+1)-lsh;
	cout<<szx<<endl;
	for(ll i=1;i<=n;i++)
		clr[i]=lower_bound(lsh+1,lsh+szx+1,clr[i])-lsh;
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u);
	}
	ll m;scanf("%lld",&m);
	for(ll i=1,u,c=0;i<=m;i++){
		scanf("%lld",&u);
		q[u].push_back((qk){c,i});
	}
	dfs_son(1,0);
	//cout<<1<<endl;
	dfs(1,0);
	for(ll i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}

