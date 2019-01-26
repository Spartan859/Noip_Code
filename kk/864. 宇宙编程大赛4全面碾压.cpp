#include<bits/stdc++.h>
#define N 200005
#define I 100000
#define ll long long
using namespace std;
ll bit[N],ans[N];
ll n;
struct rcr{
	ll s,t;
	ll id;
}ts[N];
bool cmp(const rcr &a,const rcr &b){
	return a.t<b.t||a.t==b.t&&a.s<b.s;
}
inline void addd(ll x,ll a){
	for(ll i=x;i<=I;i+=(i&(-i))) bit[i]+=a;
}
inline ll query(ll x){
	ll sum=0;
	for(ll i=x;i;i-=(i&(-i))) sum+=bit[i];
	return sum;
}
int main(){
	freopen("domination.in","r",stdin);
	freopen("domination.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&ts[i].t);
	for(ll i=1;i<=n;i++) scanf("%lld",&ts[i].s),ts[i].s+=2,ts[i].id=i;
	sort(ts+1,ts+n+1,cmp);
	for(ll i=1;i<=n;i++){
		ans[ts[i].id]=i-1-query(ts[i].s);
		addd(ts[i].s,1);
	}
	for(ll i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}
