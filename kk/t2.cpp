#include<iostream>
#define N 205
using namespace std;
int dx[4]={0,1,0,-1}; 
int dy[4]={1,0,-1,0};
char d[N][N];
bool vst[N][N];
int n,m,a,b,zcans=0,zc=0;
void dfs(int x,int y){
	vst[x][y]=1;
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(d[nx][ny]=='.') zc++;
		else if(!vst[nx][ny]) dfs(nx,ny);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<=m+1;i++) d[n+1][i]=d[0][i]='.';
	for(int i=0;i<=n+1;i++) d[i][m+1]=d[i][0]='.';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>d[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(d[i][j]=='M'&&!vst[i][j]){
				dfs(i,j);
				if(zc>zcans) zcans=zc;
				zc=0;
			}
	cout<<zcans<<endl;
	return 0;
}
