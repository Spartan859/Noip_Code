#include<bits/stdc++.h> 
#define N
using namespace std;
int n=0,a[100001],f[100001],d[100001],ans=1,t=0;
int main() {
    while(~scanf("%d",&a[++n]));//读入数据方法
    n--;//n是导弹数，由于某些原因要--
    for(int i=1; i<=n; i++) {
        f[i]=1;
        for(int j=t; j>0; j--)
            if(a[i]<=a[d[j]]) {
                f[i]=f[d[j]]+1;
                break;
            }
        t=max(t,f[i]);
        d[f[i]]=i;//简单的维护过程
        ans=max(ans,f[i]);
    }
    printf("%d\n",ans);
    ans=1;
    t=0;
    for(int i=1; i<=n; i++) {
        f[i]=1;
        for(int j=t; j>0; j--)
            if(a[i]>a[d[j]]) {
                f[i]=f[d[j]]+1;
                break;
            }
        t=max(t,f[i]);
        d[f[i]]=i;
        ans=max(ans,f[i]);
    }
    printf("%d",ans);
}
