#include<bits/stdc++.h>
using namespace std;
int p,n,m,k,dp[210][50],sum[210][210];
string s,a[10];
inline int read(){
    int date=0,w=1;char c=0;
    while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
    while(c>='0'&&c<='9'){date=date*10+c-'0';c=getchar();}
    return date*w;
}
bool check(int l,int r){
    string x=s.substr(l,r-l+1);
    for(int i=1;i<=n;i++)if(x.find(a[i])==0)return true;
    return false;
}
void init(){
    string ch;
    s+='0';
    p=read();k=read();
    for(int i=1;i<=p;i++){
        cin>>ch;
        s+=ch;
    }
    n=read();m=s.length()-1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=m;i>=1;i--)
    for(int j=i;j>=1;j--){
        sum[j][i]=sum[j+1][i];
        if(check(j,i))sum[j][i]++;
    }
}
void work(){
    dp[0][0]=0;
    for(int i=1;i<=k;i++)dp[i][i]=dp[i-1][i-1]+sum[i][i];
    for(int i=1;i<=m;i++)dp[i][1]=sum[1][i];
    for(int i=1;i<=m;i++)
    for(int j=1;j<=k&&j<i;j++)
    for(int l=j;l<i;l++)
    dp[i][j]=max(dp[i][j],dp[l][j-1]+sum[l+1][i]);
    printf("%d\n",dp[m][k]);
}
int main(){
    init();
    work();
    return 0;
}
