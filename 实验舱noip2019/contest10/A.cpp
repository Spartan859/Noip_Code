#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
ll n,m;
ll a[N];
vector<ll> es[N];
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}

inline bool check(ll k){
	ll ans=0,ac[N]={0};
	for(ll i=1;i<=n;i++) ac[i]=a[i];
	//for(ll i=1;i<=n;i++) cout<<ac[i]<<' ';
	for(ll i=1,tmp;i<=n;i++){
		if(ac[i]<=0) continue;
		tmp=ceil((double)ac[i]/k);
		for(ll j=i,l=k;j<=min(n,i+k-1);j++) ac[j]-=tmp*l,l--;
		ans+=tmp;
		//cout<<ans<<endl;
		if(ans>m) return 0;
	}
	return 1;
}
int main(){
	//#ifndef ONLINE_JUDGE
	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	//#endif 
	n=read();m=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	if(m==1){
		ll ansx=a[1];
		for(ll i=2;i<=n;i++) if(a[i]>ansx-i+1) ansx=a[i]+i-1;
		printf("%lld\n",ansx);
		return 0; 
	} 
	
	ll l=0,r=1e18,mid,ans;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid;
	}
	printf("%lld\n",ans);
	//cout<<check(32)<<endl;
	return 0;
}
