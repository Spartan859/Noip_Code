#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll HM=2e18+7,BS=131;
ll n;
string s;
set<ll> st;
ll minexpr(string s){
	ll i=0,j=1,k=0,ans;
	ll n=s.size();
	while(i<n&&j<n&&k<n){
		ll t=s[(i+k)%n]-s[(j+k)%n];
		if(!t) ++k;
		else{
			if(t>0) i=i+k+1;
			else j=j+k+1;
			if(i==j) j++;
			k=0; 
		}
	}
	ans=min(i,j);ll rt=0;
	for(i=0;i<n;i++) rt=(rt*BS+s[(ans+i)%n])%HM;
	return rt;
}
int main(){
	while(scanf("%lld",&n)!=EOF){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			cin>>s;ll k=minexpr(s);
			st.insert(k);
		}
		printf("%lld\n",st.size());
		st.clear();
	}
	return 0;
}

