#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
namespace subtask1{
	inline ll gcd(ll x,ll y){
		if(x<y) swap(x,y);
		while(x%y){
			x%=y;
			if(x<y) swap(x,y);
		}
		return y;
	} 
}

int main(){
	scanf("%lld%lld",&n,&m);
	if(n<=1e12&&m<=1e12) printf("%lld\n",subtask1::gcd(n,m));
	return 0;
}
