#include<iostream>
#define INF 1e8
#define N 30
using namespace std;
int n,m,ans=INF,c[N][N];
bool vst[N];
void dfs(int x,int cost){
	if(x==n){ans=min(ans,cost);return;}
	for(int i=0;i<m;i++)
		if(!vst[i]){
			vst[i]=1;
			dfs(x+1,cost+c[x][i]);
			vst[i]=0;
		}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>c[i][j];
	dfs(0,0);	
	cout<<ans<<endl;
	return 0;
}
