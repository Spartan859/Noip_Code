#include<cstdio>
#include<algorithm>
using namespace std;const int N=110;typedef long long ll;const ll mod=998244353;
struct mar
{
    int mp[N][N];
    inline int* operator [](const int & x){return mp[x];}
}mp,bas[2];char mde[N][N];
ll dp[N][N];ll fdp[N][N];
ll dx;ll dy;ll ans;
int n;int m;
inline void solve(mar& p,mar& q,const int& sx,const int& sy,int rd){
    for(int i=0;i<=dx;i++)
        for(int j=0;j<=dy;j++) p[1+i][1+j]=q[1+i][1+j]|mp[sx+i][sy+j];
    for(int i=1;i<=dx+1;i++)for(int j=1;j<=dy+1;j++)dp[i][j]=0;
    for(int i=1;i<=dx+1;i++)for(int j=1;j<=dy+1;j++)fdp[i][j]=0;
    if(p[1][1]==0)
    {
        dp[1][1]=1;ll v;
        for(int i=1;i<=dx+1;i++)
            for(int j=1;j<=dy+1;j++)
                v=dp[i][j],(dp[i][j+1]+=(!p[i][j+1])*v)%=mod,(dp[i+1][j]+=(!p[i+1][j])*v)%=mod;
    }
    if(q[dx+1][dy+1]==0)
    {
        fdp[dx+1][dy+1]=1;ll v;
        for(int i=dx+1;i>=1;i--)
            for(int j=dy+1;j>=1;j--)
                v=fdp[i][j],(fdp[i][j-1]+=(!q[i][j-1])*v)%=mod,(fdp[i-1][j]+=(!q[i-1][j])*v)%=mod;
    }
    for(int i=1;i<=dx+1;i++)
        for(int j=1;j<=dy+1;j++)
        {
            ll fv;if(p[i][j]==0)continue;
            if(i==1&&j==1)fv=1;else if(i==1)fv=dp[i][j-1];else if(j==1)fv=dp[i-1][j];
            else fv=(dp[i][j-1]+dp[i-1][j])%mod;
            (ans+=(ll)(rd+i+j-2)*fv%mod*fdp[i][j])%=mod;
        }
}
inline int gcd(int a,int b){if(a<b)swap(a,b);while(b){int c=a%b;a=b;b=c;}return a;}
inline void solve()
{
    scanf("%d%d",&n,&m);for(int i=1;i<=n;i++)scanf("%s",mde[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)mp[i][j]=(mde[i][j]=='1');
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)mp[i+n][j]=mp[i][j];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)mp[i][j+m]=mp[i][j];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)mp[i+n][j+m]=mp[i][j];int d=gcd(n,m);
    for(dx=0,dy=d;dx<=d;dx++,dy--)
    {
        if(dx==0&&n!=1)continue;if(dy==0&&m!=1)continue;
        if(gcd(dx,d)!=1||gcd(dx,n)!=1||gcd(dy,m)!=1)continue;
        for(int i=0;i<=dx+1;i++)for(int j=0;j<=dy+1;j++)bas[0][i][j]=0;
        for(int i=0;i<=dx+1;i++)for(int j=0;j<=dy+1;j++)bas[1][i][j]=0;
        for(int rd=0,p=1,q=0;rd<n*m;rd+=d,p^=1,q^=1)
            solve(bas[p],bas[q],(rd*dx/d)%n+1,(rd*dy/d)%m+1,rd);    
    }printf("%lld\n",ans);ans=0;
}
int main(){int T;scanf("%d",&T);for(int z=1;z<=T;z++)solve();return 0;}
