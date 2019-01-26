#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
struct query{
	ll l,r,id,pos;
}q[N];
bool cmp(const query &a,const query &b){
	return a.pos<b.pos||a.pos==b.pos&&a.r>b.r;
}
ll n,m,k,a[N];
ll cnt[105],ans[N],sz;
int main(){
	scanf("%lld %lld %lld",&n,&m,&k);
	sz=(ll)sqrt(n);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld",&q[i].l,&q[i].r);
		q[i].id=i;
		q[i].pos=(q[i].l-1)/sz+1;
	}
	sort(q+1,q+m+1,cmp);
	for(ll i=1,l=0,r=0,mx=0;i<=m;i++){
		mx=0;
		while(l>q[i].l) ++cnt[a[--l]];
		while(r<q[i].r) ++cnt[a[++r]];
		while(l<q[i].l) --cnt[a[l++]];
		while(r>q[i].r) --cnt[a[r--]];
		for(ll j=1;j<=k;j++)
			if(cnt[j]>cnt[mx]) mx=j;
		ans[q[i].id]=mx;
	}
	for(ll i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}
