#include<iostream>
#define N 15
#define M 15 
using namespace std;
int n,m,f[N][M];
int main(){
	cin>>n>>m;
	for(int j=1;j<=m;j++)f[j][j]=1;
	for(int k=1;k<=n-m;k++)
		for(int j=1;j<=m;j++){
			int i=j+k;
			f[i][j]=f[i-1][j-1]+f[i-j][j];
		}
	cout<<f[n][m]<<endl;
	cout<<"-----"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<f[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
