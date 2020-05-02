#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n,m,ans;
ll a[N];
bool ok(ll x){
	ll cnt=1;
	for(ll i=2,nw=1;i<=n;i++)
		if(a[i]-a[nw]>=x) nw=i,cnt++;
	if(cnt>=m) return 1;
	else return 0;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	ll l=1,r=a[n],mid;
	while(l<r){
		mid=l+r>>1;
		if(ok(mid)) ans=mid,l=mid+1;
		else r=mid;
	}
	printf("%lld\n",ans);
	return 0;
}

