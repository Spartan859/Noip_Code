#include<bits/stdc++.h>
#define INF 10000
#define N 12
using namespace std;
int dist[N][N][2],m,n;
int dx[4]={0,1,0,-1}; 
int dy[4]={1,0,-1,0};
char f[N][N];
void dfs(int x,int y,int len,int life){
	if(len>=dist[x][y][life]) return;
	dist[x][y][life]=len;
	if(x==n&&y==m){
		return;
	}
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
		    if(f[nx][ny]=='o') dfs(nx,ny,len+1,life);
		    else if(life!=0) dfs(nx,ny,len+1,0);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	        cin>>f[i][j];
	fill(dist[0][0],dist[0][0]+N*N*2,INF);
	dfs(1,1,0,1);
	int ans=min(dist[n][m][0],dist[n][m][1]);
	if(ans!=INF) cout<<ans<<endl;
	else cout<<"mission impossible"<<endl;
	return 0;
}
