#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
ll n,L,s[N],f[N],p[N];
int main(){
    scanf("%lld%lld",&n,&L);
    for(ll i=1,x;i<=n;++i)
        scanf("%lld",&x),s[i]=s[i-1]+x;
    fill(f+1,f+n+1,2e18);
    for (ll i=1;i<=n;i++)
        for (ll j=p[i-1];j<=i-1;j++){
            if (f[j]+(s[i]-s[j]-L)*(s[i]-s[j]-L)<f[i]){
                f[i]=f[j]+(s[i]-s[j]-L)*(s[i]-s[j]-L);
                p[i]=j;
            }
        }
    printf("%lld\n",f[n]);
    return 0;
}
