#include<bits/stdc++.h>
#define N 20
#define ll long long
using namespace std;
ll n,ans;
ll d[N],vst[N],fax[N];
vector<ll> es[N];
void buildtr(ll x,ll fa){
	for(ll i=0,y;i<es[x].size();i++){
		y=es[x][i];
		if(y==fa) continue;
		fax[y]=x;
		buildtr(y,x);
	}
}
void dfs(ll x){
	if(x==n) ans++;
	for(ll i=2;i<=n;i++){
		if(!vst[i]&&d[i]==1){
			--d[fax[i]];vst[i]=1;
			dfs(x+1);
			++d[fax[i]];vst[i]=0;
		}
	}
}
int main(){
	scanf("%lld",&n);
	for(ll i=1,x,y;i<=n-1;i++){
		scanf("%lld%lld",&x,&y);
		es[x].push_back(y);
		es[y].push_back(x);
		d[x]++,d[y]++;
	}
	//for(ll i=1;i<=n;i++) cout<<d[i]<<' ';
	buildtr(1,0);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
