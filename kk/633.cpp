#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define ERR 1e-6
using namespace std;
ll x[N],n,k;
double kx[N],s[N],MIN[N],ans=0;
bool OK(double m){
	double ans=0;
	for(int i=1;i<=n;i++) kx[i]=x[i]-m;
	for(int i=1;i<=n;i++) {
		s[i]=s[i-1]+kx[i];
		MIN[i]=min(MIN[i-1],s[i]);
	}
	for(int i=k;i<=n;i++) ans=max(ans,s[i]-MIN[i-k]);
	if(ans>0) return 1;
	return 0;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>x[i];
	double l=0,r=10005;
	while(r-l>ERR){
		double mid=(r+l)/2;
		if(OK(mid)) ans=l=mid;
		else r=mid;
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}
