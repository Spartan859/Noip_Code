#include<bits/stdc++.h>
#define N 8
using namespace std;
int ans=0,f[N][N];
bool clmn[N],d1[2*N],d2[2*N],hang[N];
char tch;
bool valid(int x,int y){
	return !clmn[y]&&!d1[x+y]&&!d2[x-y+N-1];
}
void dfs(int x){
	if(x==N){
		ans++;
		return;
	}
	if(hang[x]) dfs(x+1);
	for(int y=0;y<N;y++)
	    if(valid(x,y)){
	    	f[x][y]=clmn[y]=d1[x+y]=d2[x-y+N-1]=1;
	    	dfs(x+1);
	    	f[x][y]=clmn[y]=d1[x+y]=d2[x-y+N-1]=0;
		}
}
int main(){
	for(int i=0;i<N;i++)
	   for(int j=0;j<N;j++){
	   	    cin>>tch;
	   	    if(tch=='Q'){
			   hang[i]=1;
			   f[i][j]=clmn[j]=d1[i+j]=d2[i-j+N-1]=1;
			}
	   }
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
/*
Qooooooo
oooooooo
oooooooo
oooooooo
oooooooo
oooooooo
oooooooo
oooooooo
*/
