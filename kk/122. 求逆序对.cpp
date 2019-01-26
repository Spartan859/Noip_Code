#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bst[100005];
ll n,x,ans;
void point_add(ll i,ll z){
	while(i<=100000){
		bst[i]=bst[i]+z;
		i+=(i&(-i));
	}
}
ll query(ll i){
	ll sum=0;
	for(;i;i-=(i&(-i))) sum+=bst[i];
	return sum;
}
int main(){
	//freopen("reverse.in","r",stdin);
	//freopen("reverse.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&x);
		ans+=i-query(x+1)-1;
		point_add(x+1,1);
	}
	cout<<ans<<endl;
	return 0;
}
