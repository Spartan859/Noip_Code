#include<iostream>
#define M 51
using namespace std;
long long c[M][M],n,m,i,j;
int main(){
	cin>>n>>m;
	c[0][0]=1;
	for(i=1;i<=n;i++){
		c[i][0]=1;
		for(j=1;j<=m;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	cout<<c[n][m]<<endl;	
	return 0;
}
