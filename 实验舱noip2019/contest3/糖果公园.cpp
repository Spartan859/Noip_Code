#include<bits/stdc++.h>
#define N 2005
#define ll long long
using namespace std;
ll n,m,cnt;
ll id[N];
ll f[N][N];
vector<ll> son[N];
ll ans;

ll findfa(ll x){
	if(x==id[x]){
		son[x].push_back(x);
		return x;
	} 
	else{
		id[x]=findfa(id[x]);
		son[id[x]].push_back(x);
		return id[x];
	}
}

void unitefa(ll x,ll y,ll c){
	ll fx=findfa(x),fy=findfa(y);
	if(fx==fy) return;
	for(ll i=0;i<son[fx].size();i++)
		for(ll j=0;j<son[fy].size();j++) f[son[fx][i]][son[fy][j]]=f[son[fy][j]][son[fx][i]]=c;
	id[fy]=fx;
	for(ll j=0;j<son[fy].size();j++) findfa(son[fy][j]);
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) id[i]=i;
	for(ll i=1,t,u,v;i<=m;i++){
		scanf("%lld%lld%lld",&t,&u,&v);
		u^=ans;
		v^=ans;
		//cout<<u<<' '<<v<<endl;
		if(t==0){
			unitefa(u,v,cnt);
			cnt++;
		}
		else{
			//cout<<findfa(u)<<' '<<findfa(v)<<endl;
			ans=f[u][v];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
