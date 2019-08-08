#include<bits/stdc++.h>
#define N 105
#define M 500005
#define A_max 1005
#define ll long long
#define updn(a,b) (a)=min((a),(b))
#define updx(a,b) (a)=max((a),(b))
using namespace std;
inline ll read(){
	ll res=0,fnm=1;
	char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fnm=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fnm;
}

ll T;
ll n,m;
struct{ll xl,zd;}enm[N][M];
ll f[N][A_max];

void solve(){
	n=read();m=read();
	ll MaxAVal=0;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++) enm[i][j].xl=read(),updx(MaxAVal,enm[i][j].xl);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++) enm[i][j].zd=read(),updx(MaxAVal,enm[i][j].zd);
	
	for(ll i=1;i<=n;i++)
		for(ll j=0;j<=MaxAVal;j++) f[i][j]=2e18;
	
	for(ll j=0;j<=MaxAVal;j++) f[0][j]=j; 
	for(ll i=1;i<=n;i++){
		for(ll k=1;k<=m;k++) updn(f[i][enm[i][k].zd],f[i-1][enm[i][k].xl]);
		for(ll j=0;j<=MaxAVal-1;j++) updn(f[i][j+1],f[i][j]+1);
		for(ll j=MaxAVal;j>=1;j--) updn(f[i][j-1],f[i][j]);
	}
	ll ans=2e18;
	for(ll j=0;j<=MaxAVal;j++) updn(ans,f[n][j]);
	printf("%lld\n",ans);
}
int main(){
	T=read();
	while(T--)
		solve();
	return 0;	
}
