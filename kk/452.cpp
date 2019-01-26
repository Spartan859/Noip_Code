#include<bits/stdc++.h>
#define N 10005
using namespace std;
int n,a,b,dp[N]={0};
int main(){
	cin>>n>>a>>b;
	dp[a]=1; dp[b]=1;//Ò»²½µ½
	for(int i=1;i<=n;i++){
		if(i>a&&i>b&&dp[i-a]&&dp[i-b]) dp[i]=min(dp[i-a],dp[i-b])+1;
		if(i>a&&i>b&&dp[i-a]&&!dp[i-b]) dp[i]=dp[i-a]+1;
		if(i>a&&i>b&&!dp[i-a]&&dp[i-b]) dp[i]=dp[i-b]+1;
		if(i>a&&i<b&&dp[i-a]) dp[i]=dp[i-a]+1;
		if(i<a&&i>b&&dp[i-b]) dp[i]=dp[i-b]+1;
	}
	if(dp[n]==0) cout<<-1<<endl;
	else cout<<dp[n]<<endl;
	return 0; 
}
