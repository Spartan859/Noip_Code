#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;double x,ans;
int main(){
	while(cin>>x>>n){
		ans=1.0;
		for(ll i=1;i<=n;i++) ans*=x;
		cout<<fixed<<setprecision(10000)<<ans<<endl;
	}
	return 0;
} 
