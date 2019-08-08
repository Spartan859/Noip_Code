#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
vector<ll> es[1505];
int main(){
	scanf("%lld",&n);
	for(ll i=1,ndi,ess;i<=n;i++){
		scanf("%lld:(%lld)",&ndi,&ess);
		printf("%lld %lld\n",ndi,ess);
	}
	return 0;
}
