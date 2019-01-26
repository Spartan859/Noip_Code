#include<iostream>
#define N 105
using namespace std;
int dx[4]={0,1,0,-1}; 
int dy[4]={1,0,-1,0};
char d[N][N];
bool vst[N][N];
int a,b,cnt;
void dfs(int x,int y){
	vst[x][y]=1;
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=1&&nx<=10&&ny>=1&&ny<=10&&d[nx][ny]=='#'&&!vst[nx][ny])
			dfs(nx,ny);
	}
}
int main(){
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
			cin>>d[i][j];
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++){
			if(d[i][j]=='#'&&!vst[i][j]&&(d[i][j+1]=='#'||d[i+1][j]=='#'||d[i][j-1]=='#'||d[i-1][j]=='#')){
				cnt++;
				dfs(i,j);
			}
		}
	cout<<cnt<<endl;
	return 0;
}
