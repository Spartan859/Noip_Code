#include<bits/stdc++.h>
#define N 30005
#define INF 2e18
#define T 300
#define ll long long
using namespace std;
ll n,p[N],w[N],s[N];
ll l,r;//test
ll tmp,fst,ans=INF;
ll rdvst[N]={1};
inline ll dist(ll l,ll r){
	return s[r-1]-s[l-1];
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld %lld",p+i,w+i);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+w[i];
	for(ll i=1;i<=n;i++) fst+=dist(i,n+1)*p[i];
	for(ll t=1;t<=T;t++){
		ll i=0;
		while(rdvst[i]) i=rand()%n;
		for(ll j=1;j<i;j++){
			tmp=fst;
			for(ll k=1;k<=i;k++){
				if(k<=j) tmp=tmp-dist(k,n+1)*p[k]+dist(k,j)*p[k];
				else tmp=tmp-dist(k,n+1)*p[k]+dist(k,i)*p[k];
			}
			ans=min(ans,tmp);
		}
	}
	if(n!=2) printf("%lld",ans);
	else printf("0");
	return 0;
}
