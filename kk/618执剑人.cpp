#include<bits/stdc++.h>
#define ll long long
#define N 1005
#define P 10005
using namespace std;
vector<ll> es[N],w[N];
ll vst[N],n,p,k,ans=100005,a,b,l,lst[P],cntx,tmpx,ksj; 
void dfs(ll x){
	ksj++;
	if(ksj>=10000) return ;
	if(x==n){
		for(ll i=0;i<cntx-k;i++) tmpx=max(tmpx,lst[i]);
		ans=min(ans,tmpx);
		tmpx=0;
		return ;
	}
	vst[x]=1;
	for(ll i=0;i<es[x].size();i++){
		if(!vst[es[x][i]]) {
			lst[cntx++]=w[x][i];
			dfs(es[x][i]);
			lst[cntx--]=0;
		}
	}
	vst[x]=0;
}
int main(){
	freopen("warden.in","r",stdin);
	freopen("warden.out","w",stdout);
	scanf("%lld %lld %lld",&n,&p,&k);
	for(ll i=1;i<=p;i++) {
		scanf("%lld %lld %lld",&a,&b,&l);
		es[a].push_back(b); w[a].push_back(l);
		es[b].push_back(a); w[b].push_back(l);
	}
	dfs(1);
	ans=(ans==100005?-1:ans);
	printf("%lld\n",ans);
	return 0;
}
