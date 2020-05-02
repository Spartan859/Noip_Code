#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],b[maxn],d[maxn];
long long c[maxn],ans;
inline int lowbit(int x){
    return x&(-x);
}
inline void update(int x,long long val){
    while(x<=n){
        c[x]+=val;
        x+=lowbit(x);
    }
}
inline long long getsum(int x){
    long long res=0;
    while(x>0){
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
int main(){
    int opt,x,tmp=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        b[i]=i-1-getsum(a[i]);
        ans+=b[i],++d[b[i]];
        update(a[i],1);
    }
    memset(c,0,sizeof(c));
    update(1,ans);
    for(int i=0;i<n;++i){
        tmp+=d[i];
        update(i+2,-(n-tmp));
    }
    for(int i=1;i<=m;++i){
        scanf("%d%d",&opt,&x);
        x=min(x,n-1);
        if(opt==1){
            if(a[x]<a[x+1]){
                swap(a[x],a[x+1]);
                swap(b[x],b[x+1]);
                update(1,1);
                update(b[x+1]+2,-1);
                b[x+1]++;
            }
            else{
                swap(a[x],a[x+1]);
                swap(b[x],b[x+1]);
                update(1,-1);
                b[x]--;
                update(b[x]+2,1);
            }
        }
        else printf("%lld\n",getsum(x+1));
    }
    return 0;
}
