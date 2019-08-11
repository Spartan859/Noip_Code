#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
ll n,m;
ll a[N],sx[N],v[N];
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}

inline bool check(ll k){
	ll ans=0,ac[N];
	for(ll i=1;i<=n;i++) ac[i]=a[i];
	for(ll i=1,tmp;i<=n;i++){
		if(ac[sx[i]]>0) tmp=ceil((double)ac[sx[i]]/k);
		for(ll j=i,l=k;)
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	#endif 
	n=read();m=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	for(ll i=1;i<=n;i++){
		ll tmp=-2e18,jx;
		for(ll j=1;j<=n;j++)
			if(a[j]>tmp&&!v[j]) jx=j,tmp=a[j];
		sx[i]=jx;v[jx]=1;
	}
	//for(ll i=1;i<=n;i++) cout<<sx[i]<<' ';	
	/*ll l=0,r=1e18,mid,ans;
	while(l<r){
		mid=(l+r+1)>>1;
		cout<<mid<<endl;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid;
	}
	printf("%lld\n",ans);*/
	//cout<<check(32)<<endl;
	return 0;
}
