#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>

#define ll long long
#define db double
#define rg register int

using namespace std;

int n;
ll ans;
int b[1000005];
ll s[1000005];

struct su{
    int x,y;
    inline bool operator <(const su &z){
        return x>z.x;
    }
}a[1000005];

inline int qr(){
    register char ch; register bool sign=0; rg res=0;
    while(!isdigit(ch=getchar()))if(ch=='-')sign=1;
    while(isdigit(ch))res=res*10+(ch^48),ch=getchar();
    if(sign)return -res; else return res;
}

inline void add(int x,int v){
    for(;x<=n;x+=x&-x)s[x]+=v;
}

inline ll ask(int x){
    ll res=0;
    for(;x;x-=x&-x) res+=s[x];
    return res;
}

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    n=qr();
    for(rg i=1;i<=n;++i) a[i]={qr(),i};
    sort(a+1,a+n+1);
    for(rg i=1,j=1;i<=n;++i){
        if(a[i].x!=a[i-1].x)j=i;
        b[a[i].y]=j;
    }
    for(rg i=1;i<=n;++i){
        ans+=(ll)ask(b[i]-1)*(n-i+1);
        add(b[i],i);
    }printf("%lld\n",ans);
    return 0;
}
