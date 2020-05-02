#include<bits/stdc++.h>
#define N 50005
#define ll long long
using namespace std;

const ll mod = 998244353;

ll n,Q,k;
ll H[N], X[N], P[N], tot;
ll fa[N], dep[N], dfn[N], invdfn[N], siz[N], son[N], top[N];

inline void add(ll x,ll y) {
    P[++tot]=y;
    X[tot]=H[x];
    H[x]=tot;
}

struct Query {
    ll x,y,id;
} query[N];

ll ans[N];


bool cmp_by_x(Query a, Query b) {
    return a.x<b.x;
}

void dfs1(ll x) {
    dep[x] = dep[fa[x]] + 1;
    siz[x] = 1;
    for(ll i=H[x]; i; i=X[i]) {
        dfs1(P[i]);
        siz[x] += siz[P[i]];
        if(siz[P[i]]>siz[son[x]]) {
            son[x] = P[i];
        }
    }
}

ll tim;

void dfs2(ll x) {
    dfn[x] = ++tim;
    if(!top[x]) top[x]=x;
    if(son[x]) top[son[x]] = top[x], dfs2(son[x]);
    for(ll i=H[x]; i; i=X[i]) {
        if(P[i] == son[x]) continue;
        dfs2(P[i]);
    }
}

ll pow(ll a,ll b,ll p) {
    ll ret = 1%p;
    while(b) {
        if(b&1) ret = ret*a%p;
        b>>=1;
        a=a*a%p;
    }
    return ret;
}

const ll N4 = N*4;
struct SEGMENT_TREE {
    ll sum[N4], cnt[N4], pre[N4];
    void updsum(ll o) {
        sum[o] = (sum[o<<1] + sum[o<<1|1])%mod;
    }
    void bd(ll o,ll l,ll r) {
        if(l==r) {
            pre[o] = (pow(dep[invdfn[l]],k,mod) - pow(dep[invdfn[l]]-1,k,mod) + mod)%mod;
            cnt[o] = sum[o] = 0;
        } else {
            ll mid=(l+r)/2;
            bd(o<<1,l,mid);
            bd(o<<1|1,mid+1,r);
            pre[o] = (pre[o<<1]+pre[o<<1|1])%mod;
        }
    }
    void build() {
        bd(1,1,n);
    }
    void down(ll o) {
        if(cnt[o]>0) {
            sum[o<<1] = (sum[o<<1]+(pre[o<<1]*cnt[o])%mod)%mod;
            cnt[o<<1] += cnt[o];
            sum[o<<1|1] = (sum[o<<1|1]+(pre[o<<1|1]*cnt[o])%mod)%mod;
            cnt[o<<1|1] += cnt[o];
            cnt[o]=0;
        }
    }
    void add(ll o,ll l,ll r,ll L,ll R) {
        if(l == L && r == R) {
            sum[o] = (sum[o]+pre[o]) % mod;
            cnt[o] ++;
        } else {
            ll mid=(l+r)/2;
            down(o);
            if(R<=mid) add(o<<1,l,mid,L,R);
            else if(L>mid) add(o<<1|1,mid+1,r,L,R);
            else add(o<<1,l,mid,L,mid), add(o<<1|1,mid+1,r,mid+1,R);
            updsum(o);
        }
    }
    void add(ll l,ll r) {
        assert(l<=r);
        add(1,1,n,l,r);
    }
    ll ask(ll o,ll l,ll r,ll L,ll R) {
        if(l==L && r == R) {
            return sum[o];
        } else {
            ll mid=(l+r)/2;
            down(o);
            if(R<=mid) return ask(o<<1,l,mid,L,R);
            else if(L>mid) return ask(o<<1|1,mid+1,r,L,R);
            else return (ask(o<<1,l,mid,L,mid) + ask(o<<1|1,mid+1,r,mid+1,R))%mod;
        }
    }
    ll ask(ll l,ll r) {
        assert(l<=r);
        return ask(1,1,n,l,r);
    }
} tree;

void prepare() {
    dfs1(1);
    dfs2(1);
    assert(tim == n);
    for(ll i=1; i<=n; i++) invdfn[dfn[i]] = i;
    tree.build();
}

void add_point(ll x) {
    while(x) {
        tree.add(dfn[top[x]], dfn[x]);
        x=fa[top[x]];
    }
}

ll ask(ll x) {
    ll ret = 0;
    while(x) {
        ret = (ret + tree.ask(dfn[top[x]], dfn[x]))%mod;
        x=fa[top[x]];
    }
    return ret;
}

int main() {
	#ifdef ONLINE_JUDGE 
	freopen("ragnarok.in","r",stdin);
	freopen("ragnarok.out","w",stdout);
	#endif
    scanf("%lld%lld%lld",&n,&Q,&k);

    for(ll i=2,x; i<=n; i++) {
        scanf("%lld",&x);
        add(x,i);
        fa[i]=x;
    }
    for(ll i=1; i<=Q; i++) {
        scanf("%lld%lld",&query[i].x,&query[i].y);
        query[i].id = i;
    }

    prepare();

    sort(query+1,query+Q+1,cmp_by_x);
    ll p = 1;
    for(ll i=1; i<=n; i++) {
        add_point(i);
        while(p <= Q && query[p].x == i) {
            ans[query[p].id] = ask(query[p].y);
            p++;
        }
    }
    
    for(ll i=1; i<=Q; i++)
        printf("%lld\n",ans[i]);
    return 0;
}
