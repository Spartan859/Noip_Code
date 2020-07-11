#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
/*
先将所有s放入trie
query(i,rk) 与 i异或和第rk大的01串
*/
ll n,k;
ll a[N],s[N];
ll trie[N*32][2],sz[N*32],tot;
ll ans=1;
struct pq{
	ll id,rk,w;
	bool operator < (const pq &a)const{
		return w<a.w;
	}
};
priority_queue<pq> q; 
inline void ins(ll x){
	ll u=0;
	for(ll i=31,ch;i>=0;--i){
		ch=(x>>i)&1;
		if(!trie[u][ch]) trie[u][ch]=++tot;
		u=trie[u][ch];++sz[u];
	}
}
inline ll query(ll x,ll rk){
	ll u=0,ans=0;
	for(ll i=31,ch;i>=0;--i){
		ch=(x>>i)&1;
		if(trie[u][ch^1]&&rk<=sz[trie[u][ch^1]]) u=trie[u][ch^1],ans|=1LL<<i;
		else rk-=sz[trie[u][ch^1]],u=trie[u][ch];
	}
	return ans;
}

int main(){
	scanf("%lld%lld",&n,&k);k<<=1;
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	ins(0);
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
		ins(s[i]);
	}
	for(ll i=0;i<=n;i++) q.push((pq){i,1,query(s[i],1)});
	for(ll i=1;i<=k;i++){
		pq tmp=q.top();ans+=tmp.w;q.pop();
		if(tmp.rk<n) q.push((pq){tmp.id,tmp.rk+1,query(s[tmp.id],tmp.rk+1)});
	}
	printf("%lld\n",(ans>>1));
	return 0;
}

