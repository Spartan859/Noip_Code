#include<bits/stdc++.h>
#define N 20
using namespace std;
int dx[8]={1,1,1,0,0,-1,-1,-1}; 
int dy[8]={1,0,-1,1,-1,1,0,-1};
int n,ans=0;
bool vst[N][N]={0};
int maps[N][N];
void dfs(int x,int y){
	if(x==1&&y==n) {
		ans++;
		return;
	}
	vst[x][y]=1;
	for(int k=0;k<8;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&maps[nx][ny]==0&&!vst[nx][ny]) dfs(nx,ny);
	}
	vst[x][y]=0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)
	       cin>>maps[i][j];
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
} 
