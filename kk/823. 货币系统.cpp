#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll f[25005],a[105],n,T,ans;
int main() {
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    scanf("%lld",&T);
    for (;T--;ans=0){
        memset(f,0,sizeof(f));
		f[0]=1;
        scanf("%d",&n);
        for(ll i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(ll i=1;i<=n;i++) {
            if (!f[a[i]]){
                ans++;
                for(ll j=a[i];j<=a[n];j++)
                    f[j]=(f[j-a[i]]||f[j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
