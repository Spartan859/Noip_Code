#include<bits/stdc++.h>
#define H 20
#define M 100005
#define ll long long
using namespace std;
ll n,m,id[H][M],vst[M],ans=-1;
const ll MOD=1e9+7;
ll findfa(ll h,ll x){
	return id[h][x]==x?x:id[h][x]=findfa(h,id[h][x]);
}
void unite(ll x,ll y,ll h){
	ll fx=findfa(h,x),fy=findfa(h,y);
	if(fx==fy) return;
	id[h][fx]=fy;
	if(!h) return;
	h--;
	unite(x,y,h);
	unite(x+(1<<h),y+(1<<h),h);
}
ll quick_pw(ll x,ll p,ll m){
	ll res=1;
	while(p>0){
		if(p&1)res=res*x%m;
		p>>=1;
		x=x*x%m;
	}
	return res;
}

int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++)
		for(ll j=0;i+(1<<j)-1<=n;j++) id[j][i]=i;
	for(ll l1,r1,l2,r2,i=1;i<=m;i++){
		scanf("%lld %lld %lld %lld",&l1,&r1,&l2,&r2);
		ll t=log2(r1-l1+1);
		unite(l1,l2,t);
		unite(r1-(1<<t)+1,r2-(1<<t)+1,t);
	}
	for(ll i=1;i<=n;i++)
		if(!vst[findfa(0,i)]) vst[findfa(0,i)]=1,ans++;
	printf("%lld\n",quick_pw(10,ans,MOD)*9%MOD);
	return 0;
} 
