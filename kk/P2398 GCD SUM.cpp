#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int maxn=1e5+5;
int n,cnt;
LL ans;
int phi[maxn],pri[maxn],vis[maxn];
LL sum[maxn];
inline void get_phi(int x){
    phi[1]=1;
    for(int i=2;i<=x;++i){
        if(!vis[i]){
            pri[++cnt]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=cnt&&pri[j]*i<=x;++j){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0){
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
    }
    for(int i=1;i<=x;++i)sum[i]=sum[i-1]+phi[i];
}
int main(){
    scanf("%d",&n);
    get_phi(n);
    for(int i=1;i<=n;++i)
        ans+=(2*sum[n/i]-1)*i;
    printf("%lld",ans);
    return 0;
}
