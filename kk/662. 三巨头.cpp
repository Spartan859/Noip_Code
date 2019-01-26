#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define H 20
using namespace std;
ll n,q;
ll cnt,f[N],hd[N],fa[N][H+2],vst[N];
//qxx-template
struct data{ll t,nxt;} e[N<<1];
void add(ll u,ll v) { e[++cnt].t=v; e[cnt].nxt=hd[u]; hd[u]=cnt;}
void add2 (ll u,ll v) { add(u,v); add(v,u);}
//qxx-end

struct lca_with_dist{
	ll nd,dst;
}tmp,tmp2,ftmp;

void dfs(ll x){
    vst[x]=1;
    for(ll i=1;i<=H&&f[x]>=(1<<i);i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(ll i=hd[x];i;i=e[i].nxt){
        if (vst[e[i].t]) continue;
        f[e[i].t]=f[x]+1; fa[e[i].t][0]=x;
        dfs(e[i].t);
    }
}

ll lca(ll x,ll y){ 
    if (f[x]<f[y]) swap(x,y);
    ll d=f[x]-f[y];
    for(ll i=0;i<=H;i++)
        if((1<<i)&d) x=fa[x][i];
    for(ll i=H;i>=0;i--)
        if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    if(x==y) return x;
    else return fa[x][0];
}

inline lca_with_dist dist(ll x,ll y,ll z){
	ll l=lca(x,y);
	ll ans=f[x]+f[y]-2*f[l];
	ll r=lca(l,z);
	return (lca_with_dist){l,ans+f[l]+f[z]-2*f[r]};
}
int main(){
    scanf("%lld %lld",&n,&q);
    for(ll i=1,u,v;i<n;i++)
        scanf("%lld %lld",&u,&v),add2(u,v);
    dfs(1);
    for(ll i=1,x,y,z;i<=q;i++){
        scanf("%lld %lld %lld",&x,&y,&z);
        tmp=dist(x,y,z);
        tmp2=dist(x,z,y);
        if(tmp.dst<tmp2.dst) ftmp=tmp;
        else ftmp=tmp2;
        //--------
        tmp=dist(y,z,x);
        if(tmp.dst<ftmp.dst) ftmp=tmp;
        cout<<ftmp.nd<<' '<<ftmp.dst<<endl;
    }
    return 0;
}
