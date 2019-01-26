#include<iostream>
#define N 105
using namespace std;
int dx[4]={0,1,0,-1};//ÓÒÏÂ×óÉÏ 
int dy[4]={1,0,-1,0};
char d[N][N];
int n,m,area,onub;
int dfs(int x,int y){
	area++;
	if(x<1||x>n||y<1||y>m){
		area--;
		return 0;
	}
	d[x][y]='*';
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(d[nx][ny]=='o')
			if(dfs(nx,ny)) return 1;
	}
	bool f=false; 
	d[x][y]='o';
	if(area==onub) return 1;
	area--;
	return 0;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>d[i][j];
			if(d[i][j]=='o') onub++;
		}
	if(dfs(1,1))cout<<"Yes";
	else cout<<"No";
	return 0;
}
