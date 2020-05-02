#include<bits/stdc++.h>
#define N 5005
#define ll long long
using namespace std;
ll n;
ll a[N],b[N],cnt1,cnt2;
ll fa[N],dep[N];
vector<ll> es[N];
ll ansx[N];
void dfs(ll x,ll f){
	fa[x]=f;
	dep[x]=dep[f]+1;
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(y==f) continue;
		dfs(y,x);
	}
}
bool isfax(ll a,ll b){//判断是否会平局
	if(dep[a]<dep[b]) swap(a,b);
	ll tmp=a;
	for(ll i=1;i<=dep[tmp]-dep[b];i++) a=fa[a];
	if(a==b) return 1;
	return 0;
}
int main(){
	//freopen("match.in","r",stdin);
	//freopen("match.out","w",stdout);
	scanf("%lld",&n);
	ll m=n/2;
	getchar();
	for(ll i=1;i<=n;i++){
		char c=getchar();
		if(c=='0') a[++cnt1]=i;
		else b[++cnt2]=i;
	}
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u);
	}
	dfs(1,0);//dep,fa
	do{
		ll tmpx=0;
		for(ll i=1;i<=m;i++) if(isfax(a[i],b[i])==1) ++tmpx;
		++ansx[tmpx];
	}while(next_permutation(b+1,b+m+1));
	
	for(ll i=0;i<=m;i++) printf("%lld\n",ansx[i]);
	
	return 0;
}

