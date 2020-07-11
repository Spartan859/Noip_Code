#include<iostream>
#define N 4
using namespace std;
int d[5][5],g[5][5],i,j;
int main(){
	g[0][0]=-10;
	g[1][0]=-10;
	g[2][0]=-10;
	g[3][0]=-10;
	g[4][0]=-10;
	g[0][1]=-10;
	g[0][2]=-10;
	g[0][3]=-10;
	g[0][4]=-10;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++){
			char ch; cin>>ch;
			d[i][j]=ch-'0';
		}
		////
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			if(i==1&&j==1) g[1][1]=d[i][j];
			else g[i][j]=max(max(g[i-1][j],g[i][j-1]),g[i-1][j-1])+d[i][j]-1;
	cout<<g[N][N]<<endl;
	return 0;
}
