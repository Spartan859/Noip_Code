#include<bits/stdc++.h>
#define N 1005
#define mod 100000007
#define ll long long
using namespace std;
ll n,p;
ll f[N][N],xy[N];
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%lld%lld",&n,&p);
	for(ll i=1,x,y;i<=p;i++){
		scanf("%lld%lld",&x,&y);
		xy[x]=y;
	}
	for(ll i=1;i<=n;i++){
		if(xy[n])
			if(xy[n]==i) f[1][i]=1;
			else f[1][i]=0;
		else f[1][i]=1;
	}
	for(ll i=2;i<=n;i++)
		for(ll j=1;j<=n-i+1;j++){
			if(xy[n-i+1]){
				if(xy[n-i+1]==j) f[i][j]=f[i-1][j+1];
				else if(xy[n-i+1]==j+i-1) f[i][j]=f[i-1][j];
				else f[i][j]=0;
			}else f[i][j]=(f[i-1][j]+f[i-1][j+1])%mod;
		}
	printf("%lld\n",f[n][1]);
	return 0;
}
