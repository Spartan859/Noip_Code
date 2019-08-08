#include<bits/stdc++.h>
#define N 100005
#define M 100005
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define ll long long
using namespace std;
inline ll read(){
	ll res=0,f=1;
	char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*f;
}
ll n,m,Q;
struct edge2{ll v,nxt;}esx[M*2];/*前向星，储存最小生成树用*/ll head[N],cnt=1;//最终为边数+1 
inline void add_edge(ll u,ll v){
	esx[++cnt]=(edge2){v,head[u]};
	head[u]=cnt; 
}
inline void add_edge2(ll u,ll v){add_edge(u,v);add_edge(v,u);}
namespace subtask3{
	void solve(){
		for(ll i=1;i<=Q;i++) printf("%lld\n",1);
	}
}

ll vst[N],ans;
void bfs(ll x,ll y){
	//dbg(x);
	memset(vst,0,sizeof(vst));
	queue<pair<ll,ll> > q;
	q.push(make_pair(x,0LL));vst[x]=1;
	while(!q.empty()){
		pair<ll,ll> u=q.front();q.pop();vst[u.first]=0;
		//if(u==y) ans++;
		cout<<"debug: "<<u.first<<' '<<u.second<<endl;
		for(ll i=head[u.first];i;i=esx[i].nxt){
			ll v=esx[i].v;
			if(v==y&&v!=u.second) ans++;
			if(!vst[v]) q.push(make_pair(v,u.first)),vst[v]=1;
		}
	}
}

int main(){
	n=read();m=read();Q=read();
	if(m==n-1){
		subtask3::solve();
		return 0;
	} 
	for(ll i=1,u,v;i<=m;i++){
		u=read();v=read();
		add_edge2(u,v);
	}
	for(ll i=1,u,v;i<=Q;i++){
		u=read();v=read();
		ans=0;
		bfs(u,v);
		printf("%lld\n",ans);
	}
	return 0;
}
