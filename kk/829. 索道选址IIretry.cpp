#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=100005;
ll n;
ll a[N];
ll q[N],l=0,r=1;//dddl
ll f[N];
double slope(ll x,ll y){
	return (2.0*f[x]-2.0*f[y]-y*y+x*x)/(x-y);
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	for(ll i=1;i<=n;i++){
		while(l+1<r&&slope(q[l],q[l+1])<=i+i-1.0) ++l;
		f[i]=f[q[l]]+a[i]+(i-q[l])*(i-q[l]-1)/2;
		while(l+1<r&&slope(q[r-1],q[r-2])>=slope(q[r-1],i)) --r;
		q[r++]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}

