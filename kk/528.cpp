#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,h,ans;
int main(){
	cin>>n>>h;
	for(ll i=1,s=0,a;i<=n;i++){
		cin>>a;
		s+=a;
		ans=max(ans,(s-h+i-1)/i);
	}
	cout<<ans;
	return 0;
}
