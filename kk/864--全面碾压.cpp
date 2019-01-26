#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bit[105][100005];
ll n,s[200005],t[200005];
ll smax,tmax;
inline void add_point(ll x,ll y,ll a){
	for(ll i=x;i<=tmax;i+=i&(-i))
		for(ll j=y;j<=smax;j+=j&(-j))
			bit[i][j]+=a;
}
inline ll query(ll x,ll y){
	ll sum=0;
	for(ll i=x;i;i-=i&(-i))
		for(ll j=y;j;j-=j&(-j))
			sum+=bit[i][j];
	return sum;
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",s+i),smax=max(smax,s[i]);
	for(ll i=1;i<=n;i++) scanf("%lld",t+i),tmax=max(tmax,t[i]),t[i]++;
	for(ll i=1;i<=n;i++){
		add_point(t[i],s[i],1);
	}
	for(ll i=1;i<=n;i++){
		cout<<query(t[i],smax)-query(t[i],s[i])<<' ';
	}
	return 0;
}
