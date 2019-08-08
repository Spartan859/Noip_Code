#include<bits/stdc++.h>
#define N 1000005
#define INF 2e18
#define ll long long
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;
ll n,k,m;
ll a[N],to[N];
ll twc[65];
ll ansx[N];
ll f[N][61];
//vector<ll> tmp;

inline ll absfrll(ll x){
	if(x>0) return x;
	else return -x;
}

int main(){
	scanf("%lld%lld%lld",&n,&k,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	for(ll l=1,i=1,r=k+1;i<=n;to[i]=a[i]-a[l]>=a[r]-a[i]?l:r,i++)
		while(r<n&&a[i]-a[l]>a[r+1]-a[i]) l++,r++;
	
	//for(ll i=1;i<=n;i++) cout<<to[i]<<' ';
	//cout<<endl;
	for(ll i=1;i<=n;i++) f[i][0]=to[i];
	for(ll t=1;t<=60;t++)
		for(ll i=1;i<=n;i++) f[i][t]=f[f[i][t-1]][t-1];
		
	twc[0]=1;
	for(ll i=1;i<=60;i++)
		twc[i]=twc[i-1]+twc[i-1];
	for(ll i=1;i<=n;i++) ansx[i]=i;
	ll mc=m;
	for(ll t=60;t>=0;t--){
		if(twc[t]<=mc){
			mc-=twc[t];
			for(ll i=1;i<=n;i++) ansx[i]=f[ansx[i]][t];
			if(!mc) break; 
		}
	}
	for(ll i=1;i<=n;i++) printf("%lld ",ansx[i]);
	return 0;
}
