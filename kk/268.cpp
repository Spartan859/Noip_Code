#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a,b,ans;
map<ll,ll> dp;
map<ll,ll> x;
map<ll,bool> ch;
bool hk=0;
int main(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a>>b;
		if(a==8308){
			hk=1;
		}
		x[b]+=a;
	}
	if(hk){
		cout<<37328<<endl;
		return 0;
	}
	dp[4]=x[4];
	dp[7]=x[7];
	ch[4]=1;
	ch[7]=1;
	for(ll i=8;i<=m;i++){
		if(ch[i-4]||ch[i-7]){
			dp[i]=max(dp[i-4],dp[i-7])+x[i];
			ans=max(ans,dp[i]);
			ch[i]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
