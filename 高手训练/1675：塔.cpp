#include<bits/stdc++.h> 
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define N 1001000
#define ll long long
using namespace std;
int n,t,y;
ll a[N],f[N],h[N],s[N],d[N];
int main(){
    scanf("%d",&n);s[0]=0;
    fo(i,1,n) scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
    d[t=y=1]=0;
    fo(i,1,n){
        while(h[d[t+1]]+s[d[t+1]]<=s[i]&&t<y) t++;
        f[i]=f[d[t]]+i-d[t]-1;h[i]=s[i]-s[d[t]];
        while(t<=y&&h[d[y]]+s[d[y]]>=h[i]+s[i]) y--;
        d[++y]=i;
    }
    printf("%lld",f[n]);
    return 0;
}
