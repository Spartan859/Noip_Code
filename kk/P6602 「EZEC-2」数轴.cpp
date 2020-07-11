#include<bits/stdc++.h>
#define ll long long
#define %d %lld
using namespace std;

const ll N=1e6+5;
struct qsts{
	ll x,y;
}q[N];ll lsh[N],nwl;
//Ê÷×´Êý×é
ll bitr[N];
inline void upd(ll x,ll y){for(ll i=x;i<=nwl;i+=x&(-x)) bitr[i]+=y;}
inline ll qry(ll x){ll ans=0;for(ll i=x;i;i-=x&(-x)) ans+=bitr[i];return ans;}
// 
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(ll i=1;i<=n;i++){
		scanf("%d%d",&q[i].x,&q[i].y);
		lsh[i]=q[i].x;
	}
	sort(lsh+1,lsh+n+1);
	nwl=unique(lsh+1,lsh+n+1)-lsh-1;
	for(ll i=1;i<=n;i++) q[i].x=lower_bound(lsh+1,lsh+nwl+1,q[i].x)-lsh;
	for(ll i=1;i<=n;i++){
		upd(q[i].x,q[i].y);
	}
}

