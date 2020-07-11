#include<iostream>
#define N 15
using namespace std;
int ans=0,f[N][N],n;
bool clmn[N],d1[2*N],d2[2*N];
void print(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(f[i][j]==1) cout<<j+1<<' '; 
		}
	cout<<endl;
}
bool valid(int x,int y){
	return!clmn[y]&&!d1[x+y]&&!d2[x-y+N-1];
}	
void dfs(int x){ 
	if(x==n){
	    ans++;
	    if(ans<=3) print();
		return;
	}
	for(int y=0;y<n;y++)
		if(valid(x,y)){
			f[x][y]=clmn[y]=d1[x+y]=d2[x-y+N-1]=1;
			dfs(x+1);
			f[x][y]=clmn[y]=d1[x+y]=d2[x-y+N-1]=0;
		}
}
int main(){
	cin>>n;
	dfs(0);
	cout<<ans<<endl;
	return 0;
}


