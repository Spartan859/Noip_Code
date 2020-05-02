#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll n,a[N],m,rtx[N];//rtx:第i次操作后的版本rt 
ll sz;
struct node{
	ll l,r,val;
}tr[N*32];
ll build(ll l,ll r){
	ll rt=++sz;
	if(l==r) tr[rt].val=a[l];
	else{
		ll mid=l+r>>1;
		tr[rt].l=build(l,mid);
		tr[rt].r=build(mid+1,r);
	}
	return rt;
}
ll update(ll bf,ll l,ll r,ll x,ll val){//修改x位置to val 
	ll rt=++sz;
	tr[rt]=tr[bf];
	if(l==r) tr[rt].val=val;
	else{
		ll mid=l+r>>1;
		if(x<=mid) tr[rt].l=update(tr[rt].l,l,mid,x,val);
		else tr[rt].r=update(tr[rt].r,mid+1,r,x,val);
	}
	return rt;
}
ll query(ll rt,ll l,ll r,ll x){
	if(l==r) return tr[rt].val;
	ll mid=l+r>>1;
	if(x<=mid) return query(tr[rt].l,l,mid,x);
	return query(tr[rt].r,mid+1,r,x); 
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	rtx[0]=build(1,n);
	//change & query
	for(ll i=1,bb,tp,loc,val;i<=m;i++){
		scanf("%lld%lld",&bb,&tp);
		if(tp==1){
			scanf("%lld%lld",&loc,&val);
			rtx[i]=update(rtx[bb],1,n,loc,val);
		}else{
			scanf("%lld",&loc);
			rtx[i]=rtx[bb];
			printf("%lld\n",query(rtx[bb],1,n,loc));
		}
	}
	return 0;
}

