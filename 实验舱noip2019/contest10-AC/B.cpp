#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,ans=1;
ll inv[N],fac[N],sz[N];
struct edge{
	ll to,nxt;
}es[N*2];ll head[N],cnt=1;
inline void add_edge2(ll u,ll v){
	es[++cnt]=(edge){v,head[u]};head[u]=cnt;
	es[++cnt]=(edge){u,head[v]};head[v]=cnt;
}
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
void dfs(ll x,ll fa){
	sz[x]=1;
	for(ll i=head[x];i;i=es[i].nxt){
		ll y=es[i].to;
		if(y==fa) continue;
		dfs(y,x);
		sz[x]+=sz[y];
		ans=ans*inv[sz[y]]%mod;
	}
	ans=ans*fac[sz[x]-1]%mod;
}
inline ll ksm(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

int main(){
	n=read();
	for(ll i=1,x,y;i<=n-1;i++){
		x=read();y=read();
		add_edge2(x,y);
	}
	fac[0]=1;
	for(ll i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	//cout<<fac[n]<<endl;
	inv[n]=ksm(fac[n],mod-2);
	//cout<<inv[n]<<endl;
	for(ll i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
