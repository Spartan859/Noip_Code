#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int N=200010,Mo=19491001;
int n,m,Q,tim,tt=1;
vector <int> q[N];
int head[N],to[N*2],nxt[N*2],dfn[N],low[N],vis[N],pa[N],w[N],f[N][18],d[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline void lnk(int x,int y) {
    to[++tt]=y,nxt[tt]=head[x],head[x]=tt;
    to[++tt]=x,nxt[tt]=head[y],head[y]=tt;
}
inline void tarjan(int x) {
    dfn[x]=low[x]=++tim;
    for(int i=head[x];i;i=nxt[i]) {
	int y=to[i];
	if(y!=pa[x]) {
	    if(!dfn[y]) {
		pa[y]=x,tarjan(y);
		low[x]=min(low[x],low[y]);
		if(low[y]>dfn[x]) q[x].push_back(y);
	    }
	    else low[x]=min(low[x],dfn[y]);
	}
    }
    for(int i=head[x];i;i=nxt[i]) {
	int y=to[i],z=x;
	if(y!=pa[x]&&dfn[y]<dfn[x]) {
	    w[++n]=1;
	    while(z!=y)
		q[n].push_back(z),z=pa[z];
	    q[n].push_back(y);
	    if(~q[n].size()&1) puts("233");
	}
    }
}
inline void dfs(int x,int fa) {
    w[x]+=w[fa],dfn[x]=++tim,f[x][0]=fa;
    for(int i=1;i<18;i++) f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=nxt[i])
	if(to[i]!=fa) dfs(to[i],x);
}
inline int lca(int x,int y) {
    if(x==y) return x;
    if(dfn[x]<dfn[y]) swap(x,y);
    for(int i=17;~i;i--)
	if(f[x][i]&&dfn[f[x][i]]>dfn[y]) x=f[x][i];
    return f[x][0];
}
int main() {
    freopen("10.in","r",stdin);
    freopen("10.out","w",stdout);
    cin>>n>>m>>Q;
    for(int i=1;i<=m;i++) lnk(gi(),gi());
    tarjan(1);
    memset(head,0,sizeof(head)),tt=0;
    for(int i=1;i<=n;i++)
	for(auto x:q[i])
	    if(vis[x]!=i) vis[x]=i,lnk(i,x);
    dfs(1,0);
    for(int i=d[0]=1;i<=n;i++) d[i]=2*d[i-1]%Mo;
    while(Q--) {
	int x=gi(),y=gi(),z=lca(x,y);
	printf("%d\n",d[w[x]+w[y]-w[z]-w[f[z][0]]]);
    }
    return 0;
}
