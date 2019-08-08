#include<bits/stdc++.h>
#define M 100005
#define N 100005
#define ll long long
using namespace std;
inline ll read(){
	ll res=0,f=1;
	char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*f;
}

ll n,m;
struct edge{ll u,v,w;}es[M];//边集数组，求最小生成树用 
//struct edge2{ll v,w,nxt;}esx[M*2];/*前向星，储存最小生成树用*/ll head[N],cnt=1;//最终为边数+1 
/*inline void add_edge(ll u,ll v,ll w){
	esx[++cnt]=(edge2){v,w,head[u]};
	head[u]=cnt; 
}*/
//inline void add_edge2(ll u,ll v,ll w){add_edge(u,v,w);add_edge(v,u,w);}
bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}
//并查集 
ll id[N];
inline void init_bcj(){for(ll i=1;i<=n;i++) id[i]=i;}
ll findfa(ll x){return x==id[x]?x:id[x]=findfa(id[x]);}
void unitefa(ll x,ll y){
	ll fx=findfa(x),fy=findfa(y);
	if(fx==fy) return;
	id[fy]=fx;
}
//
//kk
void kruskal(){
	ll ans=0;
	for(ll i=1,u,v,w,fu,fv;i<=m;i++){
		u=es[i].u;v=es[i].v;w=es[i].w;
		fu=findfa(u),fv=findfa(v);
		if(fu==fv) continue;
		//add_edge2(u,v,w);
		ans+=w;
		unitefa(fu,fv);
	}
	printf("%lld\n",ans);
}
int main(){
	n=read();m=read();
	init_bcj();
	for(ll i=1,u,v,w;i<=m;i++){
		u=read();v=read();w=read();
		es[i]=(edge){u,v,w};
	}
	sort(es+1,es+m+1,cmp);
	kruskal();
	
	return 0;
}
