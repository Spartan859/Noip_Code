#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int tt,tim;
char s[N];
struct Dat {
    int x,t,f;
};
vector <Dat> q[N];
int head[N],to[N],nxt[N],v[N],ch[N][10],c[N],ans[N],f[N],dep[N],dfn[N],ed[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?o=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline void lnk(int x,int y) {
    to[++tt]=y,nxt[tt]=head[x],head[x]=tt;
}
inline void build() {
    int t=0,sum=0;
    for(int i=0; i<10; i++)
        if(ch[0][i]) dep[v[++sum]=ch[0][i]]=1,lnk(0,v[sum]);
    while(t<sum) {
        int x=v[++t];
        for(int i=0; i<10; i++) {
            int &y=ch[x][i];
            if(y) {
                dep[y]=dep[x]+1,f[y]=ch[f[x]][i],v[++sum]=y;
                lnk(f[v[sum]],v[sum]);
            } else y=ch[f[x]][i];
        }
    }
}
inline void dfs(int x) {
    dfn[x]=++tim;
    for(int i=head[x]; i; i=nxt[i]) dfs(to[i]);
    ed[x]=tim;
}
inline void add(int x) {
    while(x<=tim) ++c[x],x+=(x&-x);
}
inline int query(int x) {
    int ret=0;
    while(x) ret+=c[x],x-=(x&-x);
    return ret;
}
int main() {
    int n,m,Q;
    cin>>n>>m>>Q;
    for(int i=1,x; i<n; i++)
        x=gi(),ch[x][gi()]=i;
    build(),dfs(0);
    scanf("%s",s+1);
    for(int i=1; i<=Q; i++) {
        int x=gi(),l=gi(),r=gi();
        if(dep[x]<=r-l+1) {
            q[r].push_back((Dat) {x,i,1});
            q[l+dep[x]-2].push_back((Dat) {x,i,-1});
        }
    }
    for(int i=1,x=0; i<=m; i++) {
        add(dfn[x=ch[x][s[i]-'0']]);
        for(auto j:q[i]) ans[j.t]+=j.f*(query(ed[j.x])-query(dfn[j.x]-1));
    }
    for(int i=1; i<=Q; i++) printf("%d\n",ans[i]);
    return 0;
}
