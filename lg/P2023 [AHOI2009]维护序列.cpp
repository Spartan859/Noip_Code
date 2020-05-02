#include<bits/stdc++.h>
#define lson(x) x<<1
#define rson(x) x<<1|1
#define N 100005
#define ll long long
using namespace std;
ll n,p,ai,m,tx,gx,cx;
inline ll read(){
	ll res=0,fs=1;
	char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
struct node{
	ll sum,lza,lzm;
	node(){
		sum=0;
		lza=0;
		lzm=1;
	}
}tr[N*4];
inline void pushdown(ll rt,ll l,ll r){
	ll mid=l+r>>1;
	tr[lson(rt)].sum=(tr[lson(rt)].sum*tr[rt].lzm%p+tr[rt].lza*(mid-l+1))%p;
	tr[lson(rt)].lza=(tr[lson(rt)].lza*tr[rt].lzm%p+tr[rt].lza)%p;
	tr[lson(rt)].lzm=tr[lson(rt)].lzm*tr[rt].lzm%p;
	tr[rson(rt)].sum=(tr[rson(rt)].sum*tr[rt].lzm%p+tr[rt].lza*(r-mid))%p;
	tr[rson(rt)].lza=(tr[rson(rt)].lza*tr[rt].lzm%p+tr[rt].lza)%p;
	tr[rson(rt)].lzm=tr[rson(rt)].lzm*tr[rt].lzm%p;
	tr[rt].lza=0;tr[rt].lzm=1;
}
void update_add(ll rt,ll l,ll r,ll L,ll R,ll val,ll tp){
	if(l>R||r<L) return;
	if(l>=L&&r<=R){
		if(tp){
			tr[rt].lza=(tr[rt].lza+val)%p;
			tr[rt].sum=(tr[rt].sum+(r-l+1)*val)%p;
		}else{
			tr[rt].lza=tr[rt].lza*val%p;
			tr[rt].lzm=tr[rt].lzm*val%p;
			tr[rt].sum=tr[rt].sum*val%p;
		}
		return;
	}
	ll mid=l+r>>1;
	pushdown(rt,l,r);
	update_add(lson(rt),l,mid,L,R,val,tp);
	update_add(rson(rt),mid+1,r,L,R,val,tp);
	tr[rt].sum=(tr[lson(rt)].sum+tr[rson(rt)].sum)%p;
}
ll query(ll rt,ll l,ll r,ll L,ll R){
	if(l>R||r<L) return 0;
	if(l>=L&&r<=R) return tr[rt].sum;
	pushdown(rt,l,r);
	ll mid=l+r>>1;
	ll ans=(query(lson(rt),l,mid,L,R)+query(rson(rt),mid+1,r,L,R))%p;
	tr[rt].sum=(tr[lson(rt)].sum+tr[rson(rt)].sum)%p;
	return ans;
}
int main(){
	n=read();p=read();
	for(ll i=1;i<=n;i++){
		//cout<<1<<endl;
		ai=read();
		update_add(1,1,n,i,i,ai,1);
	}
	m=read();
	for(ll i=1,tp;i<=m;i++){
		tp=read();
		if(tp==1){
			tx=read();gx=read();cx=read();
			update_add(1,1,n,tx,gx,cx,0);
		}else if(tp==2){
			tx=read();gx=read();cx=read();
			update_add(1,1,n,tx,gx,cx,1);
		}else{
			tx=read();gx=read();
			printf("%lld\n",query(1,1,n,tx,gx));
		}
	}
	return 0;
} 
