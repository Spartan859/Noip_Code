#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
ll n,m,l,r,k,t,ans[N],cnt,P,a[N];
struct node{
	ll l,r,sum,toadd,tomul;
}st[N*4];
inline ll len(ll x){
	return st[x].r-st[x].l+1;
}
inline void mp(ll x){st[x].sum%=P;st[x].toadd%=P;st[x].tomul%=P;}
void build_tree(ll l,ll r,ll x){//x==root
	if(l==r){
		st[x]=(node){l,r,a[l],0,1};
		mp(x);
		return;
	}
	ll mid=l+(r-l)/2;
	build_tree(l,mid,x*2);
	build_tree(mid+1,r,x*2+1);
	st[x]=(node){l,r,st[x*2].sum+st[x*2+1].sum,0,1};
	mp(x);
}
void pushdown(ll x){
	st[x*2].tomul*=st[x].tomul;
	st[x*2].toadd=st[x*2].toadd*st[x].tomul+st[x].toadd;
	st[x*2].sum=st[x*2].sum*st[x].tomul+st[x].toadd*len(x*2);//st[x*2].sum+=st[x*2].toadd;
	mp(x*2);
	st[x*2+1].tomul*=st[x].tomul;
	st[x*2+1].toadd=st[x*2+1].toadd*st[x].tomul+st[x].toadd;
	st[x*2+1].sum=st[x*2+1].sum*st[x].tomul+st[x].toadd*len(x*2+1);
	mp(x*2+1);
	st[x].toadd=0;
	st[x].tomul=1;
}
ll query(ll l,ll r,ll x){//max,min,sum,etc.
	if(r<st[x].l||l>st[x].r) return 0;
	if(r>=st[x].r&&l<=st[x].l) return st[x].sum;
	pushdown(x);
	return (query(l,r,x*2)+query(l,r,x*2+1))%P;
}
void addK(ll l,ll r,ll x,ll k,ll tp){
	if(r<st[x].l||l>st[x].r) return;
	if(r>=st[x].r&&l<=st[x].l){
		if(tp==1){
			st[x].toadd*=k;
			st[x].tomul*=k;
			st[x].sum*=k;
		}else{
			st[x].toadd+=k;
			st[x].sum+=k*len(x);	
		}
		mp(x);
		return;
	}
	pushdown(x);
	addK(l,r,x*2,k,tp);
	addK(l,r,x*2+1,k,tp);
	st[x].sum=st[x*2].sum+st[x*2+1].sum;st[x].sum%=P;
}
int main(){
	scanf("%lld %lld %lld",&n,&m,&P);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	build_tree(1,n,1);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld %lld",&t,&l,&r);
		if(t!=3) scanf("%lld",&k);
		if(t==1) addK(l,r,1,k,1);
		if(t==2) addK(l,r,1,k,2);
		if(t==3) ans[cnt++]=(query(l,r,1)+P)%P;
	}
	for(ll i=0;i<cnt;i++) cout<<ans[i]<<endl;
	return 0;
}
