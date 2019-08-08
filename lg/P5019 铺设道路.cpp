#include<bits/stdc++.h>
#define N 100005 
#define ll long long
using namespace std;
ll n,a[N],ans;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",a+i);
		if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
	}
	printf("%lld\n",ans);
	return 0;
} 
