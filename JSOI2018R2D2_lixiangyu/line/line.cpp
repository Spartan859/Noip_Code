#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define D 11000005
using namespace std;
ll n,m,cnt;
int rt[N];
int ls[D],rs[D];
int mx[D],mn[D];
ll sz[D],sm[D];

void ptadd(int &rt,ll l,ll r,ll p) {
    ls[++cnt]=ls[rt];rs[cnt]=rs[rt];
	sz[cnt]=sz[rt]+1;
	sm[cnt]=sm[rt]+p;
	rt=cnt;
    if(l==r) return;
    ll mid=(l+r)>>1;
    if(p<=mid) ptadd(ls[rt],l,mid,p);
    else ptadd(rs[rt],mid+1,r,p);
}

ll scqry(ll rt1,ll rt2,ll l,ll r,ll f,ll k) {
    if(!(sz[rt1]-sz[rt2])) return 0;
    ll szx=sz[rt1]-sz[rt2];
	ll smx=sm[rt1]-sm[rt2];
    if(l>=k+f)
		return smx-(2*k+2*f+szx-1)*szx/2;
    if(r<=k+f+szx-1) 
		return (2*k+2*f+szx-1)*szx/2-smx;
    ll mid=(l+r)>>1;
	ll lsz=sz[ls[rt1]]-sz[ls[rt2]];
    return scqry(ls[rt1],ls[rt2],l,mid,f,k)+scqry(rs[rt1],rs[rt2],mid+1,r,f+lsz,k);
}

int main(){
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1,x;i<=n;i++){
        scanf("%lld",&x);
        rt[i]=rt[i-1];
        ptadd(rt[i],1,1000000,x);
    }
    for(ll i=1,l,r,k;i<=m;i++){
        scanf("%lld%lld%lld",&l,&r,&k);
        printf("%lld\n",scqry(rt[r],rt[l-1],1,1000000,0,k));
    }
    return 0;
}
