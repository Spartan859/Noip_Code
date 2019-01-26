#include<bits/stdc++.h>
#define ll long long
#define inf 100000000005
using namespace std;
set<ll> s;
set<ll>::iterator lb;
ll n,x,ans;
inline ll absv(ll v){return v>0?v:-v;}
int main(){
    scanf("%lld%lld",&n,&ans);
    s.insert(ans);
    for(ll i=1;i<n;i++){
        scanf("%lld",&x);
        lb=s.upper_bound(x);
        ll minv=inf;
        if(lb!=s.end())minv=min(minv,absv(*lb-x));
        if(lb!=s.begin())minv=min(minv,absv((*--lb)-x));
        ans+=minv;
        s.insert(x);
    }
    printf("%lld",ans);
    return 0;
}
