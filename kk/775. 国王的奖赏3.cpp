#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll n,k,fl[N],fr[N],p[N],sum[N],sum2[N],ans;
int main(){
	freopen("reward3.in","r",stdin);
	freopen("reward3.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(ll i=1;i<=n;i++) scanf("%lld",p+i),sum[i]=sum[i-1]+p[i];
	for(ll i=n;i>=1;i--) sum2[i]=sum2[i+1]+p[i];
	for(ll i=1;i<=n;i++){
		if(i<=k) fl[i]=fl[i-1]+p[i];
		else fl[i]=max(fl[i-1],sum[i]-sum[i-k]);
	}
	for(ll i=n;i>=1;i--){
		if(n-i+1<=k) fr[i]=fr[i+1]+p[i];
		else fr[i]=max(fr[i+1],sum2[i]-sum2[i+k]);
	}
	for(ll i=1;i<=n-2;i++) ans=max(ans,fl[i]+fr[i+2]);
	printf("%lld\n",ans);
	return 0;
}
