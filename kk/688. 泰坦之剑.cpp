#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
double a,b,ans,dvs;
int main(){
	//freopen
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		cin>>a>>b;
		ans+=a*b;
		dvs+=b;
	}
	ans/=dvs;
	cout<<fixed<<setprecision(1)<<ans<<endl;
	return 0;
} 
