#include<iostream>
#define N 5
#define M 6
using namespace std;
int g[M][M],i,j;
char d[M][M];
int main(){
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			cin>>d[i][j];
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++) {
			int tmp=max(g[i-1][j],g[i][j-1]);
			if(d[i][j]=='*')
				g[i][j]=tmp-1;
			else
				g[i][j]=tmp+d[i][j]-'0';
		}
	cout<<g[N][N]<<endl;	
	return 0;
}


