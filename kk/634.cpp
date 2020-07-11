#include <bits/stdc++.h>
#define ll long long
#define N 200005 
using namespace std;
ll l,r=1;
ll n,f[N],lnb[N],sum[N],q[N],tmp;//f[i]=f[j]+i-j-1
//q为单调队列 
int main(){
	freopen("mane.in","r",stdin);
	freopen("mane.out","w",stdout);
    scanf("%lld",&n);
    for (int i=1;i<=n;++i){
    	scanf("%lld",&tmp);
		sum[i]=sum[i-1]+tmp;
	}
    for (int i=1;i<=n;++i) {
        while (l+1<r&&sum[i]>=sum[q[l+1]]+lnb[q[l+1]]) l++;
        f[i]=f[q[l]]+1;
        lnb[i]=sum[i]-sum[q[l]];
        while (l<r&&sum[q[r-1]]+lnb[q[r-1]]>sum[i]+lnb[i]) r--;
        q[r++]=i;
    }
    printf("%lld",n-f[n]);
    return 0;
}
