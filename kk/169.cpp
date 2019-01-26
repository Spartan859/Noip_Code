#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
struct cc{
	ll x,y,r;
}x[1005];
bool its(cc c1,cc c2){
	if((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y)<(c1.r+c2.r)*(c1.r+c2.r)&&(c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y) > (c1.r-c2.r)*(c1.r-c2.r))
		return 1;
	return 0;
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>x[i].x>>x[i].y>>x[i].r;
	for(ll i=1;i<=n-1;i++)
	    for(ll j=i+1;j<=n;j++)
	    	if(its(x[i],x[j])) ans++;
	ans+=n+1;
	cout<<ans<<endl;
	return 0;
}
