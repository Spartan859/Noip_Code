#include<bits/stdc++.h>
#define N 105
#define M 10005
#define ll long long
using namespace std;
ll t,n,m;
ll f[M],p[N][N];
int main(){
	scanf("%lld%lld%lld",&t,&n,&m);
	for(ll i=1;i<=t;i++)
		for(ll j=1;j<=n;j++) scanf("%lld",&p[i][j]);
	for(ll i=1;i<=t-1;i++){
		memset(f,0,sizeof(f));
		for(ll j=1;j<=n;j++)
			for(ll k=1;k<=m;k++)
				if(k>=p[i][j]) f[k]=max(f[k],f[k-p[i][j]]+p[i+1][j]-p[i][j]);
		m+=f[m];
	}
	printf("%lld\n",m);	
	return 0;
}
