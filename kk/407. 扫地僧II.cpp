#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
ll a[2005],sum[2005],f[2005][2005],ans=2e18,p[2005][2005],n;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i+n]=a[i];
        sum[i]=sum[i-1]+a[i];
        p[i][i]=i;
    }
    for(ll i=n+1;i<=n+n;i++){
        sum[i]=sum[i-1]+a[i];
        p[i][i]=i;
    }
    for (ll i=n+n-1;i>=1;i--){
        for(ll j=i+1;j<=n+n;j++){
            f[i][j]=2e18;
            for (ll k=p[i][j-1];k<=p[i+1][j];k++)
                if(f[i][k]+f[k+1][j]+(sum[j]-sum[i-1])<f[i][j]) f[i][j]=f[i][k]+f[k+1][j]+(sum[j]-sum[i-1]),p[i][j]=k;
        }
    }
    for (ll i=1;i<=n;i++) ans=min(ans,f[i][i+n-1]);
    printf("%lld\n",ans);
    return 0;
}
