#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define INF 1e18
using namespace std;
ll T,n,m,k;
ll gjd[N];
ll zd[N];
struct edge{
	ll to,w;
};
vector<edge> es[N];
//dij
ll dis[N],vst[N];

//
inline ll read(){
	ll res=0,f=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*f;
}
ll dijkstra(ll st){
	priority_queue<pair<ll,ll> > q;
	memset(dis,0x7f,sizeof(dis));
	memset(vst,0,sizeof(vst));
	dis[st]=0;
	q.push(make_pair(0,st));
	while(q.size()){
		ll x=q.top().second;
		//cout<<x<<endl;
		q.pop();
		if(vst[x]) continue;
		if(zd[x]&&x!=st){return dis[x];} 
		vst[x]=1;
		for(ll i=0;i<es[x].size();i++){
			ll y=es[x][i].to,z=es[x][i].w;
			if(dis[x]+z<dis[y]){
				dis[y]=dis[x]+z;
				q.push(make_pair(-dis[y],y));
			}
		}	
	}
	return INF;
}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("strygwyr.in","r",stdin);
	freopen("strygwyr.out","w",stdout);
	#endif
	T=read();
	while(T--){
		ll ans=INF;
		n=read();m=read();k=read();
		for(ll i=1;i<=n;i++) es[i].clear();
		memset(zd,0,sizeof(zd)); 
		for(ll i=1,x,y,z;i<=m;i++){
			x=read();y=read();z=read();
			if(x!=y) es[x].push_back((edge){y,z});
		}
		for(ll i=1;i<=k;i++) gjd[i]=read(),zd[gjd[i]]=1;
		for(ll i=1,tmp;i<=k;i++){
			ans=min(ans,dijkstra(gjd[i]));
		}
		printf("%lld\n",ans);
	}
	return 0; 
}
