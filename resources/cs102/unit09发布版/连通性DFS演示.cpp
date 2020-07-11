#include<iostream>
#define N 105
using namespace std;
int dx[4]={0,1,0,-1};//ÓÒÏÂ×óÉÏ 
int dy[4]={1,0,-1,0};
char d[N][N];
int n,m;
void print(){
	cout<<"============="<<endl;
	for(int i=1;i<=n;i++,cout<<endl)
		for(int j=1;j<=m;j++)cout<<d[i][j];
	string s;getline(cin,s);
}
void dfs(int x,int y){
	if(x<1||x>n||y<1||y>m)return;
	d[x][y]='*';
	print();
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(d[nx][ny]=='.')
			dfs(nx,ny);
	}
	d[x][y]='.'; 
	print();
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>d[i][j];
	dfs(1,1);
	return 0;
}
/*
4 5
.....
.+.+.
.++++
.....

7 7
...+...
.+.+.+.
.+...+.
.++++++
.......
.+.+.+.
.......
*/
