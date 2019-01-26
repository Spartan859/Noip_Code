#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[1005][2005],n,m,a[1005],b[1005];
int main(){
	freopen("haitao.in","r",stdin);
	freopen("haitao.out","w",stdout);
	scanf("%lld %lld",&m,&n);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	for(ll i=1;i<=n;i++) scanf("%lld",b+i);
	for(ll i=1;i<=n;i++) f[i][0]=f[i-1][0]+b[i];
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++){
			if(j<a[i]) f[i][j]=f[i-1][j]+b[i];
			else f[i][j]=min(f[i-1][j]+b[i],f[i-1][j-a[i]]);
		}
	printf("%lld",f[n][m]);
	return 0;
}
 
