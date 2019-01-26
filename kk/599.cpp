//599ÍöÁé¶Ü£ºË¼Â·£ºÉ¨ÃèÏß¶Î+ln.sum
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ln[1000005],n,sum,maxb,ans;
int main(){
	freopen("shield.in","r",stdin);
	freopen("shield.out","w",stdout);
	scanf("%lld",&n);
	ll a,b;
	for(ll i=1;i<=n;i++){
		scanf("%lld %lld",&a,&b);
		ln[a]++; ln[b+1]--;
		maxb=max(b,maxb);
	}
	for(ll i=1;i<=maxb;i++){
		sum+=ln[i];
		ans=max(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
