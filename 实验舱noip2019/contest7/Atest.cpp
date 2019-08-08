#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
struct edge2{ll v,w,nxt;}esx[M*2];/*前向星，储存最小生成树用*/ll head[N],cnt=1;//最终为边数+1 
inline void add_edge(ll u,ll v,ll w){
	esx[++cnt]=(edge2){v,w,head[u]};
	head[u]=cnt; 
}
inline void add_edge2(ll u,ll v,ll w){add_edge(u,v,w);add_edge(v,u,w);}
int main(){
	scanf("%lld",&n);
	for(ll i=1,u,v,w;i<=n-1;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add_edge2(u,v,w);
	}
	for(ll i=1;i<=n-1;i++)
		for(ll j=i+1;j<=n;j++) 
	return 0;
} 
