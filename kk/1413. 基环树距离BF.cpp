#include<bits/stdc++.h>
#define INF 1e18
#define N 1005
#define ll long long
using namespace std;
ll n,q;
ll dis[N][N];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test2.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++) if(i!=j) dis[i][j]=INF;
	for(ll i=1,a,b,c;i<=n;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		dis[a][b]=dis[b][a]=c;
	} 
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	scanf("%lld",&q);
	for(ll i=1,a,b;i<=q;i++){
		scanf("%lld%lld",&a,&b);
		cout<<dis[a][b]<<endl;
	}	
	return 0;		
}

