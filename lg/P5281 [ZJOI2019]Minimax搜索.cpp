#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=400007;
const int M=20000007;
const ll mod=998244353;
struct str
{
    int x;
    int y;
    int d;
}p[N];
ll s[N];
int hd[N],pre[N],to[N],num,dep[N],son[N],w[N],n,cnt;
int sum[M],lc[M],rc[M],mul[M],tot,rt[N],sn[N],sz[N];
void adde(int x,int y)
{
    num++;pre[num]=hd[x];hd[x]=num;to[num]=y;
}

void Mul(int k,int d)
{
    mul[k]=1ll*mul[k]*d%mod;
    sum[k]=1ll*sum[k]*d%mod;
}
void pushdown(int k)
{
    if(lc[k])Mul(lc[k],mul[k]);
    if(rc[k])Mul(rc[k],mul[k]);
    mul[k]=1;
}
void add(int &k,int l,int r,int x,int d)
{
    if(!k)k=++tot;
    if(l==r){sum[k]=(sum[k]+d)%mod;return;}
    int mid=l+r>>1;
    if(mul[k]!=1)pushdown(k);
    if(x<=mid)add(lc[k],l,mid,x,d);
    else add(rc[k],mid+1,r,x,d);
    sum[k]=(sum[lc[k]]+sum[rc[k]])%mod;
}
void modify(int k,int l,int r,int x,int y,int d)
{
    if(!k)return;
    if(l>=x&&r<=y)return Mul(k,d);
    int mid=l+r>>1;
    if(mul[k]!=1)pushdown(k);
    if(x<=mid)modify(lc[k],l,mid,x,y,d);
    if(y>mid)modify(rc[k],mid+1,r,x,y,d);
    sum[k]=(sum[lc[k]]+sum[rc[k]])%mod;
}
int query(int k,int l,int r,int x,int y)
{
    if(!k)return 0;
    if(l>=x&&r<=y)return sum[k];
    int mid=l+r>>1,ans=0;
    if(mul[k]!=1)pushdown(k);
    if(x<=mid)ans=(ans+query(lc[k],l,mid,x,y))%mod;
    if(y>mid)ans=(ans+query(rc[k],mid+1,r,x,y))%mod;
    return ans;
}
void visit(int k,int l,int r)
{
    if(!k)return ;
    if(l==r){p[++cnt]={sum[k],0,l};return ;}
    int mid=l+r>>1;
    if(mul[k]!=1)pushdown(k);
    visit(lc[k],l,mid);
    visit(rc[k],mid+1,r);
}

void dfs(int v,int fa)
{
    int i,u;
    dep[v]=dep[fa]+1;s[v]=1;
    sz[v]=0;
    for(i=hd[v];i;i=pre[i])
    {
        u=to[i];
        if(u==fa)continue;
        dfs(u,v);s[v]=s[v]*s[u]%mod;
        if(dep[v]&1){
            if(w[u]>w[son[v]])son[v]=u;
        }else if(!son[v]||w[u]<w[son[v]])son[v]=u;
        if(sz[u]>sz[sn[v]])sn[v]=u;
        sz[v]+=sz[u];
    }
    if(!son[v])w[v]=v,s[v]=2,sz[v]=1;
    else w[v]=w[son[v]];
}
void orun(int a,int b)
{
    cnt=0;
    visit(rt[b],1,n);
    for(int i=1;i<=cnt;i++)
        if(p[i].d<n)p[i].y=query(rt[a],1,n,p[i].d+1,n);
    int sm=0;
    p[0].d=0;
    for(int i=cnt;i>=1;i--)
    {
        sm=(sm+p[i].x)%mod;
        modify(rt[a],1,n,p[i-1].d+1,p[i].d,sm+1);
    }
    for(int i=1;i<=cnt;i++)
        add(rt[a],1,n,p[i].d,1ll*p[i].x*(p[i].y+1)%mod);
}
void andun(int a,int b)
{
    cnt=0;
    int tmp=(sum[rt[a]]+sum[rt[b]])%mod;
    visit(rt[b],1,n);
    for(int i=1;i<=cnt;i++)
        if(p[i].d>1)p[i].y=query(rt[a],1,n,1,p[i].d-1);
    int sm=0;
    p[cnt+1].d=n+1;
    if(p[1].d>1)modify(rt[a],1,n,1,p[1].d-1,0);
    for(int i=1;i<=cnt;i++)
    {
        sm=(sm+p[i].x)%mod;
        modify(rt[a],1,n,p[i].d,p[i+1].d-1,sm);
    }
    for(int i=1;i<=cnt;i++)
        add(rt[a],1,n,p[i].d,1ll*p[i].x*p[i].y%mod);
    add(rt[a],1,n,n,tmp);
}
void dp(int v,int fa,int d)
{
    int i,u;
    if(!son[v])add(rt[v],1,n,max(1,abs(d)),1);
    else if(!d||d>0&&(dep[v]&1)||d<0&&!(dep[v]&1))
    {
        int tar;
        if(d)tar=w[son[v]]+d;
        else tar=dep[v]&1?w[son[v]]+1:w[son[v]]-1;
        u=sn[v];
        if(u==son[v])dp(u,v,d);
        else dp(u,v,tar-w[u]);
        rt[v]=rt[u];
        for(i=hd[v];i;i=pre[i])
        {
            u=to[i];
            if(u==fa||u==sn[v])continue;
            if(u==son[v])dp(u,v,d);
            else dp(u,v,tar-w[u]);
            orun(v,u);
        }
    }
    else
    {
        int tar=w[son[v]]+d;
        ll ml=1;
        u=sn[v];
        if(d<0&&w[u]<=tar||d>0&&w[u]>=tar)
            ml=ml*s[u]%mod;
        else
        {
            dp(u,v,tar-w[u]);
            rt[v]=rt[u];
        }
        for(i=hd[v];i;i=pre[i])
        {
            u=to[i];
            if(u==fa||u==sn[v])continue;
            if(d<0&&w[u]<=tar||d>0&&w[u]>=tar)
                ml=ml*s[u]%mod;
            else
            {
                dp(u,v,tar-w[u]);
                if(!rt[v])rt[v]=rt[u];
                else andun(v,u);
            }
        }
        modify(rt[v],1,n,1,n,ml);
        add(rt[v],1,n,n,ml-1);
    }
}
int main()
{
    int i,x,y,l,r;
    scanf("%d%d%d",&n,&l,&r);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        adde(x,y),adde(y,x);
    }
    dfs(1,0);
    dp(1,0,0);
    for(i=l;i<=r;i++)
        printf("%d ",query(rt[1],1,n,i,i));
    return 0;
}
