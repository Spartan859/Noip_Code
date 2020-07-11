#include<iostream>
#define N 21
using namespace std;
long long f[N][N],n,m,i,j;
bool beast[N][N];//记录有没有野兽 
int main(){
	cin>>n>>m;
	for(i=1;i<=3;i++){
		int x,y; cin>>x>>y;
		beast[x][y]=1;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(i==1&&j==1) f[1][1]=(!beast[1][1]);
			else if(beast[i][j]) f[i][j]=0;
			else f[i][j]=f[i-1][j]+f[i][j-1];
	cout<<f[n][m]<<endl;	
	return 0;
}


