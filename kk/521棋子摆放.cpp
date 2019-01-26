#include<iostream>
#include<algorithm>
#define N 8
using namespace std;
int ans=0,n,k;
bool f[N][N],v[N][N],clmn[N],hang[N];
char ch;
bool valid(int x,int y){
	return !clmn[y]&&!hang[x]&&v[x][y];
}
void dfs(int x,int y,int c){ 
	if(c==k){ans++;return;}
	if(x==N)return;
	int nx=(y==N-1?x+1:x);
	int ny=(y==N-1?0:y+1);
	if(valid(x,y)){
		f[x][y]=clmn[y]=hang[x]=1;
		dfs(nx,ny,c+1);
		f[x][y]=clmn[y]=hang[x]=0;
	}
	dfs(nx,ny,c);
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++){
	    	cin>>ch;
	    	if(ch=='o') v[i][j]=1;
		}
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}
