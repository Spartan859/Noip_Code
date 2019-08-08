#include<bits/stdc++.h>
using namespace std;
int n,m,v[100000],c[100000],l[1000][1000],dp[100000],t,e,q=0,s;//v：value；c：cost；
int main()
{
    cin>>n>>m>>t>>e;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>l[i][j];//第（i,j）棵树采摘一次可以得到的桃子数
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>s;//物品的个数
            int t=1,x=2*(i+j);
            if(l[i][j])//二进制的拆分；
            {
                while(s>=t)
                {
                    c[++q]=t*x;
                    v[q]=t*l[i][j];
                    s-=t;t*=2;
                }
                c[++q]=x*s;//重要重要重要！别忘记啦 
                v[q]=s*l[i][j];//重要重要重要！ 
            }
        }
    t=min(t,e-1);//因为时间和体力的消耗相等，所以可以看做是一个限制，因为体力>0，所以限制取t,e-1的小值；
    for(int i=1;i<=q;i++)
        for(int j=t;j>=c[i];j--)
            dp[j]=max(dp[j],dp[j-c[i]]+v[i]);//状态转移方程，和01是一样的；
    cout<<dp[t];
    return 0;
}
