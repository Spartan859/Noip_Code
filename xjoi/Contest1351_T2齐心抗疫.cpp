#include<bits/stdc++.h>
#define N 50005
#define ll long long
#define llabs(x) ((x)>0?(x):(-(x)))
using namespace std;
ll n,ans;
ll a[N],dep[N],PMAX,QMAX,dep2[N];
vector<ll> es[N];
void dfs(ll x,ll fa){//拉树：depth,PMAX 
	dep[x]=dep[fa]+1;
	for(ll i=0;i<es[x].size();i++) if(es[x][i]!=fa) dfs(es[x][i],x);
}
void dfs2(ll x,ll fa){//拉树：depth,PMAX 
	//cout<<x<<endl;
	dep2[x]=dep2[fa]+1;
	for(ll i=0;i<es[x].size();i++)
		if(es[x][i]!=fa)
			dfs2(es[x][i],x);
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u);
	}
		 
	dfs(1,0);
	PMAX=max_element(dep+1,dep+n+1)-dep;
	dfs2(PMAX,0);//求直径的两端点 
	QMAX=max_element(dep2+1,dep2+n+1)-dep2;
	//cout<<PMAX<<' '<<QMAX<<endl;
	dfs(QMAX,0);//让两端点都当上根 
	//cout<<a[6]*dep[6]<<endl;
	for(ll i=1;i<=n;i++){
		ans=max(ans,max(a[i]*(dep[i]-1),a[i]*(dep2[i]-1)));
	} 
	printf("%lld\n",ans);
	return 0;
}
/*
8 
3 1 4 1 5 9 2 6
1 2
2 3 
2 4 
1 5 
5 6 
4 8 
3 7

*/


