#include<bits/stdc++.h>
#define N 1010
#define Q 10010
using namespace std;
int n,q,h[N][N],x1,yl,x2,y2;
long long anst,ans[10010],dp[N][N],hang[N][N];
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++){
	        cin>>h[i][j];
	        hang[i][j]=hang[i][j-1]+h[i][j];
	        dp[i][j]=hang[i][j]+dp[i-1][j];
	    }
	for(int a=0;a<q;a++){
		cin>>x1>>yl>>x2>>y2;
		anst=dp[x2][y2]-dp[x1-1][y2]-dp[x2][yl-1]+dp[x1-1][yl-1];
		ans[a]=anst;
		anst=0;
	}
	for(int a=0;a<q;a++) cout<<ans[a]<<endl;
	return 0;
}
