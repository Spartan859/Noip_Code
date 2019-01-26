#include<bits/stdc++.h>
#define ll long long
#define inf 2147483640
#define N 100005
using namespace std;
ll nxt[N],pre[N],a[N],rank[N];
ll n;

ll cmp(ll x,ll y) {
    return a[x]<a[y];
}
int main() {
    scanf("%lld",&n);
    for (ll i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        rank[i]=i;
    }
    sort(rank+1,rank+1+n,cmp);
    for (ll i=1;i<=n;i++) {
        pre[rank[i]]=rank[i-1];
        nxt[rank[i]]=rank[i+1];
    }
    ll ans=0;
    for (ll i=n;i>=2;i--) {
        ll l=inf,r=inf;
        if (pre[i]!=0) l=a[i]-a[pre[i]];
        if (nxt[i]!=0) r=a[nxt[i]]-a[i];
        ans+=min(l,r);
        nxt[pre[i]]=nxt[i];
        pre[nxt[i]]=pre[i];
    }
    printf("%lld",ans+a[1]);
    return 0;
}
