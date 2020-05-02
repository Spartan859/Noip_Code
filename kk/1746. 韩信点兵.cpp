#include<bits/stdc++.h>
#define N 300005
#define ll long long
using namespace std;
ll n,m; 
ll a[N];
int main(){
	freopen("hanxin.in","r",stdin);
	freopen("hanxin.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	scanf("%lld",&m);
	for(ll i=1,x,y;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		ll sum=0;
		for(ll i=x;i<=n;i+=y) sum+=a[i];
		printf("%lld\n",sum);
	}
	return 0;
}

