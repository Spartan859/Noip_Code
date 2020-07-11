#include<iostream>
#define N 105
using namespace std;
int dx[8]={1,1,1,0,0,-1,-1,-1}; 
int dy[8]={1,0,-1,1,-1,1,0,-1};
int n,m,a,b;
char d[N][N];
bool vst[N][N];
void dfs(int x,int y){
	vst[x][y]=1;
	if(vst[n][m])return;
	for(int k=0;k<8;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&d[nx][ny]=='-'&&!vst[nx][ny])
			dfs(nx,ny);
	}
}
int main(){
	cin>>n>>m>>a>>b;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>d[i][j];
	dfs(a,b);
	if(vst[n][m])cout<<"Sadly yes"<<endl;
	else cout<<"Luckily no"<<endl;
	return 0;
}
