#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll a[3][3],f[3][3],bg[3][3];
ll T,n;
inline void rst(ll z[3][3]){
	for(ll i=0;i<=2;i++)
		for(ll j=0;j<=2;j++) z[i][j]=0;
	z[0][0]=z[1][1]=z[2][2]=1;
}
inline void mul(ll x[3][3],ll y[3][3]){
	ll z[3][3];
	for(ll i=0;i<=2;i++)
		for(ll j=0;j<=2;j++){
			z[i][j]=0;
			for(ll k=0;k<=2;k++) z[i][j]=(z[i][j]+x[i][k]*y[k][j])%mod;
		}
	for(ll i=0;i<=2;i++)
		for(ll j=0;j<=2;j++) x[i][j]=z[i][j];
} 
inline void cpy(ll x[3][3],ll z[3][3]){
	for(ll i=0;i<=2;i++)
		for(ll j=0;j<=2;j++) x[i][j]=z[i][j];
}
inline void ksm(ll x[3][3],ll y,ll z[3][3]){
	rst(z);
	ll k[3][3];
	cpy(k,x);
	while(y){
		if(y&1) mul(z,k);
		mul(k,k);
		y>>=1;
	}
}
int main(){
	freopen("charm.in","r",stdin);
	freopen("charm.out","w",stdout);
	a[0][1]=a[1][2]=a[2][0]=a[2][2]=1;
	bg[0][0]=bg[1][0]=bg[2][0]=1;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		if(n<=3){
			cout<<1<<endl;
			continue;
		} 
		n-=3;
		ksm(a,n,f);
		mul(f,bg);
		cout<<f[2][0]<<endl;
	}
	return 0;
}

