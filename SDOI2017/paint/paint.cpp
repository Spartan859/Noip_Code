#include<cstdio>
#include<iostream>
using namespace std;
#define I inline
#define R register int
#define G ch=getchar()
#define in(z) G;\
    while(ch<'-')G;\
    z=ch&15;G;\
    while(ch>'-')z*=10,z+=ch&15,G
#define lc x<<1
#define rc x<<1|1
#define pup mx[x]=max(mx[lc],mx[rc])
#define pdn if(lz[x])upd(lc,l[x],m[x],lz[x]),upd(rc,m[x]+1,r[x],lz[x]),lz[x]=0
const int N=100009,M=N*20;
int l[M],m[M],r[M],mx[M],lz[M],f[N],c[N][2],st[N][20],o[N];
int p=1,he[N],ne[N<<1],to[N<<1],d[N],dfn[N],at[N],mr[N],now;
I void dfs(R x,R fa){
    d[now=at[dfn[x]=++p]=x]=d[st[x][0]=f[x]=fa]+1;
    for(R&i=o[x];(st[x][i+1]=st[st[x][i]][i]);++i);
    for(R i=he[x];i;i=ne[i])
        if(fa!=to[i])dfs(to[i],x);
    mr[x]=now;
}
I int lca(R x,R y){
    if(d[x]<d[y])swap(x,y);
    for(R i=o[x];i>=0;--i)
        if(d[st[x][i]]>=d[y])x=st[x][i];
    if(x==y)return x;
    for(R i=o[x];i>=0;--i)
        if(st[x][i]!=st[y][i])x=st[x][i],y=st[y][i];
    return st[x][0];
}
I void build(R x,R s,R e){
    l[x]=s;r[x]=e;m[x]=(s+e)>>1;
    if(s==e){mx[x]=d[at[s]];return;}
    build(lc,s,m[x]);build(rc,m[x]+1,e);pup;
}
I void upd(R x,R s,R e,R v){
    if(l[x]==s&&r[x]==e){mx[x]+=v;lz[x]+=v;return;}
    pdn;
    if(e<=m[x])upd(lc,s,e,v);
    else if(s>m[x])upd(rc,s,e,v);
    else upd(lc,s,m[x],v),upd(rc,m[x]+1,e,v);
    pup;
}
I int get(R s){
    R x=1;
    while(l[x]!=r[x]){
        pdn;x=(lc)+(s>m[x]);
    }
    return mx[x];
}
I int ask(R x,R s,R e){//区间查值
    if(l[x]==s&&r[x]==e)return mx[x];
    pdn;
    if(e<=m[x])return ask(lc,s,e);
    if(s>m[x])return ask(rc,s,e);
    return max(ask(lc,s,m[x]),ask(rc,m[x]+1,e));
}
I bool nrt(R x){
    return c[f[x]][0]==x||c[f[x]][1]==x;
}
I void rot(R x){
    R y=f[x],z=f[y],k=c[y][1]==x,w=c[x][!k];
    if(nrt(y))c[z][c[z][1]==y]=x;c[x][!k]=y;c[y][k]=w;
    f[w]=y;f[y]=x;f[x]=z;
}
I void splay(R x){
    R y;
    while(nrt(x)){
        if(nrt(y=f[x]))rot((c[f[y]][0]==y)^(c[y][0]==x)?x:y);
        rot(x);
    }
}
I int frt(R x){
    while(c[x][0])x=c[x][0];
    return x;
}
I void access(R x){
    for(R w,y=0;x;x=f[y=x]){
        splay(x);
        if(c[x][1])w=frt(c[x][1]),upd(1,dfn[w],dfn[mr[w]],1);
        if((c[x][1]=y))w=frt(y),upd(1,dfn[w],dfn[mr[w]],-1);
    }
}
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
    register char ch;
    R n,m,i,a,b,op,x,y;
    in(n);in(m);
    for(i=1;i<n;++i){
        in(a);in(b);
        to[++p]=b;ne[p]=he[a];he[a]=p;
        to[++p]=a;ne[p]=he[b];he[b]=p;
    }
    p=0;dfs(1,0);build(1,1,n);
    while(m--){
        in(op);in(x);
        if(op==1)access(x);
        else if(op==2){
            in(y);
            printf("%d\n",get(dfn[x])+get(dfn[y])-get(dfn[lca(x,y)])*2+1);
        }
        else printf("%d\n",ask(1,dfn[x],dfn[mr[x]]));
    }
    return 0;
}
