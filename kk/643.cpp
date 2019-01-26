#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mu[1000005],vst[1000005],pr[1000005],cnt;
ll x,y,p,s;
ll F(ll k){
	ll kx=(x-1)/k+1,ky=y/k;
	ll s=(kx+ky)*(ky-kx+1)/2%p*k%p;
	return s*s%p;
}
int main(){
	scanf("%lld %lld %lld",&x,&y,&p);
	mu[1]=1;
	for(ll i=2;i<=y;i++){
		if(!vst[i]){
			pr[++cnt]=i;
			mu[i]=-1;
		}
		for(ll j=1;j<=cnt&&i*pr[j]<=y;j++){
			vst[i*pr[j]]=1;
			if(i%pr[j]==0){
				mu[i*pr[j]]=0;
				break;
			}
			mu[i*pr[j]]=-mu[i];
		}
	}
	for(ll i=1;i<=y;i++)
		if(mu[i]!=0) s=(s+mu[i]*F(i))%p;
	printf("%lld\n",(s%p+p)%p);
	return 0;
}
