#include<iostream>
#define M 21
using namespace std;
long long f[M][M],n,m,i,j;
int main(){
	cin>>n>>m;
	for(j=1;j<=m;j++) f[1][j]=1;
	for(i=2;i<=n;i++){
		f[i][1]=1;
		for(j=2;j<=m;j++)
			f[i][j]=f[i-1][j]+f[i][j-1];
	}
	cout<<f[n][m]<<endl;	
	return 0;
}


