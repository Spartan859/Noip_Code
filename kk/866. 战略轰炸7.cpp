#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll hd_e[N],hd_l[N],n,m,u,v,vst[N];
ll id[N],lca[N];
ll f[N];
ll ans;
struct edge{
	ll u,v,nxt;
}es_l[N*2],es_e[N*2];
inline ll find_fa(ll x){
	return id[x]==x?x:id[x]=find_fa(id[x]);
}
void tarjan(ll x,ll fa){
	id[x]=x;
	for(ll i=hd_l[x];i;i=es_l[i].nxt){
		if(es_l[i].v!=fa){
			tarjan(es_l[i].v,x);
			id[es_l[i].v]=x;
		}
	}
	vst[x]=1;
	for(ll i=hd_e[x];i;i=es_e[i].nxt){
		if(vst[es_e[i].v]){
			lca[(i+1)/2]=find_fa(es_e[i].v);
		}
	}
}
void dfs(ll x,ll fa){
	for(ll i=hd_l[x];i;i=es_l[i].nxt){
		if(es_l[i].v!=fa){
			dfs(es_l[i].v,x);
			f[x]+=f[es_l[i].v];
		}
	}
	if(x==1) return;
	if(f[x]==0) ans+=m;
	if(f[x]==1) ans+=1;
}
int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n+n-3;i+=2){
		scanf("%lld %lld",&u,&v);
		es_l[i].nxt=hd_l[u];
		es_l[i].u=u;es_l[i].v=v;
		hd_l[u]=i;
		es_l[i+1].nxt=hd_l[v];
		es_l[i+1].u=v;es_l[i+1].v=u;
		hd_l[v]=i+1;
	}
	for(ll i=1;i<=m+m-1;i+=2){
		scanf("%lld %lld",&u,&v);
		if(u!=v){
			es_e[i].nxt=hd_e[u];
			es_e[i].u=u;es_e[i].v=v;
			hd_e[u]=i;
			es_e[i+1].nxt=hd_e[v];
			es_e[i+1].u=v;es_e[i+1].v=u;
			hd_e[v]=i+1;
		}
	}
	tarjan(1,0);
	for(ll i=1,a,b;i<=m;i++){
		a=es_e[i*2].v;
		b=es_e[i*2].u;
		f[a]++;
		f[b]++;
		f[lca[i]]-=2;
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
} 
