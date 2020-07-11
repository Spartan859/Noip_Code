#include<iostream>
#define N 5
using namespace std;
int f[6][6],i,j;
char d[6][6];
int main(){
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			cin>>d[i][j];
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			if(i==1&&j==1) f[1][1]=(d[i][j]=='0');
			else if(d[i][j]=='#') f[i][j]=0;
			else f[i][j]=f[i-1][j]+f[i][j-1];
	cout<<f[N][N]<<endl;	
	return 0;
}


