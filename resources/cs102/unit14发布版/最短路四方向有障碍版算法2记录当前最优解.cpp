#include<iostream>
#include<algorithm>
#define N 20
#define INF 10000
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,dist[N][N];
char f[N][N];
void dfs(int x,int y,int len){
	if(len>=dist[x][y])return;
	dist[x][y]=len;
	if(x==n&&y==m)return;
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&f[nx][ny]=='o')
			dfs(nx,ny,len+1);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>f[i][j];
	fill(dist[0],dist[0]+N*N,INF);
	dfs(1,1,0);
	int ans=dist[n][m];
	if(ans<INF)cout<<ans<<endl;
	else cout<<"no way"<<endl;
	return 0;
}


