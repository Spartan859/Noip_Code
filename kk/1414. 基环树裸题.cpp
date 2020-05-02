#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
struct qxx{
	ll to,nxt;
}es[N*2];
ll hd[N],num=-1;
ll n,rt,ansb=N,ansid;
ll vst[N],fa[N];
ll loop[N];
inline void add_edge(ll a,ll b){
	es[++num]=(qxx){b,hd[a]};
	hd[a]=num;
}
bool findloop(ll u){
	vst[u]=1;
	bool rr=false;
	for(ll i=hd[u];i!=-1;i=es[i].nxt)
		if(i!=fa[u]){
			ll v=es[i].to;
			if(vst[v]==0){
				fa[v]=i^1;
				rr=(rr||findloop(v));
			}else if(vst[v]==1){
				rt=v;
				rr=true;
				loop[++loop[0]]=v;
			}
		}
	vst[u]=2;
	if(u==rt) rr=false;
	if(rr) loop[++loop[0]]=u;
	return rr;
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) hd[i]=fa[i]=-1;
	for(ll i=1,a,b;i<=n;i++){
		scanf("%lld%lld",&a,&b);
		add_edge(a,b);
		add_edge(b,a);
	}
	findloop(1);
	for(ll i=1;i<=loop[0];i++)
		if(loop[i]<ansb) ansb=loop[i],ansid=i;
	if(loop[(ansid-1+loop[0]-1)%loop[0]+1]>loop[(ansid+1)%loop[0]]){
		for(ll i=ansid;i<=loop[0];i++) cout<<loop[i]<<' ';
		for(ll i=1;i<ansid;i++) cout<<loop[i]<<' ';
	}else{
		for(ll i=ansid;i>=1;i--) cout<<loop[i]<<' ';
		for(ll i=loop[0];i>ansid;i--) cout<<loop[i]<<' ';
	}
	return 0;
}
