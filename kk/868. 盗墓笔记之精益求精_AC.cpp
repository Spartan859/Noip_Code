#include<bits/stdc++.h>
#define INF 2e18
#define N 305
#define ll long long
#define K min(W,j+w[i])
#define ERR 1e-6
using namespace std;
ll n,W,w[N],v[N];double f[1005],l=0.0,r=300000.0,mid,ans;
bool OK(double z){
	fill(f+1,f+W+1,-INF);
	for(ll i=1;i<=n;i++)
		for(ll j=W;j>=0;j--)
			f[K]=max(f[K],f[j]+v[i]-w[i]*z);
	return f[W]>=0;
}
int main(){
	scanf("%lld %lld",&n,&W);
	for(ll i=1;i<=n;i++) scanf("%lld %lld",&w[i],&v[i]);
	while(r-l>=ERR){
		mid=(l+r)/2;
		if(OK(mid)) l=ans=mid;
		else r=mid;
	}
	cout<<fixed<<setprecision(0)<<ans*1000<<endl;
	return 0;
}
