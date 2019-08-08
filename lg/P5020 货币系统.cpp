#include<bits/stdc++.h>
#define N 105
#define A_MAX 25005
#define ll long long
using namespace std;
ll T,n,a[N],ans;
ll f[A_MAX];
int main(){
	scanf("%lld",&T);
	while(T--){
		memset(f,0,sizeof(f));
		f[0]=1;
		scanf("%lld",&n);
		ans=n;
		for(ll i=1;i<=n;i++) scanf("%lld",a+i);
		sort(a+1,a+n+1);
		for(ll i=1;i<=n;i++){
			if(f[a[i]]) ans--;
			else for(ll j=a[i];j<=a[n];j++) f[j]=f[j]|f[j-a[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
