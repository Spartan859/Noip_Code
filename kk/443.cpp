#include<bits/stdc++.h>
#define INF 1e8
using namespace std;
int dx[4]={0,1,0,-1}; 
int dy[4]={1,0,-1,0};
int ans=INF;
bool vst[105][105];
void dfs(int x,int y,int c,int money,bool magic){
	if(x==m&&y==m){
		ans=min(ans,money)
		return;
	}
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=1&&nx<=m&&ny>=1&&ny<=m&&!vst[nx][ny]){
			if()
		}
	}
}
int main(){
	
} 
