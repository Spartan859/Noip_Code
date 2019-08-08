#include<bits/stdc++.h>
#define fi(s) freopen(s,"r",stdin)
#define fo(s) freopen(s,"w",stdout)
#define ll long long
using namespace std;

const ll mod=998244353;
ll tp,T;

ll ksm(ll a,ll q){
	ll res=1;
	while(q){
		if(q&1) res*=a,res%=mod;
		a=a*a,a%=mod;
		q>>=1;
		//cout<<q<<endl;
	}
	return res;
}
int main(){
	#ifndef ONLINE_JUDGE
		fi("input.txt");
		fo("output.txt");
	#endif
	scanf("%lld",&tp);
	scanf("%lld",&T);
	//printf("%lld\n",ksm(tp,T));
	//cout<<T<<endl;
	if(tp==0){
		ll n;
		while(T--){
			scanf("%lld",&n);
			if(n&1) printf("%lld\n",ksm(2,n-1));
			else printf("%lld\n",(ksm(2,n-1)+mod-1)%mod);
		}
	}else{
		ll A,B,C,D,X=0,Y=0,n,ans=0;
		scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
		while(T--){
			X=(X*A+B)%mod+1;
			Y=(Y*C+D)%mod+1;
			n=X*mod+Y;
			if(n&1) ans+=ksm(2,n-1),ans%=mod;
			else ans+=ksm(2,n-1)+mod-1,ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
