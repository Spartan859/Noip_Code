#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=7e4+5;
ll head1[N],head[N],cnt1,cnt;
ll n,ind[N];
ll cntp,topo[N];
ll fa[N],sz[N],dep[N];
ll f[N][17];

struct node1 {
    ll to,next;
}es1[N*2];
void add1(ll u,ll v) {
    es1[++cnt1].to=v;
    es1[cnt1].next=head1[u];
    head1[u]=cnt1;
}
struct node {
    ll to,next;
} es[N*2];
void add(ll u,ll v) {
    es[++cnt].to=v;
    es[cnt].next=head[u];
    head[u]=cnt;
}
void toposort() {
    queue<ll>q;
    for (ll i=1; i<=n; i++)
        if(ind[i]==0)
            q.push(i);

    while (!q.empty()) {
        ll x=q.front();
        q.pop();
        topo[++cntp]=x;
        for (ll i=head1[x]; i!=0; i=es1[i].next) {
            ind[es1[i].to]--;
            if(!ind[es1[i].to])
                q.push(es1[i].to);
        }
    }
}
void initx(ll x) {
    f[x][0]=fa[x];
    for (ll i=1; i<=16; i++)
        f[x][i]=f[f[x][i-1]][i-1];
}
ll lca(ll x,ll y) {
    if (dep[x]<dep[y]) swap(x,y);
    for (ll i=16; i>=0; i--)
        if (f[x][i]!=0&&dep[f[x][i]]>=dep[y])
            x=f[x][i];
            
    if (x==y) return y;
    for (ll i=16; i>=0; i--)
        if (f[x][i]!=0&&f[y][i]!=0&&f[x][i]!=f[y][i]) {
            x=f[x][i];
            y=f[y][i];
        }
    return fa[x];
}
void buildft() {
    dep[n+1]=1;//³¬¼¶Ô´µãn+1 
    fa[n+1]=n+1;
    for (ll i=n,x; i>=1; --i) {
        x=topo[i];
        if (head1[x]==0) {//s -> n+1
            fa[x]=n+1;
            add(n+1,x);
            f[x][0]=n+1;
            dep[x]=2;
            continue;
        }
        ll lcatmp=es1[head1[x]].to;
        for (ll i=es1[head1[x]].next; i!=0; i=es1[i].next) {
            lcatmp=lca(lcatmp,es1[i].to);
        }
        fa[x]=lcatmp;
        add(fa[x],x);
        dep[x]=dep[fa[x]]+1;
        initx(x);
    }
}
void dfs(ll x){
    sz[x]=1;
    for (ll i=head[x]; i!=0; i=es[i].next) {
        dfs(es[i].to);
        sz[x]+=sz[es[i].to];
    }
}

int main(){
	freopen("dag.in","r",stdin);
	freopen("dag.out","w",stdout);
    scanf("%lld",&n);
    for (ll i=1,x; i<=n; i++) {
        scanf("%lld",&x);
        while (x!=0) {
            add1(i,x);
            ++ind[x];
            scanf("%lld",&x);
        }
    }
    toposort();
    buildft();
    dfs(n+1);
    for (ll i=1; i<=n; i++) printf("%lld\n",sz[i]-1);
    return 0;
}
