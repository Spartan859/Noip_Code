#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ans;

int main(){
	scanf("%lld %lld",&n,&k);
	ans=n*k;
	for(ll l=1,r,Nx;l<=min(n,k);l=r+1){
		Nx=k/l;
		r=min(k/Nx,n);
		ans-=Nx*(r-l+1)*(r+l)/2;
	}
	printf("%lld\n",ans);
	return 0;
}
