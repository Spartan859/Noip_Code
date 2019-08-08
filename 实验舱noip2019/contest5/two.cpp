#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll X,T;
ll n,m,q;
ll ksm(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) res*=x,res%=mod;
		x=x*x,x%=mod;
		y>>=1;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input2.txt","r",stdin);
	freopen("output2.txt","w",stdout);
	#endif
	scanf("%lld%lld",&X,&T);
	if(X==1){
		while(T--){
			scanf("%lld%lld",&n,&m);
			q=(n-1)*(m-1);
			printf("%lld\n",ksm(2,q));
		}
	}
	return 0; 
}
