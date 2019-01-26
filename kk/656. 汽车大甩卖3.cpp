#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],b[200005],f,l=1,r,mid,ans;
bool ok(ll x){
	ll j=1,lmt=f;
	for(ll i=x;i>=1;i--,j++){
		if(b[j]>=a[i]) continue;
		else{
			lmt-=a[i]-b[j];
			if(lmt<0) return 0;
		}
	}
	return 1;
}
bool cmp(const ll &a,const ll &b){
	return a>b;
}
int main(){
	freopen("car3.in","r",stdin);
	freopen("car3.out","w",stdout);
	cin>>n>>m>>f;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1,cmp);
	r=min(n,m);
	while(l<=r){
		mid=l+(r-l)/2;
		if(ok(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<m-ans<<endl;
	return 0;
} 
