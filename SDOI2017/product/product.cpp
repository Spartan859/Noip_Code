#include<bits/stdc++.h>
#define MOD 1000000007
#define N 1005
#define ll long long
using namespace std;
ll T,n,m;
ll f[N],mtx[N][N],gm[N][N];
inline ll gcd(ll i,ll j){
	if(i==0||j==0) return 0; 
	if(gm[i][j]!=0) return gm[i][j];
	if(i<j) swap(i,j);
	while(i%j){
		i%=j;
		if(i<j) swap(i,j);
	}
	gm[i][j]=gm[j][i]=j;
	return j;
}
int main(){
	freopen("product.in","r",stdin);
	freopen("product.out","w",stdout);
	f[1]=1;
	for(ll i=2;i<=1000;i++) f[i]=(f[i-1]+f[i-2])%MOD;
	for(ll i=1;i<=1000;i++) mtx[0][i]=1;
	for(ll i=1,hang;i<=1000;i++){
		hang=1;
		for(ll j=1;j<=1000;j++){
			hang=hang*f[gcd(i,j)]%MOD;
			mtx[i][j]=mtx[i-1][j]*hang%MOD;
		}
	}
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",mtx[n][m]);
	}
	
	return 0;
}
