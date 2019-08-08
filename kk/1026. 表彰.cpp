#include <bits/stdc++.h>
#define N 1005
using namespace std;
struct hhld{
	int x,w;
}a[N];

int dp1[N][N],dp2[N][N];
int n,ork,s[N],ans;

int rgs(int l,int r) { return s[r]-s[l-1]; }

int main(){
	cout<<1<<endl;
    //freopen("location.in", "r", stdin);
    //freopen("location.out", "w", stdout);
    
    memset(dp1,0x3f,sizeof(dp1));
    memset(dp2,0x3f,sizeof(dp2));
    scanf("%d",&n);
    scanf("%d",&ork);
    for(int i=1;i<=n;i++) scanf("%d %d",&a[i].x,&a[i].w);
    a[++n].x=ork;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i].w;
    for(int i=1;i<=n;i++) if(a[i].w==0&&a[i].x==ork) dp1[i][i]=dp2[i][i]=0;
    for(int k=1;k<n;++k)
        for(int i=1,j=i+k;i<=n&&j<=n;i++,j=i+k){
            dp1[i][j]=min(dp1[i+1][j]+(rgs(1,i)+rgs(j+1,n))*(a[i+1].x-a[i].x),dp2[i+1][j]+(rgs(1,i)+rgs(j+1,n))*(a[j].x-a[i].x));
            
            dp2[i][j]=min(dp2[i][j-1]+(rgs(1,i-1)+rgs(j,n))*(a[j].x-a[j-1].x),dp1[i][j-1]+(rgs(1,i-1)+rgs(j,n))*(a[j].x-a[i].x));
        }
    ans=min(dp1[1][n],dp2[1][n]);
    printf("%d\n",ans);
    return 0;
}
