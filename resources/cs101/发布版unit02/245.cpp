#include<bits/stdc++.h>
using namespace std;
int main(){
	int c[21][21],n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) c[i][1]=1;
	for(int i=1;i<=m;i++) c[1][i]=1;
	for(int a=2;a<=n;a++)
	    for(int b=2;b<=m;b++)
	    	c[a][b]=c[a][b-1]+c[a-1][b];
	cout<<c[n][m];
	return 0;
}
