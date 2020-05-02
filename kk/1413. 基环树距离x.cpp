#include<bits/stdc++.h>
typedef int LL;
const LL maxn=3e5+9;
inline LL Read(){
    LL x(0),f(1); char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') f=-1; c=getchar();
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+c-'0'; c=getchar();
    }
    return x*f;
}
struct node{
    LL to,nxt,d;
}dis[maxn];
LL num;
LL head[maxn];
inline void Add(LL u,LL v,LL w){
    dis[++num]=(node){v,head[u],w}; head[u]=num;
}
struct E{
    LL u,v,w;
}e[maxn];
LL n,m;
LL n_tree,n_u,n_v,tim,n_d;
LL dep[maxn],size[maxn],visit[maxn],fa[maxn],val[maxn],bel[maxn],son[maxn],dx[maxn],id[maxn],top[maxn];
void Dfs1(LL u,LL f){
    dep[u]=dep[f]+1;
    size[u]=1; visit[u]=true;
    for(LL i=head[u];i;i=dis[i].nxt){
        LL v(dis[i].to); if(v==f) continue;
        if(visit[v]){
            n_tree=i+1>>1; n_u=u; n_v=v; n_d=dis[i].d;
            continue;
        }
        Dfs1(v,u); size[u]+=size[v];
        fa[v]=u; val[v]=dis[i].d; bel[i+1>>1]=v;
        if(size[son[u]]<size[v]) son[u]=v;
    }
}
void Dfs2(LL u,LL up){
    dx[++tim]=u; id[u]=tim;
    top[u]=up;
    if(son[u]) Dfs2(son[u],up);
    for(LL i=head[u];i;i=dis[i].nxt){
        LL v(dis[i].to); if(v==fa[u] || v==son[u] || (i+1>>1)==n_tree) continue;
        Dfs2(v,v);
    }
}
struct Bit{
    LL t[maxn];
    inline LL Lowbit(LL x){
        return x&-x;
    }
    inline void Add(LL x,LL val){
        for(;x<=n;x+=Lowbit(x)) t[x]+=val;
    }
    inline LL Qy(LL x){
        LL ret(0);
        for(;x;x-=Lowbit(x)) ret+=t[x];
        return ret;
    }
    inline LL Query(LL l,LL r){
        return Qy(r)-Qy(l-1);
    }
}Bt;
inline LL Query(LL x,LL y){
    LL ret(0);
    LL fx(top[x]),fy(top[y]);
    while(fx!=fy){
        if(dep[fx]>=dep[fy]){
            ret+=Bt.Query(id[fx],id[x]); x=fa[fx];
        }else{
            ret+=Bt.Query(id[fy],id[y]); y=fa[fy];
        }
        fx=top[x]; fy=top[y];
    }
    if(dep[x]<=dep[y])
        ret+=Bt.Query(id[x],id[y])-val[x];
    else
        ret+=Bt.Query(id[y],id[x])-val[y];
    return ret;
}
int main(){
    n=Read(); m=Read();
    for(LL i=1;i<=n;++i){
        LL u(Read()),v(Read()),w(Read());
        Add(u,v,w); Add(v,u,w);
        e[i]=(E){u,v,w};
    }
    Dfs1(1,0); Dfs2(1,1);
    for(LL i=1;i<=n;++i)
        Bt.Add(id[i],val[i]);
    while(m--){
        LL op(Read()),x(Read()),y(Read());
        if(op==1){
            if(x==n_tree){
                n_d=y;
                continue;
            }
            LL v(bel[x]);
            Bt.Add(id[v],-val[v]);
            Bt.Add(id[v],val[v]=y);
        }else{
            printf("%d\n",std::min(Query(x,y),std::min(Query(x,n_u)+Query(y,n_v)+n_d,Query(x,n_v)+Query(y,n_u)+n_d)));
        }
    }
    return 0;
}
