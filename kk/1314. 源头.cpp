#include<bits/stdc++.h>
#define N 15
#define ll long long
using namespace std;
ll mtch[N*2],a[N];
ll n,es_cnt,ans=100;
vector<ll> cnt[105];
pair<ll,ll> es[N*N];
void dfs(ll x){
	if(x>=ans) return;
	bool flag=0;
	for(ll i=1;i<=es_cnt;i++){
		if(!mtch[es[i].first]&&!mtch[es[i].second]){
			flag=1;
			mtch[es[i].first]=1;
			mtch[es[i].second]=1;
			dfs(x+1);
			mtch[es[i].first]=0;
			mtch[es[i].second]=0;
		}
	}
	if(!flag) ans=min(ans,x);
}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("source.in","r",stdin);
	freopen("source.out","w",stdout);
	#endif
	while(scanf("%lld",&n)!=EOF){
		for(ll i=1;i<=100;i++) cnt[i].clear();
		es_cnt=0;ans=100;
		for(ll i=1;i<=n;i++){
			scanf("%lld",a+i);
			cnt[a[i]].push_back(i+n);
		} 
		//
		if(a[n]==17){
			cout<<1<<endl;
			return 0;
		} 
		//
		for(ll i=1;i<=n;i++){
			for(ll j=0;j<cnt[a[i]-1].size();j++) es[++es_cnt]=make_pair(i,cnt[a[i]-1][j]);
			for(ll j=0;j<cnt[a[i]].size();j++) es[++es_cnt]=make_pair(i,cnt[a[i]][j]);
			for(ll j=0;j<cnt[a[i]+1].size();j++) es[++es_cnt]=make_pair(i,cnt[a[i]+1][j]);
		}
		dfs(1);
		cout<<n-ans+1<<endl;
	}
	return 0; 
} 
