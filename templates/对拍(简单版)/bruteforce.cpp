#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=0;
ll n;
int main(){
	freopen("code.in","r",stdin);
	freopen("code.bfout","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) ans+=i;
	printf("%lld\n",ans);
	return 0;
}

