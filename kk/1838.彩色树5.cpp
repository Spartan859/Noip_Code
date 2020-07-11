#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e5,H=131,MOD=998244353;
ll n;//number of nodes
ll rt[N],cnrt;//rt:the list of roots ;cnrt the number of roots
ll dptmax;//the depth of the tree
ll clr[N];//colors
ll sz[N];//size of subtrees
ll tI[N],tO[N],tim;//dfn in; dfn out; timer
ll re[N];//re[tim]=node number 时间戳对应的节点编号 
ll son[N];//heaviest son
ll dpt[N];//depth
ll fa[N];//father of every node
ll ans[N];//record the answers
vector<pair<ll,ll> > q[N];//divide the questions by nodes
set<ll> st[N];//记录颜色，去重用 
//前向星 
struct qxx{
	ll to,nxt;
}es[N];ll hd[N],tot;
void adde(ll u,ll v){
	es[++tot].to=v;es[tot].nxt=hd[u];
	hd[u]=tot;
}
//hash
inline ll hashs(string s){
	ll len=s.size()-1,hsh=0;
	for(ll i=1;i<=len;i++) hsh=(hsh+s[i])*H%MOD;
	return hsh;
}
//find: depth, size, tI, tO, re, son
void dfs_son(ll x){
	sz[x]=1;dpt[x]=dpt[fa[x]]+1;dptmax=max(dptmax,dpt[x]);
	tI[x]=++tim;re[tim]=x;
	for(ll i=hd[x];i;i=es[i].nxt){
		ll y=es[i].to;
		dfs_son(y);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]]) son[x]=y;
	}
	tO[x]=tim;
}

inline void aNode(ll x,ll tag){
	if (tag) st[dpt[x]].insert(clr[x]);
	else st[dpt[x]].clear();
}
inline void aTree(ll x,ll tag){
	for(ll i=tI[x];i<=tO[x];i++) aNode(re[i],tag);
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
		ll id=q[x][i].second,k=q[x][i].first;
		ans[id]=st[dpt[x]+k].size();
	}
	if(son[fa[x]]==x) return;
	aTree(x,0);
}
int main(){
	freopen("offspring.in","r",stdin);
	freopen("offspring.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1,f;i<=n;i++){
		string s;
		cin>>s;s=' '+s;
		clr[i]=hashs(s);
		scanf("%lld",&f);
		fa[i]=f;
		if(f==0) rt[++cnrt]=i;
		else adde(f,i);
	}
	//questions 
	ll m;
	scanf("%lld",&m);
	for(ll i=1,u,k;i<=m;i++){
		scanf("%lld%lld",&u,&k);
		q[u].push_back(make_pair(k,i));
	}
	for(ll i=1;i<=cnrt;i++){
		dfs_son(rt[i]);
		dfs(rt[i]);
	}
	for(ll i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}
