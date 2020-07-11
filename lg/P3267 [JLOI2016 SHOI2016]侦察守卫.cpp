#include<bits/stdc++.h>
#define ll long long
const ll N=500005,D=23,INF=1e18;
using namespace std;
ll n,d;
ll w[N]; 
ll m;
ll kz[N];//kz[i]=1: 需要被控制
vector<ll> es[N]; 
ll cv[N][D],uc[N][D];

void trdp(ll x,ll fa){
	if(kz[x]) cv[x][0]=uc[x][0]=w[x];
	for(ll i=1;i<=d;i++) cv[x][i]=w[x];
	cv[x][d+1]=INF;
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(y==fa) continue;
		trdp(y,x);
		for(ll i=d;i>=0;i--)
			cv[x][i]=min(cv[x][i]+uc[y][i],cv[y][i+1]+uc[x][i+1]);
		for(ll i=d;i>=0;i--) cv[x][i]=min(cv[x][i+1],cv[x][i]);
		for(ll i=d;i>=1;i--)
			uc[x][i]+=uc[y][i-1];
		uc[x][0]=cv[x][0];
		for(ll i=1;i<=d;i++) uc[x][i]=min(uc[x][i],uc[x][i-1]);
	}
}
int main(){
	scanf("%lld%lld",&n,&d);
	for(ll i=1;i<=n;i++) scanf("%lld",w+i);
	scanf("%lld",&m);
	for(ll i=1,u;i<=m;i++){
		scanf("%lld",&u);
		kz[u]=1;
	}
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u);
	}
	trdp(1,0);
	printf("%lld\n",cv[1][0]);
	return 0;
}

