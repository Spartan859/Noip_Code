#include<bits/stdc++.h>
#define M 1005
#define ll long long
using namespace std;
ll n,m,r;
ll f[M];
struct qj{
	ll st,ed,ef;
}a[M];
bool cmp(const qj &a,const qj &b){
	return a.ed<b.ed;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&r);
	for(ll i=1;i<=m;i++)
		scanf("%lld%lld%lld",&a[i].st,&a[i].ed,&a[i].ef);
	sort(a+1,a+n+1,cmp);
	f[1]=a[1].ef;
	for(ll i=2;i<=m;i++){
		f[i]=a[i].ef;
		for(ll j=1;j<=i-1;j++)
			if(a[i].st-a[j].ed>=r) f[i]=max(f[i],f[j]+a[i].ef);
	}
	printf("%lld\n",*max_element(f+1,f+n+1));
	return 0;
}

