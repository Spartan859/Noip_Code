#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n,m,ans,bst=N,g[N],h[N][2];
vector<ll> es[N];
void dfs(ll x,ll fa){
	for(ll i=0,y;i<es[x].size();i++){
		y=es[x][i];
		if(y!=fa){
			dfs(y,x);
			if(h[y][0]+1>h[x][1]) h[x][1]=h[y][0]+1;
			if(h[x][1]>h[x][0]) swap(h[x][1],h[x][0]);
		}
	}
}
void dfs_up(ll x,ll fa){
	for(ll i=0,y,tmp;i<es[x].size();i++){
		y=es[x][i];
		if(y!=fa){
			tmp=(h[y][0]+1==h[x][0]);
			g[y]=max(g[x],h[x][tmp])+1;
			dfs_up(y,x);
		}
	}
}
int main(){
	scanf("%lld",&n);
	for(ll i=1,x,y;i<=n-1;i++){
		scanf("%lld %lld",&x,&y);
		es[x].push_back(y);
		es[y].push_back(x);
	}
	dfs(1,0);
	dfs_up(1,0);
	for(ll i=1;i<=n;i++){
		cout<<max(g[i],h[i][0])<<endl;
	}
	return 0;
}
