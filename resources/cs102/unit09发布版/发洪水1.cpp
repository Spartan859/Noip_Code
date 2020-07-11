#include<iostream>
#define N 105
using namespace std;
int dx[8]={1,1,1,0,0,-1,-1,-1}; 
int dy[8]={1,0,-1,1,-1,1,0,-1};
char d[N][N];
int n,m,a,b;
void dfs(int x,int y){
	d[x][y]='@';
	for(int k=0;k<8;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&d[nx][ny]=='-')
			dfs(nx,ny);
	}
}
void print(){
	for(int i=1;i<=n;i++,cout<<endl)
		for(int j=1;j<=m;j++)cout<<d[i][j];
}
int main(){
	cin>>n>>m>>a>>b;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>d[i][j];
	dfs(a,b);
	print();
	return 0;
}
