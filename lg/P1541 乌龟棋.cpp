#include<bits/stdc++.h>
#define A 45
#define ll long long
using namespace std;
ll n,m,a[5];
ll f[45][45][45][45];
ll sc[355];
int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",sc+i);
	for(ll i=1,tmp;i<=m;i++){
		scanf("%lld",&tmp);
		a[tmp]++;
	}
	for(ll i=0;i<=a[1];i++)
		for(ll j=0;j<=a[2];j++)
			for(ll k=0;k<=a[3];k++)
				for(ll l=0;l<=a[4];l++){
					ll tmp=i+j+j+k+k+k+l+l+l+l+1;
					if(!(i||j||k||l)){
						f[0][0][0][0]=sc[1];
						continue;
					}
					if(i!=0) f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]+sc[tmp]);
					if(j!=0) f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]+sc[tmp]);
					if(k!=0) f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]+sc[tmp]);
					if(l!=0) f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]+sc[tmp]); 
				}
	printf("%lld",f[a[1]][a[2]][a[3]][a[4]]);
	return 0;			
} 
