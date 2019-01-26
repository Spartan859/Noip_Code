#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXN 20 

using namespace std;
 
int a[MAXN][MAXN],n,m,r,c,ans;
 
int R[MAXN],cost[MAXN][MAXN],dp[MAXN][MAXN],val[MAXN];
 
inline void read(int &x) {
    int f=1;x=0;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-48;c=getchar();}
    x=x*f;
}

void printArr_dp(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%4d ",dp[i][j]);
        }
        cout<<endl;;
    }
}
 
inline int DP() {
    int ret=1e9;
    for(int i=1;i<=m;i++) {  //在第i列之间的数的差值之和 
        val[i]=0;
        for(int j=1;j<r;j++)
        val[i]+=abs(a[R[j]][i]-a[R[j+1]][i]);
    }
     
    for(int i=1;i<=m;i++)   //处理在第i列与第j列之间 数的差值之和 
        for(int j=i+1;j<=m;j++) {
            cost[i][j]=0;
            for(int k=1;k<=r;k++) 
                cost[i][j]+=abs(a[R[k]][i]-a[R[k]][j]);
       }
     
    for(int i=1;i<=m;i++) //前i列之中 第i列强制选择 
        for(int j=1;j<=i&&j<=c;j++) { //已经选了j列 
        dp[i][j]=1e9;
        for(int k=j-1;k<i;k++) //    从j-1列开始 在第j-1列到第i列之中选第j列 再加上第i列的花费 
            dp[i][j]=min(dp[i][j],dp[k][j-1]+cost[k][i]+val[i]);    //在前k列中选取了j-1列 再选取第j列 
    }
    
    for(int i=c;i<=m;i++) //在前i列中选了c列 
        ret=min(ret,dp[i][c]);
    return ret;
 }
//now为当前遍历的行的编号，cnt为找到的行的数目，找到的行的编号放在 R[]数组中 
inline void slect(int now,int cnt) {// 任意选取r行
    if(now>n) {//n行都搜索完了 
        if(cnt==r) ans=min(ans,DP());//这r行找好了，我们就DP 
        return;
    }
    slect(now+1,cnt);//不选这一行 
    R[cnt+1]=now;//记录选的这行 
    slect(now+1,cnt+1);//选这一行 
    return;
}
 
int main() {
    freopen("submatrix.txt","r",stdin); 
    read(n);read(m);read(r);read(c);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        read(a[i][j]);
    ans=1e9;
    slect(1,0);
    printf("%d\n",ans);
    return 0;
}
