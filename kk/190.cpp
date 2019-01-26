#include<bits/stdc++.h>
#define INF 10005
using namespace std;
int main(){
	int x[105],i=0,dp[105];
	while(cin>>x[i]) i++;
	fill(dp,dp+i,INF);
	for(int j=0;j<i;j++){
		*lower_bound(dp,dp+i,x[j])=x[j];
	}
	cout<<lower_bound(dp,dp+i,INF)-dp;
	return 0;
} 
