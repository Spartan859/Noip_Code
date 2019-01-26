#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y;
ll calcsum_ysh(ll x){
	ll ans=0;
	for(ll l=1,r,Nx;l<=x;l=r+1){
		Nx=x/l;
		r=x/Nx;
		ans+=Nx*(r-l+1)*(r+l)/2;
	}
	return ans;
}
int main(){
	scanf("%lld %lld",&x,&y);
	printf("%lld\n",calcsum_ysh(y)-calcsum_ysh(x-1));
	return 0;
}
