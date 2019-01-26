#include<bits/stdc++.h>
#define ll long long
#define INF 2e18
#define P 100000007
using namespace std;
ll n,m,t,x,y;
ll ans[200005],cnt;
struct node{
	ll l,r,sum,toadd;
}st[800005];
void build_st(ll x,ll lx,ll rx){
	st[x].l=lx;st[x].r=rx;
	st[x].sum=0;
	if(lx==rx) return;
	ll mid=(lx+rx)>>1;
	build_st(x*2,lx,mid);
	build_st(x*2+1,mid+1,rx);
}
void add_sg(ll x,ll l,ll ad){
	st[x].sum+=ad; st[x].sum=(st[x].sum+P)%P;
	if(st[x].l==st[x].r) return;
	
	if(l<=st[x*2].r) add_sg(x*2,l,ad);
	else add_sg(x*2+1,l,ad);
}
ll query(ll x,ll l,ll r){
	if(l>st[x].r||r<st[x].l) return 0;
	if(st[x].l>=l&&st[x].r<=r) return st[x].sum;
	return query(x*2,l,r)+query(x*2+1,l,r);
}
int main(){
	scanf("%lld %lld",&n,&m);
	build_st(1,1,n);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld %lld",&t,&x,&y);
		if(t==2) add_sg(1,x,y);
		else ans[cnt++]=(query(1,x,y)+P)%P;
	}
	for(ll i=0;i<cnt;i++) cout<<ans[i]<<endl;
	return 0;
}
