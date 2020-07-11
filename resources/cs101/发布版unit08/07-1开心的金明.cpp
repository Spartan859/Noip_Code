#include<iostream>
#define M 30
#define N 30005
using namespace std;
int p[M],level[M],f[M][N],i,j,n,m;
int main(){
	cin>>n>>m;
	for(i=1;i<=m;i++) cin>>p[i]>>level[i];
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			f[i][j]=f[i-1][j];
			if(p[i]<=j) 
				f[i][j]=max(f[i][j],f[i-1][j-p[i]]+p[i]*level[i]);
		}
	}
	cout<<f[m][n]<<endl;
	return 0;
}
