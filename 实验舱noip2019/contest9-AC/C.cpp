#include<bits/stdc++.h>
using namespace std;
#define N_max 200005
#define mpr make_pair
#define ll long long
#define fio(x) freopen(#x".in","r",stdin);freopen(#x".out1","w",stdout)
struct edge1{ll to,w;};
struct edge2{ll x,y,z;};
bool cmp(const edge2 &a,const edge2 &b){
	return a.z<b.z;
}
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
//读入
//dis[x]1，离x最近的加油站离它的距离；2，离x最近的关键点离它的距离 
//w[x]离x最近的加油站在加油站集合中的编号
//v[x]离fuelsta[x]最近的关键点离它的距离（新图中只有加油站的编号）
//c[x] x离 
//算出上述数据后，对于每条边(x,y,z)，
//如果w[x]!=w[y],connect w[x] with w[y],weight c[x]+c[y]+z
//calculate MST on the new graph
//倍增后，看交点在何处，相邻的两点其中一点即为答案 
ll n,m,k,s;
ll fst[N_max],snd[N_max];
vector<edge1> es1[N_max];
ll dis[N_max],vst[N_max];
edge2 g[N_max*4];ll cntn;
ll fa[N_max*2],f[N_max][18];
ll w[N_max],v[N_max],c[N_max];
namespace init{
	inline void add_edge2(ll u,ll v,ll w){
		es1[u].push_back((edge1){v,w});
		es1[v].push_back((edge1){u,w});
	}
	inline void input(){
		n=read();m=read();k=read();s=read();
		for(ll i=1;i<=k;i++) fst[i]=read();
		for(ll i=1;i<=s;i++) snd[i]=read();
		for(ll i=1,u,v,w;i<=m;i++) 
			u=read(),v=read(),w=read(),add_edge2(u,v,w);
	}
}

namespace shstpth{
	inline void dijkstra(ll n,ll* v){//求解v数组为源，v_size=n的n源最短路 
		memset(dis,127,sizeof(dis));
		memset(vst,0,sizeof(vst));
		priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
		for(ll i=1;i<=n;i++) w[v[i]]=i,q.push(mpr(0,v[i])),dis[v[i]]=0;
		while(!q.empty()){
			ll x=q.top().second;q.pop();
			if(vst[x]) continue;
			vst[x]=1;
			for(ll i=0;i<es1[x].size();i++){
				ll y=es1[x][i].to,z=es1[x][i].w;
				if(dis[y]>dis[x]+z){
					dis[y]=dis[x]+z;
					w[y]=w[x];
					q.push(mpr(dis[y],y));
				}
			}
		}
	}
}

namespace MST{
	ll findfa(ll x){return x==fa[x]?x:fa[x]=findfa(fa[x]);}
	inline void solve(){
		for(ll i=1;i<=k;i++) fa[i]=i;
		sort(g+1,g+cntn+1,cmp);
		for(ll i=1;i<=cntn;i++){
			ll x=g[i].x,y=g[i].y,z=g[i].z;
			x=findfa(x),y=findfa(y);
			if(x!=y){
				v[++k]=min(v[x],v[y]);c[k]=g[i].z;
				f[x][0]=f[y][0]=fa[x]=fa[y]=fa[k]=k;
			}
		}
	}
	inline ll query(ll x){
		ll ans=v[x];
		for(ll i=17;~i;i--){
			ll t=f[x][i];
			if(!t) continue;
			if(v[t]>c[t]) ans=min(ans,v[t]),x=t;
			else ans=min(ans,c[t]);
		}
		return ans;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	fio(C);
	#endif
	init::input();
	shstpth::dijkstra(k,fst);
	for(ll i=1;i<=n;i++)
		for(ll j=0;j<es1[i].size();j++){
			ll y=es1[i][j].to,z=es1[i][j].w;
			if(w[i]!=w[y]) g[++cntn]=(edge2){w[i],w[y],dis[i]+dis[y]+z}; 
		}
	//for(ll i=1;i<=n;i++) cout<<dis[i]<<endl; 
	shstpth::dijkstra(s,snd);
	for(ll i=1;i<=k;i++) v[i]=dis[fst[i]];
	MST::solve();
	for(ll i=1;i<=17;i++)
		for(ll j=1;j<=k;j++) f[j][i]=f[f[j][i-1]][i-1];
	for(ll i=1;i<=(k+1)>>1;i++) printf("%lld\n",MST::query(i));
	return 0;
} 
