#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b;
ll ans;
int main(){
	scanf("%lld %lld",&a,&b);
	for(ll i=1;a-i*b>0;i++){
		ans=max(ans,(a-i*b)*(i+1));
	}
	cout<<ans<<endl;
	return 0;
}
