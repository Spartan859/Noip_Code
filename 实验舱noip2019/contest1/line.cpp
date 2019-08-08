#include<bits/stdc++.h>
#define N 5005
#define ll long long
using namespace std;
ll n,H,r,a,b;
ll cf[N],sum[N];
struct qj{
	ll l,r;
}qjx[10005];
bool cmp(const qj &a,const qj &b){
	return a.l<b.l||a.l==b.l&&a.r<b.r;
}
bool eq(qj a,qj b){
	return a.l==b.l&&a.r==b.r;
}
int main(){
	scanf("%lld%lld%lld",&n,&H,&r);
	for(ll i=1;i<=r;i++){
		scanf("%lld%lld",&a,&b);
		qjx[i].l=a;
		qjx[i].r=b;
	}
	//ШЅжи
	sort(qjx+1,qjx+r+1,cmp);
	for(ll i=1;i<=r;i++){
		ll j=1;
		while(eq(qjx[i],qjx[i+j])) qjx[i+j].l=1,qjx[i+j].r=2,j++;
	}
	for(ll i=1;i<=r;i++){
		ll ax=qjx[i].l,bx=qjx[i].r;
		//cout<<ax<<' '<<bx<<endl;
		if(ax>bx) swap(ax,bx);
		ax++,bx--;
		if(ax>bx) continue;
		cf[ax]++;cf[bx+1]--;
	}
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+cf[i];
	for(ll i=1;i<=n;i++) printf("%lld\n",H-sum[i]);
	return 0;
}
