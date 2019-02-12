#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
ll n,m,ans;
struct lne{ll x,y1,y2,k;}a[N<<1];
struct seg{ll l,r,cnt,len;}tr[N<<3];//线段树--cnt表示厚度，len表示总被覆盖长度
ll raw[N<<1];//存储原值 
bool cmp(const lne &a,const lne &b){
	return a.x<b.x;
}
ll val_fnd(ll x){
	ll l=1,r=m,mid;
	while(l<=r){
		mid=l+((r-l)>>1);
		if(x>raw[mid]) l=mid+1;
		else if(x<raw[mid]) r=mid-1;
		else return mid;
	}
}
void build(ll p,ll l,ll r){//建树 
	tr[p].l=l; tr[p].r=r; tr[p].cnt=tr[p].len=0;
	if(l==r) return;
	ll mid=l+((r-l)>>1);
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
void update(ll p,ll l,ll r,ll k){//c[l-r]+=k 
	if(l<=tr[p].l&&r>=tr[p].r){
		tr[p].cnt+=k;
		if(tr[p].cnt) tr[p].len=raw[tr[p].r+1]-raw[tr[p].l];
		else if(tr[p].l==tr[p].r) tr[p].len=0;
		else tr[p].len=tr[p<<1].len+tr[p<<1|1].len;
		return;
	}//更新覆盖长度,直接更新为raw(tr[p].r+1)-raw(tr[p].l)(原值)
	if(tr[p].l==tr[p].r) return;
	ll mid=tr[p].l+((tr[p].r-tr[p].l)>>1);
	if(l<=mid) update(p<<1,l,r,k);
	if(r>mid) update(p<<1|1,l,r,k);
	tr[p].len=(tr[p].cnt?raw[tr[p].r+1]-raw[tr[p].l]:tr[p<<1].len+tr[p<<1|1].len);//更新覆盖长度，如果被全覆盖，则更新为左子树+右子树，否则直接更新为raw(tr[p].r+1)-raw(tr[p].l) 
}
int main(){
	//freopen("reward5.in","r",stdin);
	//freopen("reward5.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1,y,z,k;i<=n;i++){
		k=i<<1;
		scanf("%lld %lld %lld %lld",&a[k-1].x,&y,&a[k].x,&z);
		if(a[k-1].x>a[k].x) swap(a[k-1].x,a[k].x);
		if(y>z) swap(y,z);
		raw[k-1]=a[k-1].y1=a[k].y1=y;
		raw[k]=a[k-1].y2=a[k].y2=z;
		a[k-1].k=-1;
		a[k].k=1;
	}
	n<<=1;
	sort(raw+1,raw+n+1);
	m=unique(raw+1,raw+n+1)-raw-1;
	sort(a+1,a+n+1,cmp);
	build(1,1,m-1);
	for(ll i=1,y,z;i<n;i++){
		y=val_fnd(a[i].y1);z=val_fnd(a[i].y2)-1;//还原
		update(1,y,z,a[i].k);//添加/删除线段 
		ans+=tr[1].len*(a[i+1].x-a[i].x);//加上宽度*总被覆盖长度
	}
	cout<<ans<<endl;
	return 0; 
}
