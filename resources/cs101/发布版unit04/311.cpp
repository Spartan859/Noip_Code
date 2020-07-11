#include<iostream>
#define N 5
using namespace std;
int d[6][6],g[6][6],i,j;
int main(){
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++){
			char ch; cin>>ch;
			if(ch=='*') d[i][j]=-1;
			else d[i][j]=ch-'0';
		}
	fill(g[0],g[0]+36,-10);	
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			if(i==1&&j==1) g[1][1]=d[i][j];
			else g[i][j]=max(g[i-1][j],g[i][j-1])+d[i][j];
	cout<<g[N][N]<<endl;
	return 0;
}
