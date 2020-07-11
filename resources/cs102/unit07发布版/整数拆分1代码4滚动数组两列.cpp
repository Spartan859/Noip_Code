#include<iostream>
#define N 15
#define M 15 
using namespace std;
int n,m,f[N][2];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n-m+1;i++)f[i][1]=1;
	int r=0;
	for(int j=2;j<=m;j++,r=1-r)
		for(int i=j;i<=n-m+j;i++)
			f[i][r]=f[i-1][1-r]+f[i-j][r];
	cout<<f[n][1-r]<<endl;
	cout<<"-----"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=1;j++)
			cout<<f[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
