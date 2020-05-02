#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int main(){
	ll ansx=0;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		ll ans=0;
		for(ll m=1;m<=sqrt(i);m++){
			if(i%m==0){
				ans+=(m+2)/3;
				
			} 
				ifans+=(i/m+2)/3;
		}
		ansx+=ans;
	}
	cout<<ansx<<endl;
	return 0;
}

