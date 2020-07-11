#include<bits/stdc++.h>
#define ll long long
#define lz(x) tr[x].lz
#define mx(x) tr[x].MAX
#define l(x) tr[x].l
#define r(x) tr[x].r
using namespace std;
const ll N=1e4+5;
struct nd{
	ll l,r;
	ll MAX;
	ll lz; 
}tr[N*32];
inline void spread(ll x){//lazytag pushdown
	if(lz(x)){
		mx(x*2)+=lz(x);
		mx(x*2+1)+=lz(x);
		lz(x*2)+=lz(x);
		lz(x*2+1)+=lz(x);
		lz(x)=0;
	}
}
inline void pushup(ll x){
	mx(x)=max(mx(x*2),mx(x*2+1));
}
void build(ll rt,ll l,ll r){
	tr[rt].l=l;tr[rt].r=r;
	tr[rt].MAX=0;tr[rt].lz=0;
	if(l==r) return; 
	ll mid=l+r>>1;
	build(rt*2,l,mid);build(rt*2+1,mid+1,r);
}
void upd(ll rt,ll L,ll R,ll add){
	//cout<<L<<' '<<R<<endl;
	if(L<=l(rt)&&R>=r(rt)){
		mx(rt)+=add;
		lz(rt)+=add;
		return;
	}
	spread(rt);
	ll mid=(l(rt)+r(rt))>>1;
	if(L<=mid) upd(rt*2,L,R,add);
	if(R>mid) upd(rt*2+1,L,R,add);
	pushup(rt);
}
ll ask(ll rt,ll L,ll R){
	if(L<=l(rt)&&R>=r(rt)) return mx(rt);
	spread(rt);
	ll mid=l(rt)+r(rt)>>1;
	ll ret=0;
	if(L<=mid) ret=max(ret,ask(rt*2,L,R));
	if(R>mid) ret=max(ret,ask(rt*2+1,L,R));
	return ret;
}

ll T;
ll n;
ll W,H;
ll ans=0;
struct star{
	ll x,yl,yr,l;
}a[N*2];
bool cmp(const star &a,const star &b){
	return a.x<b.x||a.x==b.x&&a.l<b.l;
}
ll lsh[N*2];
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		scanf("%lld%lld",&W,&H);
		for(ll i=1,x,y,l;i<=n;i++){
			scanf("%lld%lld%lld",&x,&y,&l);
			a[i].x=x;a[i].yl=y;a[i].yr=y+H-1;a[i].l=l;
			lsh[i]=y;lsh[i+n]=y+H-1;
		}
		sort(lsh+1,lsh+n*2+1);ll nl=unique(lsh+1,lsh+n*2+1)-lsh-1;
		for(ll i=1;i<=n;i++){
			a[i].yl=lower_bound(lsh+1,lsh+nl+1,a[i].yl)-lsh;//ÀëÉ¢»¯ 
			a[i].yr=lower_bound(lsh+1,lsh+nl+1,a[i].yr)-lsh;
			a[i+n]=(star){a[i].x+W,a[i].yl,a[i].yr,-a[i].l};
		}
		sort(a+1,a+n*2+1,cmp);
		build(1,1,nl);
		//cout<<"nl: "<<<<endl;
		for(ll i=1;i<=n*2;i++){
			star c=a[i];
			upd(1,c.yl,c.yr,c.l);//¸üÐÂ 
			/*cout<<"sg: "<<' ';
			for(ll j=1;j<=7;j++) 
				cout<<ask(1,j,j)<<' ';
			cout<<endl;*/
			ans=max(ans,mx(1));
		}
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}
/*
2
3 5 4

1 2 3
2 3 2
6 3 1


3 5 4

1 2 3
2 3 2
5 3 1
*/
