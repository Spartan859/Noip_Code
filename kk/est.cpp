#include<bits/stdc++.h>
using namespace std;
int N,M,T;
string str[55];
int dp[55][55][2555][2];//�� λ�� �������� ��ȷ��� 
int main()
{
    cin>>N>>M>>T;
    for(int i=1;i<=N;i++) cin>>str[i];
    memset(dp,0,sizeof(dp));
    int maxz=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<M;j++)
        {
            for(int k=1;k<=T;k++)
            {
                    if(j==0)
                    {
                        dp[i][j][k][1]=max(dp[i-1][M-1][k-1][0],dp[i-1][M-1][k-1][1])+1;//����һ��k-1����ʱ������ 
                        dp[i][j][k][0]=max(dp[i-1][M-1][k-1][0],dp[i-1][M-1][k-1][1]);    
                    }
                    else if(str[i][j]==str[i][j-1]) 
                    {
                        dp[i][j][k][1]=max(dp[i][j-1][k-1][0],dp[i][j-1][k][1])+1;//��Ϊ�ϴδ��󣬹�һ������һ����Ӧ��Ϊk-1�� 
                        dp[i][j][k][0]=max(dp[i][j-1][k][0],dp[i][j-1][k-1][1]);
                    }
                    else 
                    {
                        dp[i][j][k][1]=max(dp[i][j-1][k][0],dp[i][j-1][k-1][1])+1;//ͬ�� 
                        dp[i][j][k][0]=max(dp[i][j-1][k][1],dp[i][j-1][k-1][0]);
                    }
            }
            maxz=max(maxz,max(dp[i][j][T][1],dp[i][j][T][0]));
            
        }
    }
    cout<<maxz<<endl; 
}
