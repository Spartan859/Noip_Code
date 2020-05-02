#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n,m;
ll a[N];
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
ll A[N],B[N],C[N];//A为+1-1差分序列，B维护差分A的前缀和，C维护B的前缀和 
inline bool check(ll k){
	ll ans=0,sumB=0;
	memset(A,0,sizeof(A));
	for(ll i=1,tmp;i<=n;i++){
		B[i]=B[i-1]+A[i];
		C[i]=C[i-1]+B[i];
		ll de=sumB-C[i-1];
		if(a[i]+de<=0) continue;
		tmp=ceil((double)(a[i]+de)/k);
		A[i]-=tmp;A[min(n+1,i+k)]+=tmp;B[i]-=tmp;C[i]-=tmp;
		sumB-=k*tmp;
		ans+=tmp;
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
	ll l=0,r=1e9+n,mid,ans;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid;
	}
	printf("%lld\n",ans);
	//cout<<check(32)<<endl;
	return 0;
}
