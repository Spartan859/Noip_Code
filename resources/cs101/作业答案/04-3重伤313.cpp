#include<iostream>
#define N 4
#define M 5
using namespace std;
int d[M][M],f[M][M],i,j;
int main(){
	fill(f[0],f[0]+M*M,-6);
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++){
			char ch; cin>>ch;
			d[i][j]=ch-'0';
		}
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			if(i==1&&j==1) f[1][1]=d[1][1];
			else {
				int tmp=max(f[i-1][j],f[i][j-1]);
				tmp=max(tmp,f[i-1][j-1]);
				f[i][j]=d[i][j]+tmp-1;
			}
	cout<<f[N][N]<<endl;	
	return 0;
}


