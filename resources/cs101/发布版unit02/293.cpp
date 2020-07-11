#include<iostream>
using namespace std;
int main(){
	long long c[23][23],n,m,x,y;
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++) c[i][1]=1;
	for(int i=2;i<=m;i++) c[1][i]=1;
	c[x][y]=0;
	for(int a=2;a<=n;a++){
	    for(int b=2;b<=m;b++){
	    	if(a!=x||b!=y) c[a][b]=c[a][b-1]+c[a-1][b];
	    }
	}
	cout<<c[n][m]<<endl;
	return 0;
}
