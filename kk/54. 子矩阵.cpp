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
    for(int i=1;i<=m;i++) {  //�ڵ�i��֮������Ĳ�ֵ֮�� 
        val[i]=0;
        for(int j=1;j<r;j++)
        val[i]+=abs(a[R[j]][i]-a[R[j+1]][i]);
    }
     
    for(int i=1;i<=m;i++)   //�����ڵ�i�����j��֮�� ���Ĳ�ֵ֮�� 
        for(int j=i+1;j<=m;j++) {
            cost[i][j]=0;
            for(int k=1;k<=r;k++) 
                cost[i][j]+=abs(a[R[k]][i]-a[R[k]][j]);
       }
     
    for(int i=1;i<=m;i++) //ǰi��֮�� ��i��ǿ��ѡ�� 
        for(int j=1;j<=i&&j<=c;j++) { //�Ѿ�ѡ��j�� 
        dp[i][j]=1e9;
        for(int k=j-1;k<i;k++) //    ��j-1�п�ʼ �ڵ�j-1�е���i��֮��ѡ��j�� �ټ��ϵ�i�еĻ��� 
            dp[i][j]=min(dp[i][j],dp[k][j-1]+cost[k][i]+val[i]);    //��ǰk����ѡȡ��j-1�� ��ѡȡ��j�� 
    }
    
    for(int i=c;i<=m;i++) //��ǰi����ѡ��c�� 
        ret=min(ret,dp[i][c]);
    return ret;
 }
//nowΪ��ǰ�������еı�ţ�cntΪ�ҵ����е���Ŀ���ҵ����еı�ŷ��� R[]������ 
inline void slect(int now,int cnt) {// ����ѡȡr��
    if(now>n) {//n�ж��������� 
        if(cnt==r) ans=min(ans,DP());//��r���Һ��ˣ����Ǿ�DP 
        return;
    }
    slect(now+1,cnt);//��ѡ��һ�� 
    R[cnt+1]=now;//��¼ѡ������ 
    slect(now+1,cnt+1);//ѡ��һ�� 
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
