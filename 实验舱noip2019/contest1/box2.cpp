#include<bits/stdc++.h>
#define N 10005
#define ll long long
using namespace std;
ll n,a[N],b[N],T;
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		ll ax=0,bx=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld",a+i,b+i);
			ax+=a[i];
			bx+=b[i];
		}
		cout<<(ax+bx-n+1)/2<<endl;
	}
	return 0;
}
