#include<bits/stdc++.h>
#define N 15
#define ll long long
using namespace std;
ll tst[N];
ll ans,n;
void dfs(ll x){
	if(x==n+1){
		for(ll i=1;i<=n;i++)
			if(tst[i]==1)
				if(tst[i-1]==0&&tst[i+1]==0) return;
		++ans;
		return;
	}
	tst[x]=0;
	dfs(x+1);
	tst[x]=1;
	dfs(x+1);
	tst[x]=0;
}
int main(){
	scanf("%lld",&n);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}

