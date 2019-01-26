#include<iostream>
#define N 205
using namespace std;
int dx[8]={1,1,1,0,0,-1,-1,-1}; 
int dy[8]={1,0,-1,1,-1,1,0,-1};
char d[N][N];
bool vst[N][N];
int n,m,a,b,area=0,temp,h;
void dfs(int x,int y){
	vst[x][y]=1;
	area++;
	for(int k=0;k<8;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=0&&nx<=n+1&&ny>=0&&ny<=m+1&&d[nx][ny]=='-'&&!vst[nx][ny])
			dfs(nx,ny);
	}
}
int main(){
	cin>>n>>h; m=n; a=0; b=0;
	for(int i=0;i<=n+1;i++) d[0][i]=d[i][0]=d[n+1][i]=d[i][n+1]='-';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>temp;
			if(temp>h) d[i][j]='+';
			else d[i][j]='-';
		}
	dfs(a,b);
	area-=4*n+4;
	cout<<n*n-area<<endl;
	return 0;
}
