#include<bits/stdc++.h>
#define F(i,s,t) for(ll i=s;i<=t;i++)
#define N_MAX 10005
#define M_MAX 100005
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

ll n,m,s,t;
struct edge{
	ll v,w,nxt;
}es[M_MAX*2];ll head[N_MAX],cnt=1;
inline void add_edge(ll u,ll v,ll w){
	es[++cnt]=(edge){v,w,head[u]};
	head[u]=cnt;
}

struct pr{ll v,e;}pre[N_MAX];
ll inque[N_MAX];
inline bool bfs(){
	memset(inque,0,sizeof(inque));
	memset(pre,-1,sizeof(pre));
	queue<ll> q;
	q.push(s);inque[s]=1;
	while(!q.empty()){
		ll x=q.front();
		//cout<<s<<endl;
		q.pop();
		for(ll i=head[x];i;i=es[i].nxt){
			ll y=es[i].v;
			//cout<<y<<endl;
			if(!inque[y]&&es[i].w){
				pre[y]=(pr){x,i};
				if(y==t) return 1;
				q.push(y);inque[y]=1;
			}
		}
	}
	return 0;
}
void EK(){
	//cout<<1<<endl;
	ll ans=0;
	while(bfs()){
		//cout<<1<<endl;
		ll mi=2e18;
		for(ll i=t;i!=s;i=pre[i].v){
			//dbg(i);
			mi=min(mi,es[pre[i].e].w);
		} 
		for(ll i=t;i!=s;i=pre[i].v){
			es[pre[i].e].w-=mi;
			es[pre[i].e^1].w+=mi;
		}
		ans+=mi;
	}
	printf("%lld\n",ans);
}
int main(){
	n=read();m=read();s=read();t=read();
	for(ll i=1,u,v,w;i<=m;i++){
		u=read();v=read();w=read();
		add_edge(u,v,w);
		add_edge(v,u,0);
	}
	EK();
	return 0;
}
