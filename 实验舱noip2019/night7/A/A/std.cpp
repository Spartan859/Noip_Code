#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100010;
int ans,tt;
bool w[N];
int head[N],to[N],nxt[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?o=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline void dfs(int x,int y) {
    if(x==y) {++ans;return;}
    w[x]=1;
    for(int i=head[x];i;i=nxt[i])
	if(!w[to[i]]) dfs(to[i],y);
    w[x]=0;
}
int main() {
    freopen("A.in","r",stdin);
    freopen("std.out","w",stdout);
    int n,m,Q;
    cin>>n>>m>>Q;
    for(int i=1;i<=m;i++) {
	int x=gi(),y=gi();
	to[++tt]=y,nxt[tt]=head[x],head[x]=tt;
	to[++tt]=x,nxt[tt]=head[y],head[y]=tt;
    }
    while(Q--) {
	int x=gi(),y=gi();
	ans=0,dfs(x,y);
	printf("%d\n",ans);
    }
    return 0;
}
