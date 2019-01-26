#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n,m,nd[N],ans;
bool OK(ll x){
	ll q=0;
	for(ll i=n;i>=1;i--) q+=nd[i]/x;
	return q>=m;
}
int main(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>nd[i];
	sort(nd+1,nd+n+1);
	ll l=1,r=1e6,mid=0;
	while(l<=r){
		mid=l+(r-l)/2;
		if(OK(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
