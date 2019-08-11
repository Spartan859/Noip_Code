#include<bits/stdc++.h>
#define N 20
#define ll long long
using namespace std;
ll n,ans;
ll d[N],vst[N],fax[N];
vector<ll> es[N];

int main(){
	scanf("%lld",&n);
	for(ll i=1,x,y;i<=n-1;i++){
		scanf("%lld%lld",&x,&y);
		es[x].push_back(y);
		es[y].push_back(x);
		d[x]++,d[y]++;
	}
	//for(ll i=1;i<=n;i++) cout<<d[i]<<' ';
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
