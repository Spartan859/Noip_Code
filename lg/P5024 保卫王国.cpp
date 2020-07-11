#include <iostream>
#include <cstdio>
#include <cctype>
#define il inline
#define vd void
#define mn 100005
#define INF 100000000000000 //1e14
#define rg register
#define ll long long
#define rep(i,x,y) for(register int i=x;i<=y;++i)
#define drp(i,x,y) for(register int i=x;i>=y;--i)
using namespace std;
const int Len=2333333,aa[18]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
char buf[Len],*p1=buf,*p2=buf,duf[Len],*q1=duf;
il char gc(); il int rd(); il vd pc(char c); il vd rt(ll x); il vd flush();
template<class T> il T Max(T a,T b){return a>b?a:b;}
template<class T> il T Min(T a,T b){return a<b?a:b;}
int n,m,ty,u,v,cnt,x,y,p[mn],h[mn],fa[19][mn],dep[mn],Log[mn];
ll dp[3][mn],f[3][3][19][mn];
struct E{int to,nxt;}e[mn<<1];
il vd Add(int u,int v){e[++cnt]=(E){v,h[u]},h[u]=cnt;}
vd Dfs(int u){
    dep[u]=dep[fa[0][u]]+1,dp[1][u]=p[u],f[0][0][0][u]=INF; //???????0
    for(rg int i=1;aa[i]<dep[u];++i) fa[i][u]=fa[i-1][fa[i-1][u]];
    for(rg int i=h[u];i;i=e[i].nxt){int v=e[i].to;
        if(v!=fa[0][u]) fa[0][v]=u,Dfs(v),
            dp[0][u]+=dp[1][v],dp[1][u]+=Min(dp[0][v],dp[1][v]);
    } //???dp??
}
vd Cfs(int u){
    //f[0][1][0][u]=dp[1][fa[0][u]]-dp[0][u],
    //f[1][0][0][u]=dp[0][fa[0][u]]-dp[1][u],
    //f[1][1][0][u]=dp[1][fa[0][u]]-dp[1][u];
    f[1][0][0][u]=dp[0][fa[0][u]]-dp[1][u],
    f[0][1][0][u]=f[1][1][0][u]=dp[1][fa[0][u]]-Min(dp[0][u],dp[1][u]);
    for(rg int i=1;aa[i]<dep[u];++i){
        int F=fa[i-1][u];//ÖÐµã 
        f[0][0][i][u]=Min(f[0][0][i-1][u]+f[0][0][i-1][F],f[0][1][i-1][u]+f[1][0][i-1][F]),
        f[0][1][i][u]=Min(f[0][0][i-1][u]+f[0][1][i-1][F],f[0][1][i-1][u]+f[1][1][i-1][F]),
        f[1][0][i][u]=Min(f[1][0][i-1][u]+f[0][0][i-1][F],f[1][1][i-1][u]+f[1][0][i-1][F]),
        f[1][1][i][u]=Min(f[1][0][i-1][u]+f[0][1][i-1][F],f[1][1][i-1][u]+f[1][1][i-1][F]);
    }// 4??????
    for(rg int i=h[u];i;i=e[i].nxt) if(e[i].to!=fa[0][u]) Cfs(e[i].to);
}
il vd Work(){
    if(dep[u]<dep[v]) swap(u,v),swap(x,y);
    int L;
    ll u0=INF,u1=INF,v0=INF,v1=INF,l0=INF,l1=INF,ans;
    x?u1=dp[1][u]:u0=dp[0][u],y?v1=dp[1][v]:v0=dp[0][v];
    for(rg int i=Log[dep[u]-dep[v]];i>=0;--i) if(dep[u]-aa[i]>=dep[v]){
        ll t0=u0,t1=u1;
        u0=Min(t0+f[0][0][i][u],t1+f[1][0][i][u]),
        u1=Min(t0+f[0][1][i][u],t1+f[1][1][i][u]),
        //printf("%d ",u);
        u=fa[i][u];
        //printf("%d %lld %lld\n",u,u0,u1);
    } //u???
    if(u==v) L=u,y?l1=u1:l0=u0; //?1???
    else{
        for(rg int i=Log[dep[u]-1];i>=0;--i) if(fa[i][u]!=fa[i][v]){
          	ll t0=u0,t1=u1,p0=v0,p1=v1;
            u0=Min(t0+f[0][0][i][u],t1+f[1][0][i][u]),
            u1=Min(t0+f[0][1][i][u],t1+f[1][1][i][u]),
            v0=Min(p0+f[0][0][i][v],p1+f[1][0][i][v]),
            v1=Min(p0+f[0][1][i][v],p1+f[1][1][i][v]),
            u=fa[i][u],v=fa[i][v];
        } //???
        L=fa[0][u],l0=dp[0][L]-dp[1][u]-dp[1][v]+u1+v1,
      	l1=dp[1][L]-Min(dp[0][u],dp[1][u])-Min(dp[0][v],dp[1][v])+Min(u0,u1)+Min(v0,v1);
    }// ?????????????
    //printf("%d\n",L);
    if(L==1) ans=Min(l0,l1); //??L=1
    else{
        for(rg int i=Log[dep[L]-2];i>=0;--i) if(dep[L]-aa[i]>1){
            ll t0=l0,t1=l1;
            l0=Min(t0+f[0][0][i][L],t1+f[1][0][i][L]),
            l1=Min(t0+f[0][1][i][L],t1+f[1][1][i][L]),
            L=fa[i][L];
        }//L???
        ans=Min(dp[0][1]-dp[1][L]+l1,dp[1][1]-Min(dp[0][L],dp[1][L])+Min(l0,l1));
    }
    rt(ans<INF?ans:-1),pc('\n');
}
int main(){
    n=rd(),m=rd(),ty=rd();
    rep(i,1,n) p[i]=rd();
    rep(i,2,n) u=rd(),v=rd(),Add(u,v),Add(v,u),Log[i]=Log[i>>1]+1;
    Dfs(1),Cfs(1);
    //rep(i,1,n) printf("%d 0:%lld 1:%lld\n",i,dp[0][i],dp[1][i]);
    //puts("");
    //int P=1;
    //rep(i,1,n) printf("%d %lld %lld %lld %lld\n",i,f[0][1][P][i],f[1][0][P][i],f[1][1][P][i],f[0][0][P][i]);
    //puts("");
    while(m--) u=rd(),x=rd(),v=rd(),y=rd(),Work();
    return flush(),0;
}

il char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,Len,stdin),p1==p2)?-1:*p1++;}
il int rd(){char c; int f=1;
    while(!isdigit(c=gc())&&c!='-');
    c=='-'?f=-1,c=gc():0; int x=c^48;
    while(isdigit(c=gc())) x=((x+(x<<2))<<1)+(c^48);
    return x*f;
}
il vd pc(char c){q1==duf+Len&&fwrite(q1=duf,1,Len,stdout),*q1++=c;}
il vd rt(ll x){x<0?pc('-'),x=-x:0,pc((x>=10?rt(x/10),x%10:x)+48);}
il vd flush(){fwrite(duf,1,q1-duf,stdout);}
