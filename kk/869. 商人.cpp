#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll solve(ll x){
	if(x<=1) return x;
	ll rt=0,ed=sqrt(x);
	for(ll i=1;i<=ed;i++) rt+=n/i+i*(n/i-n/(i+1));
	if(ed*(ed+1)>n) rt-=ed;
	return rt;
}
int main(){
	freopen("merchant.in","r",stdin);
	freopen("merchant.out","w",stdout);
	scanf("%lld",&n);
	printf("%lld\n",solve(n));
	return 0;
}
