#include<iostream>
#define M 21
using namespace std;
long long f[M][M],n,m,x,y,i,j;
int main(){
	cin>>n>>m>>x>>y;
	f[1][1]=1;
	for(j=1;j<=m;j++) //第1行 
		if(x==1&&y==j) break;
		else f[1][j]=1;
	for(i=2;i<=n;i++) //第2到n行 
		for(j=1;j<=m;j++){
			if(x==i&&y==j) continue;
			if(j==1) f[i][1]=1;
			else f[i][j]=f[i-1][j]+f[i][j-1];
		}
	cout<<f[n][m]<<endl;	
	return 0;
}


