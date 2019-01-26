#include<bits/stdc++.h>
#define ll long long
#define N 300005
using namespace std;
struct edge{
    ll nxt,to,dis;
}e[2*N],q[2*N];
//-----------
struct length{
    ll len,lca,u,v;
}len[N];
//------------
ll head[N],headq[N],num,ret;
ll n,m,a[N],f[N],s[N],dis[N],ans;
ll cnt,maxlen;
bool vst[N];
//------

inline void add_edge(ll x,ll y,ll d){
    e[++cnt].nxt=head[x];
    e[cnt].to=y;
    e[cnt].dis=d;
    head[x]=cnt;
}
inline void add_que(ll x,ll y){
    q[++cnt].nxt=headq[x];
    q[cnt].to=y;
    headq[x]=cnt;
}
ll find(ll x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
void dfs(ll u,ll pre){
    for(ll i=head[u];i;i=e[i].nxt){
        ll v=e[i].to;
        if(v==pre)
            continue;
        dfs(v,u);
        s[u]+=s[v];
    }
    if(s[u]==num&&a[u]>ret)
        ret=a[u];
}
inline bool check(ll x){
    memset(s,0,sizeof(s));
    num=ret=0;
    for(ll i=1;i<=m;i++)
        if(len[i].len>x){
            s[len[i].u]++;
            s[len[i].v]++;
            s[len[i].lca]-=2;
            num++;
        }
    dfs(1,0); 
    if(maxlen-ret>x) 
        return 0;
    return 1;
}
void tarjan(ll u,ll pre){
    for(ll i=head[u];i;i=e[i].nxt){
        ll v=e[i].to;
        if(v==pre)
            continue;
        dis[v]=dis[u]+e[i].dis;
        tarjan(v,u);
        a[v]=e[i].dis;
        ll f1=find(v);
        ll f2=find(u);
        if(f1!=f2)
            f[f1]=find(f2);
        vst[v]=1;
    }
    for(ll i=headq[u];i;i=q[i].nxt)
        if(vst[q[i].to]){
            ll p=(i+1)/2;
            len[p].lca=find(q[i].to);
            len[p].len=dis[u]+dis[q[i].to]-2*dis[len[p].lca];
            maxlen=max(maxlen,len[p].len);
        }
}
int main(){
	freopen("reasoning.in","r",stdin);
	freopen("reasoning.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i=1,ai=0,bi=0,ti=0;i<n;i++){
        scanf("%lld %lld %lld",&ai,&bi,&ti);
        add_edge(ai,bi,ti);
        add_edge(bi,ai,ti);
    }
    for(ll i=1;i<=n;i++) f[i]=i;
    cnt=0;
    for(ll i=1,x=0,y=0;i<=m;i++){
    	scanf("%lld %lld",&x,&y);
        len[i].u=x;
        len[i].v=y;
        add_que(x,y);
        add_que(y,x);
    }
    tarjan(1,0);
    ll l=0,r=maxlen,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            r=mid-1;
            ans=mid; 
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
