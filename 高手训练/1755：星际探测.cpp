#include<bits/stdc++.h>
#define ll unsigned int
using namespace std;
const ll N=1e5+5,INF=2e9;
ll n,q;
ll sz;
ll jc[N];
inline void read(ll &n){
	char c;int f=1;n=0;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=-1;
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	n*=f;
}

struct inp{
	ll D,V;//dv
	bool operator < (const inp &a){
		return D<a.D;
	}
}ar[N];

void input(){
	read(n);read(q);
	for(ll i=1;i<=n;i++) read(ar[i].D);
	for(ll i=1;i<=n;i++) read(ar[i].V);
	sort(ar+1,ar+n+1);
}
struct node{
	ll l,r,len,MIN,val[10],MINPOS; 
}tr[N*4];

node push_up(node a,node b,ll l,ll r){
	node rt;
	if(a.MIN<b.MIN){
		rt.MIN=a.MIN;
		rt.MINPOS=a.MINPOS;
	}else{
		rt.MIN=b.MIN;
		rt.MINPOS=b.MINPOS;
	}
	rt.len=a.len+b.len;
	memset(rt.val,0,sizeof(rt.val));
	rt.val[0]=1;
	int tmpblen=b.len;
	for(int k=1;k<=min((ll)6,rt.len);k++)
		for(ll i=max(0,k-tmpblen);i<=k&&i<=a.len;i++)
			rt.val[k]+=a.val[i]*b.val[k-i];
			
	rt.l=l;rt.r=r;
	return rt;
}

void buildtr(ll &rt,ll l,ll r){//按离散化的新数组进行建树 
	rt=++sz;
	if(l==r){
		tr[rt].len=1;tr[rt].MIN=ar[l].V;
		tr[rt].val[0]=1;tr[rt].val[1]=ar[l].V;
		tr[rt].MINPOS=l;
		return;
	}
	ll mid=l+r>>1;
	buildtr(tr[rt].l,l,mid);
	buildtr(tr[rt].r,mid+1,r);
	tr[rt]=push_up(tr[tr[rt].l],tr[tr[rt].r],tr[rt].l,tr[rt].r);
}

node query(ll rt,ll l,ll r,ll lq,ll rq){
	if(lq<=l&&rq>=r) return tr[rt];
	if(lq>r||rq<l) return (node){0,0,0,INF,{1},INF};
	ll mid=l+r>>1;
	node lf=query(tr[rt].l,l,mid,lq,rq)
	,rf=query(tr[rt].r,mid+1,r,lq,rq);
	if(lf.MIN==INF) return rf;
	if(rf.MIN==INF) return lf;
	return push_up(lf,rf,0,0);
}

inline ll merge(node a,node b,int k){//最终求解，只算val[k] 
	ll rt=0;
	int tmpblen=b.len;
	for(ll i=max(0,k-tmpblen);i<=k&&i<=a.len;i++)
		rt+=a.val[i]*b.val[k-i];
	return rt;
}


inline ll erfenrf(ll x){//找到D<=x的末位数 
	ll l=1,r=n,mid,rt;
	while(l<=r){
		mid=l+r>>1;
		if(ar[mid].D<=x) rt=mid,l=mid+1;
		else r=mid-1;
	}
	return rt;
}
inline ll erfenlf(ll x){
	ll l=1,r=n,mid,rt;
	while(l<=r){
		mid=l+r>>1;
		if(ar[mid].D>=x) rt=mid,r=mid-1;
		else l=mid+1;
	}
	return rt;
}
void solve(){
	buildtr(tr[0].l,1,n);
	jc[1]=1;
	for(ll i=2;i<=n;i++) jc[i]=jc[i-1]*i;
	for(ll i=1,l,r,sl;i<=q;i++){
		read(l);read(r);read(sl);
		ll lq=erfenlf(l),rq=erfenrf(r);
		node rx=query(1,1,n,lq,rq);
		
		if(rx.MINPOS==lq){cout<<query(1,1,n,lq+1,rq).val[sl]*jc[sl]<<endl;continue;} 
		if(rx.MINPOS==rq){cout<<query(1,1,n,lq,rq-1).val[sl]*jc[sl]<<endl;continue;} 
		
		node ax=query(1,1,n,lq,rx.MINPOS-1)
		,bx=query(1,1,n,rx.MINPOS+1,rq);
		
		ll ans=merge(ax,bx,sl)*jc[sl];
		cout<<ans<<endl;
	}
}
int main(){
	input();
	solve();
	return 0;
}
/*
5 3
5 4 7 2 6
1 4 5 3 2
6 7 1
2 6 2
1 8 3

5
52
924
*/

