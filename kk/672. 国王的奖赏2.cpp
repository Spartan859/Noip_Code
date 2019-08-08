#include<bits/stdc++.h>
#define max(a,b) a>b?a:b
#define ll long long
#define N 505
#define getsum(x1,y1,x2,y2) s[x2][y2]+s[x1-1][y1-1]-s[x2][y1-1]-s[x1-1][y2]
using namespace std;
ll n,m,d[N][N],s[N][N],tmp,f[N],ans;
int main(){
	//freopen("reward2.in","r",stdin);
	//freopen("reward2.out","w",stdout); 
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++) scanf("%lld",&d[i][j]);
	for(ll i=1;i<=n;i++){
		tmp=0;
		for(ll j=1;j<=m;j++){
			tmp+=d[i][j];
			s[i][j]=s[i-1][j]+tmp;
		}
	}
	for(ll i1=1;i1<=n;i1++)
		for(ll i2=i1;i2<=n;i2++)
			for(ll j=1;j<=m;j++) f[j]=max(0,f[j-1]+getsum(i1,j,i2,j)),ans=max(ans,f[j]);
	printf("%lld\n",ans);
	return 0;
}
