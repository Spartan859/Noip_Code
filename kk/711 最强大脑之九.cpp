#include<bits/stdc++.h>
#define N 100005
#define M 1000005
#define ll long long
using namespace std;
ll n,m,bl,uv,cnt[M],a[N],ans[N],k;
struct query{
	ll l,r,pos,id;
}q[N];
bool cmp(const query &a,const query &b){
	return a.pos<b.pos||a.pos==b.pos&&a.r<b.r;
}
int main(){
	scanf("%lld %lld %lld",&n,&m,&k);
	bl=(ll)sqrt(n);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld",&q[i].l,&q[i].r);
		q[i].id=i;
		q[i].pos=q[i].l/bl+1;
	}
	sort(q+1,q+m+1,cmp);
	for(ll i=1,l=0,r=0;i<=m;i++){
		while(l>q[i].l) uv+=(++cnt[a[--l]]==1);
		while(r<q[i].r) uv+=(++cnt[a[++r]]==1);
		while(l<q[i].l) uv-=(--cnt[a[l++]]==0);
		while(r>q[i].r) uv-=(--cnt[a[r--]]==0);
		ans[q[i].id]=uv;
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<endl;
	return 0;
}
