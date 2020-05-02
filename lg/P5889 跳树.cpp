#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=5e5+5;
ll n,m,q,sz;
struct opx{
	ll hst,l,pth;
	opx operator + (const opx &b) const{
		if(!hst&&!l) return b;
		if(!b.hst&&!b.l) return *this;
		opx rt;
		
		if(b.hst>l){
			rt.hst=hst+b.hst-l;
			rt.l=b.l;
			rt.pth=b.pth;
		}else{
			rt.hst=hst;
			rt.l=l-b.hst+b.l;
			rt.pth=((pth>>b.hst)<<b.l)+b.pth;
		}
		return rt;
	}
}ops[M],tpl[5]={(opx){0,0,0},(opx){0,1,0},(opx){0,1,1},(opx){1,0,0}};

struct node{
	ll l,r;
	opx val;
}tr[M*4]; 


void buildtr(ll &rt,ll l,ll r){
	rt=++sz;
	if(l==r) tr[rt].val=ops[l];
	else{
		ll mid=l+r>>1;
		buildtr(tr[rt].l,l,mid);
		buildtr(tr[rt].r,mid+1,r);
		tr[rt].val=tr[tr[rt].l].val+tr[tr[rt].r].val;
	}
}
void upd(ll rt,ll l,ll r,ll x,opx val){
	if(l==r) tr[rt].val=val;
	else{
		ll mid=l+r>>1;
		if(x<=mid) upd(tr[rt].l,l,mid,x,val);
		else upd(tr[rt].r,mid+1,r,x,val);
		tr[rt].val=tr[tr[rt].l].val+tr[tr[rt].r].val;
	}
}
opx query(ll rt,ll l,ll r,ll lq,ll rq){
	if(lq<=l&&rq>=r) return tr[rt].val;
	if(lq>r||rq<l) return tpl[0];
	ll mid=l+r>>1;
	return query(tr[rt].l,l,mid,lq,rq)+query(tr[rt].r,mid+1,r,lq,rq);
}


int main(){
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1,tp;i<=m;i++){
		scanf("%lld",&tp);
		ops[i]=tpl[tp];
	}
	buildtr(tr[0].l,1,m);
	for(ll i=1,tp,s,l,r,x,val;i<=q;i++){
		scanf("%lld",&tp);
		if(tp==1){
			scanf("%lld%lld%lld",&s,&l,&r);
			opx tmp=query(1,1,m,l,r);
			s=(max(1ll,s>>tmp.hst)<<tmp.l)+tmp.pth;
			printf("%lld\n",s);
		}else{
			scanf("%lld%lld",&x,&val);
			upd(1,1,m,x,tpl[val]);
		}
	}
	return 0;
}

