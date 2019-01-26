#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long
#define mod 10007
using namespace std;
ll num[100010],color[100010],n,m;
ll cnt[100010][2],nm[100010][2],sumj[100010][2],sum[100010][2],ans;
int main()
{
	//freopen("int.txt","r",stdin);
	//freopen("my.txt","w",stdout);
	int i,j;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;++i) scanf("%lld",&num[i]);
	for(i=1;i<=n;++i) scanf("%lld",&color[i]);
	for(i=1;i<=n;++i)
	 {
	 	int c=color[i],x=i%2;
	 	cnt[c][x]++;
	 	if(cnt[c][x]>1) ans+=(nm[c][x]*num[i]%mod+sumj[c][x]+(cnt[c][x]-1)*i*num[i]%mod+i*sum[c][x]%mod)%mod;
	 	ans%=mod;
	 	nm[c][x]=(nm[c][x]+i)%mod; sumj[c][x]=(sumj[c][x]+i*num[i])%mod; sum[c][x]=(sum[c][x]+num[i])%mod;
	}
	ans%=mod;
    printf("%lld\n",ans);
    return 0;
}
