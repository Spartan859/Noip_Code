#include<bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
ll n,ans;
ll f[N],w[N],dp[N],sx[N];
vector<ll> es[N];
inline ll read(){
	ll res=0,f=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*f;
}
void dfs(ll x){
	if(es[x].size()==0) ans+=w[x];
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		dfs(y);
		ans
	}
}
int main(){
	n=read();
	for(ll i=2;i<=n;i++) f[i]=read(),es[f[i]].push_back(i);
	for(ll i=1;i<=n;i++) w[i]=read();
	dfs(1);
	for(ll i=1;i<=n;i++){
		ans=0;
		dfs(i);
		printf("%lld ",ans);
	} 
	return 0;
}
