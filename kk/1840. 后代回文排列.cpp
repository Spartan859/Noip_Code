#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll n;
ll fa[N][25]; 
ll son[N],sz[N],dpth[N];
ll cnt[N][30];//第k层（绝对位置）颜色cnt数组 
ll clr[N];
ll ans;
ll res[N];
vector<ll> q[N];
struct qxx{
	ll to,nxt;
}es[N*2];ll hd[N],tot;
ll tI[N],tO[N],id[N],tim;
void adde(ll u,ll v){
	es[++tot]=(qxx){v,hd[u]};
	hd[u]=tot;
}
void dfs_son(ll x){
	//cout<<x<<endl;
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
void aNode(ll x){
	res[dpth[x]]-=cnt[dpth[x]][clr[x]];
	cnt[dpth[x]][clr[x]]^=1;	
	res[dpth[x]]+=cnt[dpth[x]][clr[x]];
}
void aTree(ll x){
	for(ll i=tI[x];i<=tO[x];i++) 
		aNode(id[i]);
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
		aTree(y);
	}
	aNode(x);
	for(ll i=0;i<q[x].size();i++){
		ll h=q[x][i];
		ans+=(res[h]<=1);
	}
	if(son[fa[x][0]]==x) return;
	aTree(x);
}
int main(){
	freopen("hw.in","r",stdin);
	freopen("hw.out","w",stdout);
	ll m;scanf("%lld%lld",&n,&m);
	for(ll i=2;i<=n;i++){
		scanf("%lld",&fa[i][0]);
		adde(fa[i][0],i);
		//cout<<i<<":  "<<fa[i][0]<<endl;
	}
	string clrtmp;cin>>clrtmp;
	//cout<<"qweqwe:  "<<clrtmp<<endl;
	for(ll i=0;i<n;i++) clr[i+1]=clrtmp[i]-'a'+1;
	//cout<<1<<endl;
	dfs_son(1);
	//prebz();
	for(ll i=1,u,h;i<=m;i++){
		scanf("%lld%lld",&u,&h);
		q[u].push_back(h);
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}

