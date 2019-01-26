#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll q[N];//dddl
ll f[N];//dp 
ll n,a[N],l=0,r=1;
double slope(ll x,ll y){//slope through (2f[x]+x^2,x) and (2f[y]+y^2,y)
	return (2.0*f[x]+x*x-2*f[y]-y*y)/(x-y);
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	for(ll i=1;i<=n;i++){
		while(l+1<r&&slope(q[l],q[l+1])<=i*2.0-1) l++;
		f[i]=f[q[l]]+(i-q[l])*(i-q[l]-1)/2+a[i];
		while(l+1<r&&slope(q[r-1],q[r-2])>=slope(q[r-1],i)) r--;
		q[r++]=i;
	}
	cout<<f[n]<<endl;
	return 0;
}
