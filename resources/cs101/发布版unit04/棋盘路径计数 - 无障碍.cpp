#include<iostream>
#define M 21
using namespace std;
long long f[M][M],n,m,i,j;
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(i==1&&j==1) f[1][1]=1;
			else f[i][j]=f[i-1][j]+f[i][j-1];
	cout<<f[n][m]<<endl;	
	return 0;
}


