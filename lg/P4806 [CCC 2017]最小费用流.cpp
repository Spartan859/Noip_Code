#include<bits/stdc++.h>
#define N 100005
#define M 500005
#define ll long long
using namespace std;
ll n,m,D;
ll rt[N];
ll ansjh[N];
struct essz{
	ll u,v,w,id;
}es[M];
bool cmp(const essz &a,const essz &b){
	return a.w<b.w;
}
ll find_rt(ll x){
	//cout<<x<<endl;
	return rt[x]==x?x:rt[x]=find_rt(rt[x]);
}

void input(){
	scanf("%lld%lld%lld",&n,&m,&D);
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&es[i].u,&es[i].v,&es[i].w);
		es[i].id=i;
	}	
}
void solve(){
	for(ll i=1;i<=n;i++) rt[i]=i;
	if(D==0){
		sort(es+1,es+m+1,cmp);
		ll ans=0,cnt=0;
		for(ll i=1;i<=m;i++){
			ll fu=find_rt(es[i].u),fv=find_rt(es[i].v);
			if(fu!=fv)
				rt[fu]=fv,ans+=(es[i].id>n-1),cnt++;
			if(cnt==n-1) break;
		}
		printf("%lld\n",ans);
	}
	//cout<<0<<endl;
}
int main(){
	input();
	solve();
	return 0;
}

