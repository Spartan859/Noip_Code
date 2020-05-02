#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN=2e5+10;
ll a[MAXN],f[MAXN];
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    while(m--){
        ll ans=0;
        int k=read();
        if(k==0||n==1){
            for(int i=1;i<=n;i++) ans+=a[i]*a[i];
            printf("%lld\n",ans);
            continue;
        }
        int t=gcd(n,k),p=n/t;
        if(f[p]){
            printf("%lld\n",f[p]);
            continue;
        }
        for(int i=1;i<=n;i+=p){
            for(int j=0;j<p-2;j++) ans+=a[i+j]*a[i+j+2];
            ans+=(a[i]*a[i+1]+a[i+p-1]*a[i+p-2]);
        }
        printf("%lld\n",ans);
        f[p]=ans; 
    }
    return 0;
}
