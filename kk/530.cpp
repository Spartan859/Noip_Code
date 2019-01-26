#include<bits/stdc++.h> 
#define N 20
#define INF 10000
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,dist[N][N],stx,sty,enx,eny;
char f[N][N];
void dfs(int x,int y,int len){
	if(len>=dist[x][y])return;
	dist[x][y]=len;
	if(x==enx&&y==eny)return;
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&f[nx][ny]!='#')
			dfs(nx,ny,len+1);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
		    cin>>f[i][j];
		    if(f[i][j]=='L') {
			    stx=i;
				sty=j;
			}
			else if(f[i][j]=='J'){
				enx=i;
				eny=j;
			}
		}
			
	fill(dist[0],dist[0]+N*N,INF);
	dfs(stx,sty,0);
	int ans=dist[enx][eny];
	if(ans<INF){
		double sec=ans/2.;
		cout<<fixed<<setprecision(1)<<sec<<endl;
	}
	else cout<<"forever"<<endl;
	return 0;
}
