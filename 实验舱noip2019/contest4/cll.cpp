#include<bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
ll T,n;
vector<ll> es[N],w[N];
map<ll,ll> mp;//cntÊý×é 
ll fx[N],dpth[N],bian[N];

bool sblian=1;
ll lian[N];
ll cpy[N];


void dfs(ll x,ll fa){
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(y==fa) continue;
		fx[y]=x;
		dpth[y]=dpth[x]+1;
		bian[y]=w[x][i];
		dfs(y,x);
	}
}
int main(){
	scanf("%lld",&T);
	while(T--){
		ll ans=0;
		sblian=1;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++) es[i].clear(),w[i].clear();
		for(ll i=1,u,v,wx;i<=n-1;i++){
			scanf("%lld%lld%lld",&u,&v,&wx);
			if(v!=u+1) sblian=0;
			lian[u]=wx;
			es[u].push_back(v);
			es[v].push_back(u);
			w[u].push_back(wx);
			w[v].push_back(wx);
		}
		
		if(sblian){
			for(ll i=1;i<=n-1;i++){
				mp.clear();
				ll js=0;
				for(ll j=1;j<=i;j++){
					mp[lian[j]]++;
					if(!(mp[lian[j]]&1)) js--;
					else js++;
				}
				if(js) ans++;
				for(ll j=2;j<=n-i;j++){
					mp[lian[j-1]]--,mp[lian[j+i-1]]++;
					if(!(mp[lian[j-1]]&1)) js--;
					else js++;
					if(!(mp[lian[j+i-1]]&1)) js--;
					else js++;
					
					if(js) ans++;
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		dfs(1,0);//dpth&&fa get
		for(ll i=1;i<=n-1;i++)
			for(ll j=i+1;j<=n;j++){
				ll u=i,v=j;
				mp.clear();
				ll js=0;
				while(u!=v){
					if(dpth[u]>dpth[v]){
						mp[bian[u]]++;
						if(!(mp[bian[u]]&1)) js--;
						else js++;
						u=fx[u];
					}else{
						mp[bian[v]]++;
						if(!(mp[bian[v]]&1)) js--;
						else js++;
						v=fx[v];
					}
				}
				if(js) ans++;
			}
		printf("%lld\n",ans);	
	}
	return 0;
}
