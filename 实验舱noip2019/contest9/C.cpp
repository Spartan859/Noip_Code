#include<bits/stdc++.h>
#define N 100005
#define INF 1e18
#define ll long long
using namespace std;
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
/*namespace subtask1{
	#define N_sub1 105
	ll n,m,ks[N_sub1],ss[N_sub1];
	ll dis[N_sub1][N_sub1];
	//vector<ll> es[N_sub1];
	void input(){
		scanf("%lld%lld",&n,&m,&k,&s);
		for(ll i=1;i<=k;i++) ks[i]=read();
		for(ll i=1;i<=s;i++) ss[i]=read();
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				if(i!=j) dis[i][j]=INF;
				else dis[i][j]=0;
		for(ll i=1,u,v,w;i<=m;i++){
			scanf("%lld%lld%lld",&u,&v,&w);
			dis[u][v]=min(dis[u][v],w);
			dis[v][u]=min(dis[v][u],w);
		}
	}
	ll vst[N_sub1];
	bool dfs(ll x,ll lmt){
		for(ll i=1;i<=n;i++) if()
	}
	void solve(){
		input();
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				for(ll k=1;k<=n;k++) dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
		memset(vst,0,sizeof(vst));
		ll l=0,r=1e9,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(dfs())
		}
	}
}*/
ll n,m,k,s,ans=INF;
ll ks[N],ss[N];
vector<ll> es[N],wx[N];
inline void add_edge(ll u,ll v,ll w){
	es[u].push_back(v);
	es[v].push_back(u);
	wx[u].push_back(w);
	wx[v].push_back(w);
}
namespace subtask2{
	ll d[N],vst[N];
	void dijkstra(ll st){
		for(ll i=1;i<=n;i++) d[i]=INF;
		priority_queue<pair<ll,ll> > q;
		q.push(make_pair(0,st));d[st]=0;
		while(!q.empty()){
			ll u=q.top().second;
			q.pop();
			if(vst[u]) continue;
			vst[u]=1;
			for(ll i=0;i<es[u].size();i++){
				ll v=es[u][i],w=wx[u][i];
				if(d[u]+w<d[v]){
					d[v]=d[u]+w;
					q.push(make_pair(-d[v],v));
				}
			}
		}
	}
}

int main(){
	n=read();m=read();k=read();s=read();
	for(ll i=1;i<=k;i++)
		ks[i]=read();
	for(ll i=1;i<=s;i++)
		ss[i]=read();
	for(ll i=1,u,v,w;i<=m;i++) u=read(),v=read(),w=read(),add_edge(u,v,w);
	if(k==1){
		subtask2::dijkstra(ks[1]);
		for(ll i=1;i<=s;i++) ans=min(ans,subtask2::d[ss[i]]);
	}
	cout<<ans<<endl;
	return 0;
}
/*
6 8 1 3
6
1 2 4
3 6 10
5 6 5
2 5 6
2 3 4
3 4 9
2 4 3
2 1 7
5 1 9
*/
