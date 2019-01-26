#include<bits/stdc++.h>
#define N 1010
using namespace std;
string a,b;
int la,lb,dp[N][N];
int main(){
	cin>>a>>b;
	la=a.size();
	lb=b.size();
	a=" "+a;
	b=" "+b;
	for(int i=1;i<=la;i++)
	    for(int j=1;j<=lb;j++)
	        if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
	        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	cout<<dp[la][lb]<<endl;
	return 0;
}
