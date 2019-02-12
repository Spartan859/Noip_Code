#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=803,INF=2e18;

ll f[N][N],n,m,y[N],ans=INF;

int main(){
	freopen("variety.in","r",stdin);
	freopen("variety.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",y+i);
	fill(f[0],f[0]+N*N,INF);
	for(ll i=1;i<=n;i++) f[i][1]=0;
	for(ll j=2;j<=m;j++)
		for(ll i=j;i<=n;i++)
			for(ll k=1;k<=i-1;k++)
				f[i][j]=min(f[i][j],f[k][j-1]+abs(y[k]-y[i]));
	for(ll i=m;i<=n;i++) ans=min(ans,f[i][m]);
	printf("%lld\n",ans);
	return 0;
}
