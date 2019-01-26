#include<bits/stdc++.h>
#define ll long long
#define INF 2e18
using namespace std;
ll m,p;
ll ans[200005],cnt,n,t,cnt2;
char ch;
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
	st[x].sum=max(st[x].sum,ad);
	if(st[x].l==st[x].r) return;
	
	if(l<=st[x*2].r) add_sg(x*2,l,ad);
	else add_sg(x*2+1,l,ad);
}
ll query(ll x,ll l,ll r){
	if(l>st[x].r||r<st[x].l) return 0;
	if(st[x].l>=l&&st[x].r<=r) return st[x].sum;
	return max(query(x*2,l,r),query(x*2+1,l,r));
}
int main(){
	scanf("%lld %lld",&m,&p);
	build_st(1,1,200000);
	for(ll i=1;i<=m;i++){
		cin>>ch>>n;
		if(ch=='A'){
			cnt2++;
			add_sg(1,cnt2,(n+t)%p);
		}
		if(ch=='Q') t=ans[cnt++]=query(1,cnt2-n+1,cnt2);
	}
	for(ll i=0;i<cnt;i++) cout<<ans[i]<<endl;
	return 0;
}
