#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=200005,N=100005;
ll n,m;
ll st;ll dp[N];
queue<ll> q;
struct qxx{
	ll to,nxt;
}es[M];ll head[N],tot;
void add_e(ll x,ll y){
	es[++tot]=(qxx){y,head[x]};
	head[x]=tot;
}
ll ind[N];
void bfs(){
	q.push(st);
	while(!q.empty()){
		ll x=q.front();q.pop();
		for(ll i=head[x];i;i=es[i].nxt){
			ll y=es[i].to;
			dp[y]=max(dp[y],dp[x]+1);
			if(--ind[y]==0) q.push(y);
		}
	}
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1,u,v;i<=m;i++){
		scanf("%lld%lld",&u,&v);
		add_e(u,v);
		++ind[v];
	}
	for(ll i=1;i<=n;i++) if(ind[i]==0){
		dp[i]=1;q.push(i);
	} 
	bfs();
	for(ll i=1;i<=n;i++) printf("%lld\n",dp[i]);
	return 0;
}

