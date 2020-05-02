#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
const ll mod=1e9+7;
ll sum[N*32],ls[N*32],rs[N*32],rt[N*32];
ll tot,n,m;
ll vis[N],a[N],b[N];
ll ans;
void build(ll l,ll r,ll &root){
    root=++tot;
    sum[root]=0;
    if(l==r) return;
    ll mid=l+r>>1;
    build(l,mid,ls[root]);
    build(mid+1,r,rs[root]);
}
void update(ll l,ll r,ll root,ll last,ll q,ll val){
    sum[root]=sum[last];
    ls[root]=ls[last];
    rs[root]=rs[last];
    if(l==r){
        sum[root]+=val;
        return;
    }
    ll mid=l+r>>1;
    if(mid>=q)
        update(l,mid,ls[root]=++tot,ls[last],q,val);
    else
        update(mid+1,r,rs[root]=++tot,rs[last],q,val);
    sum[root]=sum[ls[root]]+sum[rs[root]];
}
ll query(ll l,ll r,ll root,ll ql,ll qr){
    if(l>=ql&&r<=qr) return sum[root];
    ll mid=l+r>>1;
    ll ans=0;
    if(mid>=ql)
        ans+=query(l,mid,ls[root],ql,qr);
    if(mid<qr)
        ans+=query(mid+1,r,rs[root],ql,qr);
    return ans;
}
int main(){
	//freopen("sequence.in","r",stdin);
	//freopen("sequence.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld",a+i),b[i]=a[i];
    sort(b+1,b+1+n);
    ll sz=unique(b+1,b+1+n)-(b+1);
    for(ll i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+sz,a[i])-b;
    build(1,n,rt[0]);
    for(ll i=1;i<=n;i++){
        if(!vis[a[i]])
            update(1,n,rt[i]=++tot,rt[i-1],i,1);
        else{
            update(1,n,rt[i]=++tot,rt[i-1],i,1);
            ll del=++tot;
            update(1,n,del,rt[i],vis[a[i]],-1);
            rt[i]=del;
        }
        vis[a[i]]=i;
    }
    for(ll l=1;l<=n;l++)
    	for(ll r=l;r<=n;r++){
    		ll tmp=query(1,n,rt[r],l,r);
    		tmp=tmp*tmp%mod;
    		ans=(ans+tmp)%mod;
		}
    printf("%lld\n",ans);
    return 0;
}
