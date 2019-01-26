#include<iostream>
#define N 205
#define M 11
using namespace std;
int n,m,f[N][M];
int main(){
	cin>>n>>m;
	f[1][1]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=min(i,m);j++)
			f[i][j]=f[i-1][j-1]+f[i-j][j];
	cout<<f[n][m]<<endl;
	return 0;
}
