#include<bits/stdc++.h>
#define MXBIT 10005
#define H 10000
#define W 10000
#define ll long long
using namespace std;
ll bit[MXBIT];
ll n,anssz[200005],ans,m;
struct rsndoll{
	ll w,h,id;
}d[200005];
bool cmp(const rsndoll &a,const rsndoll &b){
	return a.h<b.h||a.h==b.h&&a.w<b.w;
}
inline void addp(ll x,ll a){
	for(ll i=x;i<=W;i+=(i&(-i))) bit[i]+=a;
}
inline ll query(ll x){
	ll sum=0;
	for(ll i=x;i;i-=(i&(-i))) sum+=bit[i];
	return sum;
}
int main(){
	scanf("%lld %lld",&m,&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld %lld",&d[i].w,&d[i].h);
		d[i].id=i;
	}
	sort(d+1,d+n+1,cmp);
	for(ll i=1;i<=n;i++){
		addp(d[i].w,1);
		ans+=i-query(d[i].w);
	}
	cout<<ans<<endl;
	return 0;
}
