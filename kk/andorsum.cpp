#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1010;
const int mod=1e9+7;
int n;
int ge[N][N];
int s[N][N];
int stk[N],top;
ll ans;
int main()
{
	freopen("andorsum.in","r",stdin);
	freopen("andorsum.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&ge[i][j]);
        }
    }
    for(int k=0;k<31;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((ge[i][j]>>k)&1) s[i][j]=s[i-1][j]+1;
                else s[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            ll sum=0;
            top=0;
            for(int j=1;j<=n;j++)
            {
                sum+=s[i][j];
                while(top&&s[i][stk[top]]>=s[i][j])
                {
                    sum-=(stk[top]-stk[top-1])*(s[i][stk[top]]-s[i][j]);
                    top--;
                }
                ans+=sum<<k;
                ans%=mod;
                stk[++top]=j;
            }
        }
    }
    printf("%lld ",ans);
    ans=0;
    for(int k=0;k<31;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((ge[i][j]>>k)&1) s[i][j]=0;
                else s[i][j]=s[i-1][j]+1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            ll sum=0;
            top=0;
            for(int j=1;j<=n;j++)
            {
                sum+=s[i][j];
                while(top&&s[i][stk[top]]>=s[i][j])
                {
                    sum-=(stk[top]-stk[top-1])*(s[i][stk[top]]-s[i][j]);
                    top--;
                }
                ans+=(i*j-sum)<<k;
                ans%=mod;
                stk[++top]=j;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
