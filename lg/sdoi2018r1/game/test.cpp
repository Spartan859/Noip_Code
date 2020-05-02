#define ri register int
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N=1e5+5,M=2e5+5;
inline int re(){
    ri x=0,w=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*w;
}
int n,m,ts,tp,tot,t,S,q;
int dfn[N],low[N],st[N],dep[N],top[N],sz[N],son[N],fa[N];
struct Graph{
    int cnt,last[N],nxt[M],to[M];
    inline void link(ri u,ri v){
        nxt[++cnt]=last[u];to[cnt]=v;last[u]=cnt;
        nxt[++cnt]=last[v];to[cnt]=u;last[v]=cnt;
    }
}G,T;
void tarjan(ri u){
    dfn[u]=low[u]=++ts;st[++tp]=u;
    for(ri i=G.last[u],v;i;i=G.nxt[i]){
        v=G.to[i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                T.link(++tot,u);
                ri x=0;
                do{
                    x=st[tp--];T.link(tot,x);
                }while(x!=v);
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
}
void dfs1(ri u){
    sz[u]=1;
    for(ri i=T.last[u],v;i;i=T.nxt[i]){
        v=T.to[i];
        if(v==fa[u])continue;
        dep[v]=dep[u]+1;
        fa[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])son[u]=v;
    }
}
void dfs2(ri u,ri Tp){
    top[u]=Tp;
    if(son[u])dfs2(son[u],Tp);
    for(ri i=T.last[u],v;i;i=T.nxt[i]){
        v=T.to[i];
        if(v==son[u]||v==fa[u])continue;
        dfs2(v,v);
    }
}
inline int Query(ri x,ri y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}
inline void clr(){
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(st,0,sizeof(st));
	memset(dep,0,sizeof(dep));
	memset(top,0,sizeof(top));
	memset(sz,0,sizeof(sz));
	memset(son,0,sizeof(son));
	memset(fa,0,sizeof(fa));
	ts=tp=0;
}
int main(){
	t=re();
	while(t--){
		tot=n=re();m=re();
		for(int i=1,u,v;i<=m;i++){
			u=re();v=re();
			G.link(u,v);
		}
		tarjan(1);
		dep[1]=1;
		dfs1(1);dfs2(1,1);
		q=re();
		for(int i=1,u,v;i<=q;i++){
			S=re();
			u=re();v=re();
			printf("%d\n",(dep[u]+dep[v]-2*dep[Query(u,v)])/2-1);
		}
		clr();
	}
    return 0;
}
