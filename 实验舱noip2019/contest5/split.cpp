#include<bits/stdc++.h>
#define ABS(x) (((x)>0)?(x):(-(x)))
#define N 3005
#define ll long long
using namespace std;
ll n,m;

ll a[N],b[N],c[N];


int main(){
	#ifndef ONLINE_JUDGE
	freopen("split1.in","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	if(m&1){
		for(ll i=1;i<=(m>>1);i++) b[i]=a[i];
		for(ll i=n,j=1;j<=(m>>1)+1;i--,j++) b[m-j+1]=a[i];
		for(ll i=(m>>1)+1,j=1;j<=n-m;i++,j++) c[j]=a[i];
		ll ans1=0;
		for(ll i=1;i<=m;i++)
			for(ll j=1;j<=n-m;j++) ans1+=ABS(b[i]-c[j]);
		swap(c[1],b[(m>>1)+1]);
		ll ans2=0;
		for(ll i=1;i<=m;i++)
			for(ll j=1;j<=n-m;j++) ans2+=ABS(b[i]-c[j]);
		printf("%lld\n",min(ans1,ans2));
	}else{
		for(ll i=1;i<=(m>>1);i++) b[i]=a[i];
		for(ll i=n,j=1;j<=(m>>1);i--,j++) b[m-j+1]=a[i];
		for(ll i=(m>>1)+1,j=1;j<=n-m;i++,j++) c[j]=a[i];
		ll ans=0;
		for(ll i=1;i<=m;i++)
			for(ll j=1;j<=n-m;j++) ans+=ABS(b[i]-c[j]);
		printf("%lld\n",ans);
	}
	return 0;
}
