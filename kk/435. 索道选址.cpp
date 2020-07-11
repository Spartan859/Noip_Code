#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=30005;
ll n;
ll p[N],w[N];
ll s[N],sumsc[N],sump[N];
ll f[N];
ll q[N],l=0,r=1;
ll ans=1e18;
inline double slope(ll x,ll y){
	return (w[x]*sump[x-1]*1.0-w[y]*sump[y-1]*1.0)/(w[x]*1.0-w[y]*1.0);
}
int main(){
	scanf("%lld",&n);
	for(ll i=n;i>=1;--i)
		scanf("%lld%lld",p+i,w+i);
	//cout<<"-----"<<endl;
	for(ll i=1;i<=n;i++){
		w[i]+=w[i-1];
		sump[i]=sump[i-1]+p[i];
		sumsc[i]=sumsc[i-1]+p[i]*w[i];
	} 
	//memset(f,127,sizeof(f));
	q[l]=1;
	for(ll i=2;i<=n;++i){
		while(l+1<r&&slope(q[l],q[l+1])<=sump[i-1]) ++l;
		ll k=q[l]; 
		f[i]=sumsc[i-1]-w[k]*(sump[i-1]-sump[k-1]);
		while(l+1<r&&slope(q[r-1],q[r-2])>=slope(q[r-1],i)) --r;
		q[r++]=i;
	} 	
 	for(ll i=2;i<=n;i++){
 		ans=min(ans,f[i]+sumsc[n]-sumsc[i]-w[i]*(sump[n]-sump[i]));
	}
	printf("%lld\n",ans);
    return 0;
}
