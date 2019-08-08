#include<bits/stdc++.h>
#define fi(s) freopen(s,"r",stdin);
#define fo(s) freopen(s,"w",stdout);
#define ABS(s) ((s)>0?(s):-(s))
#define N 5000005
#define ll long long
using namespace std;
const ll mod=998244353;
ll X,T;
ll n,m;
ll jc[N];
inline void initjc(){
	jc[1]=1;
	for(ll i=2;i<=N;i++) jc[i]=jc[i-1]*i,jc[i]%=mod/*,cout<<jc[i]<<' '*/;
	//cout<<endl;
}
inline ll pnum(ll x){
	ll ans=0;
	for(ll i=2;i*i<=x;i++)
		if(!(x%i)) x/=i,ans++;
	if(x>1) ++ans;
	return ans;	
}

inline ll ksm(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) res*=x,res%=mod;
		x*=x,x%=mod;
		y>>=1;
	}
	return res;
}



int main(){
	#ifndef ONLINE_JUDGE
	//fi("two2.in");
	//fo("two2x.out");
	#endif
	scanf("%lld%lld",&X,&T);
	if(X==1){
		while(T--){
			scanf("%lld%lld",&n,&m);
			printf("%lld\n",ksm(2,(n-1)*(m-1)));
		}
	}else if(X==-1){
		while(T--){
			scanf("%lld%lld",&n,&m);
			if(n+m&1) printf("%lld\n",0);
			else printf("%lld\n",ksm(2,(n-1)*(m-1)));
		}
	}else{
		initjc();
		ll PX=pnum(ABS(X));
		while(T--){
			scanf("%lld%lld",&n,&m);
			if(n!=m) printf("%lld\n",0);
			else printf("%lld\n",ksm(jc[n],PX)*ksm(2,(n-1)*(n-1))%mod);
			//cout<<jc[n]<<' '<<pnum(n)<<endl;
		}
	}
	/*
	freopen("CON","r",stdin);
	ll qry;
	while(cin>>qry) cout<<pnum(qry)<<endl;
	*/
	return 0;
}
