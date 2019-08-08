#include<bits/stdc++.h>
#define N 7005
#define ll long long
using namespace std;
ll n,m,cnt=1;
ll id[N];
ll f[N][N];
ll ans;
vector<ll> tr[N];//以i为根的树中的所有节点 

ll findfa(ll x){
	return x==id[x]?x:id[x]=findfa(id[x]);
}

void unitefa(ll x,ll y,ll c){
	ll fx=findfa(x),fy=findfa(y);
	if(fx==fy) return;
	for(ll i=0;i<tr[fx].size();i++)
		for(ll j=0;j<tr[fy].size();j++){
			ll u=tr[fx][i],v=tr[fy][j];
			f[u][v]=f[v][u]=c;
		}
	id[fx]=fy;
	for(ll i=0;i<tr[fx].size();i++){//合并点集 
		ll u=tr[fx][i];
		tr[fy].push_back(u);
	}
	tr[fx].clear(); 
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) id[i]=i,tr[i].push_back(i);
	for(ll i=1,t,u,v;i<=m;i++){
		scanf("%lld%lld%lld",&t,&u,&v);
		u^=ans;
		v^=ans;
		if(t==0){
			unitefa(u,v,cnt);
			//cout<<cnt<<endl;
			cnt++;
		}
		else{
			ans=f[u][v];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
