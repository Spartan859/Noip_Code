#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
ll n,m,u,v,ed[N][N],ind[N],sel,cnt,vst[N];
vector<ll> es[N];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=m;i++){ 
		scanf("%lld %lld",&u,&v);
		if(ed[v][u]==1) continue;
		ed[v][u]=1;
		es[v].push_back(u);
		ind[u]++;
	}
	while(cnt<n){
		for(ll i=1;i<=n;i++) if(!ind[i]&&!vst[i]){
			sel=i;
			vst[sel]=1;
			break;
		}
		for(ll i=0;i<es[sel].size();i++) ind[es[sel][i]]--;
		cout<<sel<<' ';
		cnt++;
	}
	return 0;
}
