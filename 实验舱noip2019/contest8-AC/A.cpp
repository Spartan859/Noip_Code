#include<bits/stdc++.h>
#define N 2005
#define M 3005
#define ll long long
using namespace std;
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
//qxx
struct edge{ll v,nxt;}es[M];ll head[N],cnt;
inline void add_edge(ll u,ll v){es[++cnt]=(edge){v,head[u]};head[u]=cnt;}
//
ll vst[N],mtch[N];
bool dfs(ll x){
	for(ll i=head[x];i;i=es[i].nxt){
		ll y=es[i].v;
		if(vst[y]) continue;
		vst[y]=1;
		if(!mtch[y]||dfs(mtch[y])){
			mtch[y]=x;
			return 1; 
		}
	}
	return 0;
}ll n,m;
ll ans=0;
bool xyl(){
	for(ll i=1;i<=n;i++){
		memset(vst,0,sizeof(vst));
		if(!dfs(i))
			return 0;
	}
	return 1;
}

int main(){
	while(scanf("%lld%lld",&n,&m)==2){
		cnt=0;
		memset(head,0,sizeof(head));
		memset(mtch,0,sizeof(mtch));
		for(ll i=1,u,v;i<=m;i++){
			u=read();v=read();
			add_edge(u,v);
		}
		if(xyl()) puts("YES");
		else puts("NO");
	}
	return 0;
}
