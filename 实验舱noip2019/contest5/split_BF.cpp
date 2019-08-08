#include<bits/stdc++.h>
#define ABS(x) (((x)>0)?(x):(-(x)))
#define N 45
#define INF 2e18
#define ll long long
using namespace std;
ll n,m,ans=INF;
ll B[N],C[N],A[N];

void dfs(ll i,ll x,ll y){
	if(i==n+1){
		ll ansx=0;
		for(ll i=1;i<=m;i++)
			for(ll j=1;j<=n-m;j++) ansx+=ABS(B[i]-C[j]);
		ans=min(ans,ansx);
		return;
	}
	if(x<=m){
		B[x]=A[i];
		dfs(i+1,x+1,y);
		B[x]=0;
	}
	if(y<=n-m){
		C[y]=A[i];
		dfs(i+1,x,y+1);
		C[y]=0;
	} 
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("split1.in","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",A+i);
	dfs(1,1,1);
	printf("%lld\n",ans);
	return 0;
}
