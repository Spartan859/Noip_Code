#include<iostream>
#include<string>
#include<algorithm>
#define N 4
#define GUNS 6
using namespace std;
int ans=0,f[N][N];
void print(){
	cout<<ans<<":"<<endl;
	for(int i=0;i<N;i++,cout<<endl)
		for(int j=0;j<N;j++)cout<<f[i][j];	
}
bool valid(int x,int y){
	for(int i=1;i<=min(x,y);i++)
		if(f[x-i][y-i])return 0;	
	for(int i=1;i<=min(x,N-1-y);i++)
		if(f[x-i][y+i])return 0;
	return 1;
}
void dfs(int x,int y,int c){ 
	if(c==GUNS){ans++;print();return;}
	if(x==N)return;
	int nx=(y==N-1?x+1:x);
	int ny=(y==N-1?0:y+1);
	if(valid(x,y)){
		f[x][y]=1;
		dfs(nx,ny,c+1);
		f[x][y]=0;
	}
	dfs(nx,ny,c);
}
int main(){
	dfs(0,0,0);
	return 0;
}


