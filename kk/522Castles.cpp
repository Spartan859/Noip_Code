#include<bits/stdc++.h>
#define N 5
using namespace std;
int ans=0,f[N][N],v[N][N];
char ch;
bool valid(int x,int y){
	if(!v[x][y]) return 0;//if wall,no place
	for(int i=1;i<=x;i++)
		if(f[x-i][y]) return 0;
		else if(!v[x-i][y]) break;
		
	for(int i=1;i<=N-x-1;i++)
		if(f[x+i][y]) return 0;
		else if(!v[x+i][y]) break;
		
	for(int i=1;i<=y;i++)
	    if(f[x][y-i]) return 0;
		else if(!v[x][y-i]) break;
		
	for(int i=1;i<=N-y-1;i++)
	    if(f[x][y+i]) return 0;
	    else if(!v[x][y+i]) break;
	
	return 1;
}
void dfs(int x,int y,int c){
	if(x==N){
		ans=max(ans,c);
	    return;
	}
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
	for(int i=0;i<N;i++)
	    for(int j=0;j<N;j++){
	    	cin>>ch;
	    	if(ch=='.') v[i][j]=1;
		}     
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}


