#include<bits/stdc++.h>
#define ll long long
#define N 2000005
using namespace std;
ll q[N],x[N],s[N],f[N],MAX[N],n,m;

bool OK(ll k){
	ll l=1,r=1,tans=0;
	for(int i=1;i<=n;i++){
		while(l<r&&i-q[l]>=k+1) l++;
		while(l<r&&s[i]<s[q[r-1]]) r--;
		q[r++]=i;
		tans=max(tans,s[i]-s[q[l]]);
		if(tans>=m) return 1; 
	}
	return 0;
}
int main(){
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++) cin>>x[i],s[i]=s[i-1]+x[i];
	ll l=0,r=n,ans=-1,mid;
	while(l<=r){
		mid=l+((r-l)>>1);
		if(OK(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld",(ans==-1?0:ans));
	return 0;
}
