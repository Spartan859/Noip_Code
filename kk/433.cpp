#include<bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
//typedef __int64 LL;
const int inf=0x3f3f3f3f;
const double pi= acos(-1.0);
const double esp=1e-6;
using namespace std;
const int Maxn=1e6+10;
const int mod=1000000000;
int dp[Maxn];
int main()
{
    int n;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<Maxn;i++)
    {
        if(i&1)
            dp[i]=dp[i-1]%mod;
        else
            dp[i]=(dp[i-2]+dp[i>>1])%mod;
    }
    scanf("%d",&n); 
    printf("%d\n",dp[n]);
    return 0;
}
