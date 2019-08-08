#include<bits/stdc++.h>
#define ERR 1e-6
#define N 200005
#define ll long long
using namespace std;
ll n,k;
double l=0,r=10000,mid,ans,s[N],MIN[N];
double x[N];
bool OK(double mid){
	double tans=0.0;
	memset(s,0,sizeof(s));
	memset(MIN,0,sizeof(MIN));
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+x[i]-mid;
		MIN[i]=min(MIN[i-1],s[i]);
	}
	for(ll i=k;i<=n;i++) tans=max(tans,s[i]-MIN[i-k]);
	if(tans>ERR) return 1;
	return 0;
}
int main(){
	freopen("god6.in","r",stdin);
	freopen("god6.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(ll i=1;i<=n;i++) scanf("%lf",x+i);
	while(r-l>ERR){
		mid=l+(r-l)/2;
		if(OK(mid)) ans=l=mid;
		else r=mid;
	}
	if(ans<=ERR) cout<<"0.00"<<endl;
	else cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}
