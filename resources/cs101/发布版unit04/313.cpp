#include<iostream>
#define N 4
using namespace std;
int d[4][4],g[4][4],i,j;
int main(){
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			char ch; cin>>ch;
			d[i][j]=ch-'0';
		}
		////
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(i==0&&j==0) g[0][0]=d[i][j];
			else g[i][j]=max(max(g[i-1][j],g[i][j-1]),g[i-1][j-1])+d[i][j]-1;
	cout<<g[N-1][N-1]<<endl;
	return 0;
}
