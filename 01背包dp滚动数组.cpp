#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
ll n,c,m,w[N],v[N],f[N][N],ct[N][5];
ll ans;
ll tmpo,tmpt;
inline void solveo(){
	for(ll i=0;i<=2;i++)
		for(ll j=0;j<=c;j++) f[i][j]=0;
	for(ll i=1;i<=n;i++)
	    for(ll j=1;j<=c;j++){
	    	if(j-w[i]>=0)
	    	    f[i%2][j]=max(f[(i-1)%2][j-w[i]]+v[i],f[(i-1)%2][j]);
	    	else
	    	    f[i%2][j]=f[(i-1)%2][j];
		}
	printf("%lld\n",f[n%2][c]);
}
inline ll solvet(ll a){
	for(ll i=0;i<=2;i++)
		for(ll j=0;j<=c;j++) f[i][j]=0;
	for(ll i=1;i<=n;i++)
	    for(ll j=1;j<=c;j++){
	    	if(j-w[i]>=0&&i!=a)
	    	    f[i%2][j]=max(f[(i-1)%2][j-w[i]]+v[i],f[(i-1)%2][j]);
	    	else
	    	    f[i%2][j]=f[(i-1)%2][j];
		}
	return f[n%2][c];
}
int main(){
	freopen("desert.in","r",stdin);
	freopen("desert.out","w",stdout);
	scanf("%lld %lld %lld",&n,&c,&m);
	//scanf("%lld %lld",&c,&n);
	for(ll i=1;i<=n;i++) scanf("%lld %lld",&w[i],&v[i]);
	if(m==0) solveo();
	else if(m==1){
		scanf("%lld %lld",&tmpo,&tmpt);
		printf("%lld",max(solvet(tmpo),solvet(tmpt)));
	}
	return 0;
}
