#include<iostream>
#define N 4005
#define ull unsigned long long
using namespace std;
ull n,m,f[N][N],i,j,ans,k;//n拆分成若干个不同正整数,最大数不超过m
int main() {
    cin>>m>>n;
    f[1][1]=1;
    for(i=2; i<=n; i++)
        for(j=1; j<=min(i,m); j++)
            f[i][j]=f[i-1][j-1]+f[i-j][j];
    for(k=1; k<=m; k++) {
        int tmp=n-k*(k-1)/2;
        if(tmp>=0) ans+=f[tmp][k];
    }
    cout<<ans;
    return 0;
}
