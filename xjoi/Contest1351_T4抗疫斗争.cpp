#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int mod=998244353,N=1e6+77;
void inc(int &x,int y) 
{
	x=x+y>=mod?x+y-mod:x+y;
}
long long n;
int ans,val[N];
int work(long long x)
{
	long long ans=0;
	int sq=sqrt(x);
	for(int i=1;i<=sq;i++)ans+=(x/i);
	ans=(2*ans-1ll*sq*sq)%mod;
	return ans;
}
int main()
{
	scanf("%lld",&n);
	for(long long a=1;a<=n;a<<=1)
		inc(ans,1ll*(a-(a>>1))%mod*work(n/a)%mod);
	printf("%d",ans);
	return 0;
}
