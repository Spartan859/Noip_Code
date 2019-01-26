#include<bits/stdc++.h>
#define INF 10000
#define N 25
using namespace std;
int dist[N][N],m,n,ans=INF;
int dx[4]={0,1,0,-1}; 
int dy[4]={1,0,-1,0};
char f[N][N];
void dfs(int x,int y,int len){
	if(len>=dist[x][y]) return;
	dist[x][y]=len;
	if(x==n&&y==m){
		ans=min(len,ans);
		return;
	}
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
		    if(f[nx][ny]==f[x][y]) dfs(nx,ny,len);
		    else dfs(nx,ny,len+1);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	        cin>>f[i][j];
	fill(dist[0],dist[0]+N*N,INF);
	dfs(1,1,0);
	cout<<ans<<endl;
	return 0;
}
