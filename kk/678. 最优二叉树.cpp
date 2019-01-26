#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[2005][2005],n,s[2005],p[2005][2005],a,qzh[2005];
int main(){
	scanf("%lld",&n);
	for(ll i=1,a;i<=n;i++){
		scanf("%lld",&a);
		s[i]=s[(p[i][i]=i)-1]+(f[i][i]=a);
		qzh[i]=qzh[i-1]+a;
	}
	for(ll i=n-1,v;i>=1;i--){
		for(ll j=i+1;j<=n;j++){
			f[i][j]=2e18;
			for(ll k=p[i][j-1];k<=p[i+1][j];k++){
				if(f[i][j]>f[i][k-1]+f[k+1][j]+qzh[j]-qzh[i-1]){
					f[i][j]=f[i][k-1]+f[k+1][j]+qzh[j]-qzh[i-1];
					p[i][j]=k;
				}
			}
		}
	}
	printf("%lld",f[1][n]);
	return 0;
}
