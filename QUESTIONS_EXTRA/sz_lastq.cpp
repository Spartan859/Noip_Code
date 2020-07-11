#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll f[N][2][2];
ll n;
int main(){
	scanf("%lld",&n);
	f[2][0][0]=1;
	f[2][0][1]=1;
	f[2][1][0]=0;
	f[2][1][1]=1;
	for(ll i=3;i<=n;i++){
		f[i][0][0]=f[i-1][0][0]+f[i-1][1][0];
		f[i][0][1]=f[i-1][0][0]+f[i-1][1][0];
		f[i][1][0]=f[i-1][1][1];
		f[i][1][1]=f[i-1][0][1]+f[i-1][1][1];
	}
	ll ans=f[n][0][0]+f[n][1][0]+f[n][1][1];
	printf("%lld\n",ans);
	return 0;
}

