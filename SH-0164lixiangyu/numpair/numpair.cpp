#include<bits/stdc++.h>
#define INF 2e18
#define ll long long
using namespace std;
ll n,ans=INF;
ll exgcd(ll a,ll b){
	if(b!=1&&b!=0) return a/b+exgcd(b,a%b);
    if(b) return a-1;
    else return INF;
}
int main(){
	freopen("numpair.in","r",stdin);
	freopen("numpair.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) ans=min(ans,exgcd(i,n));
	printf("%lld",ans);
	return 0;
}
