#include <iostream>
#define M 505
#define N 2005
using namespace std;
int n,m,w[M],v[M],f[M][N]; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>w[i]>>v[i];		
	for(int i=1;i<=m;i++)
		for(int j=w[i];j<=n;j++) 
			f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
	cout<<f[m][n]<<endl;
	return 0;
}
