#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
ll vst[N],f[N]={0,1},fa[N][22],a[N],st[N][22];
ll n,m,x,L,p,ans;
struct node{
	ll to,nxt;
}edge[N*2];ll num_edge,head[N*2];
inline void add_edge(ll u,ll v){
	edge[++num_edge].nxt=head[u];
	edge[num_edge].to=v;
	head[u]=num_edge;
}
inline void add_two(ll u,ll v){add_edge(u,v);add_edge(v,u);}
void dfs(ll x){
	vst[x]=1;
	for(ll i=1;i<=20&&(1<<i)<=f[x];i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		st[x][i]=max(st[x][i-1],st[fa[x][i-1]][i-1]);
	} 
	for(ll i=head[x];i;i=edge[i].nxt){
		if(!vst[edge[i].to]){
			f[edge[i].to]=f[x]+1;
			fa[edge[i].to][0]=x;
			dfs(edge[i].to);
		}
	}
}
int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=2;i<=n;i++){
		scanf("%lld",&p);
		add_two(i,p);
	}
	for(ll i=1;i<=n;i++) scanf("%lld",&st[i][0]);
	dfs(1);
	for(ll i=1;i<=m;i++){
		ans=0;
		scanf("%lld %lld",&x,&L);
		L=min(L+1,f[x]);
		for(ll j=0;j<=20&&(1<<j)<=L;j++){
			if(L&(1<<j)){
				ans=max(ans,st[x][j]);
				x=fa[x][j];
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}

