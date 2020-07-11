#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T;
inline ll gcd(ll x,ll y){
	if(x<y) swap(x,y);
	ll tmp;
	while(y){
		tmp=y;
		y=x%y;
		x=tmp;
	}
	return x;
}
int main(){
	scanf("%lld",&T);
	while(T--){
		ll pa,pb,k;
		scanf("%lld%lld%lld",&pa,&pb,&k);
		if(k==1){
			puts("No");continue;
		}
		if(pa==pb){
			puts("Yes");continue;
		}
		ll gcdx=gcd(pa,pb);
		pa/=gcdx;pb/=gcdx;
		if(pa>pb) swap(pa,pb);
		if((pb-2)/pa+1>=k) puts("No");
		else puts("Yes");
	}
	return 0;
}

