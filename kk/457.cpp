#include<iostream>
#define N 505
#define M 15
using namespace std;
long long f[N][M],ans=0;
int n,m;
int main(){
	cin>>n>>m;
	f[1][1]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=min(i,m);j++)
			f[i][j]=f[i-1][j-1]+f[i-j][j];
	for(int i=1;i<=m;i++) ans+=f[n][i];//从(n,1)的情况加到(n,m)
	cout<<ans<<endl;
	return 0;
}
