#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
ll f[N],n,a[N],ans;
int main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		if(i>=a[i]) f[i]=1;
		if(i>a[i]) f[i]=max(f[i],f[i-a[i]]+1);
	}
	ans=*max_element(f+1,f+n+1);
	printf("%lld",ans);
	return 0;
}
