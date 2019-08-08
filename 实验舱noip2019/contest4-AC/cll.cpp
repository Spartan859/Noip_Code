#include<bits/stdc++.h>
#define fi(s) freopen(s,"r",stdin)
#define fo(s) freopen(s,"w",stdout)
#define ll long long
#define N 500005
using namespace std;

ll T;
ll s[N];//s（i）记录从根节点一路到i的异或值 不需要清零 
ll head[N],cnt;//前向星头数组 

struct edge{
	ll v,w,nxt;
}es[N<<1];

inline void add_edge(ll u,ll v,ll w){
	es[++cnt]=(edge){v,w,head[u]};
	head[u]=cnt;
}

inline void add_edge_d(ll u,ll v,ll w){
	add_edge(u,v,w);
	add_edge(v,u,w);
}

void dfs(ll x,ll fa){//填充s[] 
	//cout<<x<<endl;
	for(ll i=head[x];i!=-1;i=es[i].nxt){
		ll y=es[i].v;
		if(y==fa) continue;
		s[y]=s[x]^es[i].w;
		dfs(y,x);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	//fi("cll4.in");
	//fo("output.txt");
	#endif
	scanf("%lld",&T);
	while(T--){
		ll n;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++) head[i]=-1;
		cnt=0;
		map<ll,ll> h;
		for(ll i=1,u,v,w;i<=n-1;i++){
			scanf("%lld%lld%lld",&u,&v,&w);
			if(!h[w]) h[w]=(((rand()&32767LL<<15LL)|(rand()&32767LL))<<15LL)|(rand()&32767LL);
			add_edge_d(u,v,h[w]);
		}
		dfs(1,0);
		map<ll,ll> cnt;
		for(ll i=1;i<=n;i++) cnt[s[i]]++;
		ll ans=0;
		for(ll i=1;i<=n;i++) ans+=n-cnt[s[i]];
		printf("%lld\n",ans>>1);
	}
	return 0;
}
