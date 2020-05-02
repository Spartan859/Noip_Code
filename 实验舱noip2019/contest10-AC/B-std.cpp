#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100010,Mo=998244353;
int ans=1,tt;
int fac[N],rev[N],head[N],to[N*2],nxt[N*2],sz[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?o=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline void dfs(int x,int fa) {
    sz[x]=1;
    for(int i=head[x]; i; i=nxt[i]) {
        int y=to[i];
        if(y!=fa) {
            dfs(y,x),sz[x]+=sz[y];
            ans=1LL*ans*rev[sz[y]]%Mo;
        }
    }
    ans=1LL*ans*fac[sz[x]-1]%Mo;
}
inline int Pow(int x,int y) {
    int ret=1;
    for(; y; y>>=1,x=1LL*x*x%Mo)
        if(y&1) ret=1LL*ret*x%Mo;
    return ret;
}
int main() {
    int n;
    cin>>n;
    for(int i=fac[0]=1; i<=n; i++) fac[i]=1LL*fac[i-1]*i%Mo;
    rev[n]=Pow(fac[n],Mo-2);
    for(int i=n; i; i--) rev[i-1]=1LL*rev[i]*i%Mo;
    for(int i=1; i<n; i++) {
        int x=gi(),y=gi();
        to[++tt]=y,nxt[tt]=head[x],head[x]=tt;
        to[++tt]=x,nxt[tt]=head[y],head[y]=tt;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
