#include<cstdio>
#include<algorithm>
using namespace std;const int N=1510;typedef long long ll;const ll mod=1e9+7;
inline ll po(ll a,ll p){ll r=1;for(;p;p>>=1,a=a*a%mod){if(p&1){r=r*a%mod;}}return r;}
int n;int p;ll m;ll k;ll mp[N][N];ll f[N];ll inv1;ll inv;ll res;int T;
inline void solve()
{
    scanf("%d%d%lld%lld",&n,&p,&m,&k);
    if(k==0){printf("-1\n");return;}//特判一些特殊情况
    if(m==0)
    {
        if(k==1){printf("-1\n");return;}
        for(;p>0;){if(p<n){p++;}p-=k;res++;}printf("%lld\n",res);res=0;return;
    }inv=po(m+1,mod-2);inv1=po(m,mod-2);f[0]=po(m*inv%mod,k);
    for(int i=1;i<=min((ll)(n+1),k);i++)f[i]=f[i-1]*inv1%mod*po(i,mod-2)%mod*(k-i+1)%mod;//递推f数组
    for(int i=1;i<n;i++)for(int j=1;j<=i;j++)mp[i][j]=(f[i-j]*m+f[i-j+1])%mod*inv%mod;//列方程
    for(int i=1;i<n;i++)mp[i][i+1]=f[0]*inv%mod;//i+1
    for(int i=1;i<n;i++)(mp[i][i]+=mod-1)%=mod;//1~i
    for(int i=1;i<=n;i++){mp[i][n+1]=mod-1;}//常数项
    for(int i=1;i<=n;i++){mp[n][i]=f[n-i];}(mp[n][n]+=mod-1)%=mod;
    for(int i=1;i<=n;i++)//高斯消元
    {
        ll inv=po(mp[i][i],mod-2);mp[i][i]=1;(mp[i][n+1]*=inv)%=mod;
        if(i!=n){(mp[i][i+1]*=inv)%=mod;}//两行两行的向下消
        for(int j=i+1;j<=n;j++)
        {
            ll mult=mp[j][i];mp[j][i]=0;(mp[j][i+1]+=mod-mult*mp[i][i+1]%mod)%=mod;
            (mp[j][n+1]+=mod-mult*mp[i][n+1]%mod)%=mod;
        }
    }
    for(int i=n;i>1;i--){(mp[i-1][n+1]+=mod-mp[i-1][i]*mp[i][n+1]%mod)%=mod;mp[i-1][i]=0;}//倒着消上去
    printf("%lld\n",mp[p][n+1]);
}
inline void clear()//清空
{
    for(int i=1;i<=min((ll)(n+1),k);i++){f[i]=0;}
    for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)mp[i][j]=0;
}
int main(){scanf("%d",&T);for(int i=1;i<=T;i++){solve();clear();}return 0;}//拜拜程序~
