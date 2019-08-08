#include<bits/stdc++.h>
using namespace std;
int n,m,ans,tmpans;
int fdj[30],zdy[30];
void dfs(int x,int y){
	tmpans++;
	if(tmpans>ans) ans=tmpans;
	fdj[x-y+10]=1;zdy[x+y]=1;
	int nx,ny;
	for(int i=n;x+y+1-i<=m&&i>=1;i--){
		nx=i;ny=x+y+1-i;
		if(ny<1) continue;
		if(fdj[nx-ny+10]==1) continue;
		
		dfs(nx,ny);
	}
	tmpans--;
	fdj[x-y+10]=0;
	zdy[x+y]=0;
}
int main(){
	freopen("volunteer.in","r",stdin);
	freopen("volunteer.out","w",stdout);
	scanf("%d %d",&n,&m);
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}
