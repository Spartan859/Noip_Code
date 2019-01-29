#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f
using namespace std;
ll mp[25][125];
ll d[25][25];
ll dp[1000005][25];

ll t,n;
ll x[25],y[25];

ll solve(ll n){
	memset(dp,inf,sizeof(dp));
   	d[1][1]=0;
   	ll cnt=1;
	for(ll i=0;i<n;i++){
        dp[cnt|(1<<i)][i]=d[0][i];
    }
   	for(ll i=0;i<=(1<<(n))-1;i++){
       	for(ll j=0;j<n;j++){
          	for(ll k=0;k<n;k++){
              	if(!(i&(1<<j))&&(i&(1<<k))){
                    dp[i|(1<<j)][j]=min(dp[i|(1<<j)][j],dp[i][k]+d[k][j]);
                }
          	}
       	}
   	}
   	ll ans=inf;
   	for(ll i=0;i<n;i++)
    ans=min(ans,dp[(1<<(n))-1][i]+d[i][0]);
    return ans;
}
void floyd(ll n){
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++){
        	d[i][j]=mp[i][j];
    	}
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            for(ll k=0;k<n;k++){
            	if(d[i][k]>d[i][j]+d[j][k])
                	d[i][k]=d[i][j]+d[j][k];
        }
}
int main(){
	//freopen("agent.in","r",stdin);
	//freopen("agent.out","w",stdout);
	memset(mp,inf,sizeof(mp));
    scanf("%d",&n);
    for(ll i=0;i<n;i++){
    	scanf("%d %d",x+i,y+i);
	}
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			mp[i][j]=mp[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
    floyd(n);
    printf("%d\n", solve(n));
    cout<<(1<<19)<<endl;
  	return 0;
}
