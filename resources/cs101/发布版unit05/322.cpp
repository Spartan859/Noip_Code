#include <iostream>
using namespace std;
int n=100,m=5,w[6],v[6],f[6][101];
int main(){
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++)
		for(int j=0;j<=n;j++) {  //循环查看背包剩余承重j 
			if(j<w[i])   //金块i太重，无法放入 
				f[i][j]=f[i-1][j];
			else 		//比较两种决策：金块i可以放，或者不放
				f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+w[i]);
		}
	cout<<f[m][n]<<endl; 
	return 0;
}
