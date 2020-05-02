#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;ll ans;
ll a[10],nw[10],pre[10];
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++){
		scanf("%lld",a+i);
		nw[i]=n;
	} 
	ans=n;
	while(1){
		ll cb=0;
		for(ll i=1;i<=m;i++){
			cb+=nw[i]/a[i];
			pre[i]=nw[i];
			nw[i]%=a[i];
		} 
		if(cb==0) break;
		if(cb>=n){
			puts("Inf");
			return 0;
		}
		ans+=cb;
		bool flg=1;
		for(ll i=1;i<=m;i++)
			nw[i]+=cb;
	}
	printf("%lld\n",ans);
	return 0;
}

