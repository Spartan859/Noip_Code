#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[105][105],ans,tmp,cnt;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
void dfs(ll x,ll y){
	for(ll k=0;k<4;k++){
		ll nx=x+dx[k],ny=y+dy[k];
		if(nx==0) nx=n;
		if(nx==n+1) nx=1;
		if(ny==0) ny=n;
		if(ny==n+1) ny=1;
		if(a[nx][ny]==0){
			a[nx][ny]=a[x][y]=1;tmp+=2;
			ans=max(ans,tmp);
			for(ll i=1;i<=n;i++)
				for(ll j=1;j<=n;j++)
					if(!a[i][j])
						dfs(i,j);
			a[nx][ny]=a[x][y]=0;tmp-=2;
		}
	}
} 
int main(){
	//freopen("glory.in","r",stdin);
	//freopen("glory.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]==0) cnt++;
		}
	if(cnt==n*n){
		if(cnt%2) cout<<cnt-1<<endl;
		else cout<<cnt<<endl;
		return 0;
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(!a[i][j]) dfs(i,j);
	cout<<ans<<endl;
	return 0;
}
