#include<bits/stdc++.h>
#define N 10005
#define ll long long
using namespace std;
ll T;
ll n,a[N],b[N];
bool check(ll x){
	ll hc=0;//可补格用了几个
	ll lf=x,rt=x;//左箱右箱还剩几格 
	for(ll i=1;i<=n;i++){
		lf-=a[i];
		rt-=b[i];
		if(lf<0) hc-=lf,lf=0;
		if(rt<0) hc-=rt,rt=0;
		if(hc>i) return 0;//补不上了 
	}
	//cout<<endl;
	return 1;
}
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		ll lfts=0,rghs=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld",a+i,b+i);
			lfts+=a[i];
			rghs+=b[i];
		} 
		ll l=0,r=max(lfts,rghs),mid,ans;
		while(l<r){
			mid=(l+r+1)/2;
			if(check(mid)) ans=mid,r=mid-1;
			else l=mid;
		}
		printf("%lld\n",ans);
		//if(T==0) cout<<"T:"<<check(5)<<endl;
	}
	return 0;
}
