#include<iostream>
#define M 21
using namespace std;
long long f[M][M],n,m,x1,y1,x2,y2,x3,y3,i,j;
int main(){
	cin>>n>>m;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	f[1][1]=1;
	f[x1][y1]=0;
	f[x2][y2]=0;
	f[x3][y3]=0;
	for(i=1;i<=n;i++) 
		for(j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			if(x1==i&&y1==j) continue;
			if(x2==i&&y2==j) continue;
			if(x3==i&&y3==j) continue;
			f[i][j]=f[i-1][j]+f[i][j-1];
		}
	cout<<f[n][m]<<endl;
	return 0;
}
