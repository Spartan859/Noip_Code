#include<bits/stdc++.h>
#define ll long long
#define N 2000005
using namespace std;
ll w[N],n,k,ans;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%lld %lld",&k,&n);
	for(ll i=0;i<n;i++) scanf("%lld",&w[i]);
	sort(w,w+n);
	for(ll i=0;i<n-1;i++){
		ans+=upper_bound(w+i+1,w+n,w[i]+k)-w-i-1;
	}
	cout<<ans<<endl;
	return 0;
}
