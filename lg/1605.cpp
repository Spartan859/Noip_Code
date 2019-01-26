#include<bits/stdc++.h>
#define N 10
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int fx,fy,sx,sy,ans=0,n,m,t,tx,ty;
bool f[N][N],vst[N][N];
void dfs(int x,int y){
	if(x==fx&&y==fy){
		ans++;
		return;
	}
	vst[x][y]=1;
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!f[nx][ny]&&!vst[nx][ny])
		    dfs(nx,ny);
	}
	vst[x][y]=0;
}
int main(){
	cin>>n>>m>>t;
	cin>>sx>>sy>>fx>>fy;
	for(int i=0;i<t;i++){
		cin>>tx>>ty;
		f[tx][ty]=1;
	}
	dfs(sx,sy);
	cout<<ans<<endl;
	return 0;
}
