#include<cstdio>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define ll long long
#define N 200005
#define lson(x) ((x)<<1)
#define rson(x) (((x)<<1)^1)
#define fo(x,l,r) for(ll x=l;x<=r;x++)
#define pll(x) printf("%lld\n",(x))
using namespace std;
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
ll n,q;
ll a[N];
struct node{
	ll sum,min,max,lz;
}tr[N*4];
inline void pushup(ll rt){
	tr[rt].max=max(tr[lson(rt)].max,tr[rson(rt)].max);
	tr[rt].min=min(tr[lson(rt)].min,tr[rson(rt)].min);
	tr[rt].sum=tr[lson(rt)].sum+tr[rson(rt)].sum;
}
inline void Add(ll rt,ll l,ll r,ll v){
	tr[rt].min+=v;
	tr[rt].max+=v;
	tr[rt].sum+=v*(r-l+1);
	tr[rt].lz+=v;
}
inline void pushdown(ll rt,ll l,ll r){
	if(tr[rt].lz==0) return;
	ll mid=l+r>>1;
	Add(lson(rt),l,mid,tr[rt].lz);
	Add(rson(rt),mid+1,r,tr[rt].lz);
	tr[rt].lz=0;
}
void build(ll rt,ll l,ll r){
	if(l==r){
		tr[rt].max=tr[rt].min=tr[rt].sum=a[l];
		return;
	}
	ll mid=l+r>>1;
	build(lson(rt),l,mid);
	build(rson(rt),mid+1,r);
	pushup(rt);
}
void update(ll rt,ll l,ll r,ll L,ll R,ll val){
	if(l>R||r<L) return;
	if(l>=L&&r<=R){
		Add(rt,l,r,val);
		return;
	} 
	ll mid=l+r>>1;
	pushdown(rt,l,r);
	update(lson(rt),l,mid,L,R,val);
	update(rson(rt),mid+1,r,L,R,val);
	pushup(rt);
}
ll query_sum(ll rt,ll l,ll r,ll L,ll R){
	//cout<<l<<' '<<r<<' '<<L<<' '<<R<<endl;
	if(l>R||r<L) return 0;
	//cout<<1<<endl;
	if(l>=L&&r<=R){
		//cout<<tr[rt].sum<<endl;
		return tr[rt].sum;
	} 
	//cout<<1<<endl;
	ll mid=l+r>>1;
	pushdown(rt,l,r);
	return query_sum(lson(rt),l,mid,L,R)+query_sum(rson(rt),mid+1,r,L,R);
}
int main(){
	n=read();q=read();
	fo(i,1,n) a[i]=read();
	build(1,1,n);
	ll a,b,c;
	fo(i,1,q){
		char c='X';
		while(c!='C'&&c!='Q') c=getchar();
		if(c=='C'){
			a=read();
			b=read();
			c=read();
			update(1,1,n,a,b,c);
		}else{
			a=read();
			b=read();
			pll(query_sum(1,1,n,a,b));
		}
	}
	return 0;
}
