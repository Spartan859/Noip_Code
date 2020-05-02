#include<bits/stdc++.h>
#define ABS(x) ((x)>=0?(x):(-(x)))
#define ll long long
using namespace std;
const ll N=1e3+5,INF=1e18;
ll n,m;
ll X[N],Y[N];
ll mht(ll x,ll y,ll xx,ll yy){
	return ABS(x-xx)+ABS(y-yy);
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		scanf("%lld%lld",X+i,Y+i);
	for(ll i=1,t,x,y;i<=m;i++){
		scanf("%lld%lld%lld",&t,&x,&y);
		if(t==1) X[++n]=x,Y[n]=y;
		else{
			ll ans=INF;
			for(ll j=1;j<=n;j++) ans=min(ans,mht(X[j],Y[j],x,y));
			printf("%lld\n",ans);
		}
	}
	return 0;
}

