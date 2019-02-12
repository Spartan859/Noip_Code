#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define P 100000007
using namespace std;
ll n,m,l,r,k,t,ans[N],cnt;
struct node{
	ll l,r,sum,toadd;
}st[N*4];
inline ll len(ll x){
	return st[x].r-st[x].l+1;
}
inline void mp(ll x){st[x].sum%=P;st[x].toadd%=P;}
void build_tree(ll l,ll r,ll x){//x==root
	if(l==r){
		st[x]=(node){l,r,0,0};
		return;
	}
	ll mid=l+(r-l)/2;
	build_tree(l,mid,x*2);
	build_tree(mid+1,r,x*2+1);
	st[x]=(node){l,r,0,0};
}
void pushdown(ll x){
	st[x*2].toadd+=st[x].toadd;
	st[x*2].sum+=st[x].toadd*len(x*2);//st[x*2].sum+=st[x*2].toadd;
	mp(x*2);
	st[x*2+1].toadd+=st[x].toadd;
	st[x*2+1].sum+=st[x].toadd*len(x*2+1);
	mp(x*2+1);
	st[x].toadd=0;
}
ll query(ll l,ll r,ll x){//max,min,sum,etc.
	if(r<st[x].l||l>st[x].r) return 0;
	if(r>=st[x].r&&l<=st[x].l) return st[x].sum;
	pushdown(x);
	return (query(l,r,x*2)+query(l,r,x*2+1))%P;
}
void addK(ll l,ll r,ll x,ll k){
	if(r<st[x].l||l>st[x].r) return;
	if(r>=st[x].r&&l<=st[x].l){
		st[x].toadd+=k;
		st[x].sum+=k*len(x);
		mp(x);
		return;
	}
	pushdown(x);
	addK(l,r,x*2,k);
	addK(l,r,x*2+1,k);
	st[x].sum=st[x*2].sum+st[x*2+1].sum;st[x].sum%=P;
}
int main(){
	scanf("%lld %lld",&n,&m);
	build_tree(1,n,1);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld %lld %lld",&t,&l,&r,&k);
		if(t==1) addK(l,r,1,k);
		else ans[cnt++]=(query(l,l,1)+P)%P;
	}
	for(ll i=0;i<cnt;i++) cout<<ans[i]<<endl;
	return 0;
}
