#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n,m,a[105],dp[105][105];
int main(){
	//freopen("flower.in","r",stdin);
	//freopen("flower.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=0;i<=n;i++) dp[i][0]=1;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++) 
			for(ll k=0;k<=min(a[i],j);k++)
				dp[i][j]+=dp[i-1][j-k],dp[i][j]%=1000007;
	cout<<dp[n][m]<<endl;
	return 0;
}
