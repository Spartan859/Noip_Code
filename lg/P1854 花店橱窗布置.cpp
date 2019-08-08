#include<bits/stdc++.h>
#define FM 105
#define INF 2e18
#define ll long long
using namespace std;
ll F,V,A[FM][FM],ans=-INF,ansb;
pair<ll,ll> f[FM][FM];
void printans(ll x,ll b){
	if(x==1){
		printf("%lld ",b);
		return;
	} 
	printans(x-1,f[x][b].second);
	printf("%lld ",b);
}
int main(){
	scanf("%lld %lld",&F,&V);
	for(ll i=1;i<=F;i++)
		for(ll j=1;j<=V;j++) scanf("%lld",&A[i][j]);
		
	for(ll i=1;i<=F;i++)
		for(ll j=i;j<=V-F+i;j++){
			f[i][j].first=-INF;
			if(i==1) f[i][j]=make_pair(A[i][j],0);
			else
				for(ll k=i-1;k<j;k++)
					if(f[i-1][k].first+A[i][j]>f[i][j].first)
						f[i][j]=make_pair(f[i-1][k].first+A[i][j],k);
		}
	for(ll i=F;i<=V;i++)
		if(f[F][i].first>ans) ans=f[F][i].first,ansb=i;
	printf("%lld\n",ans);
	printans(F,ansb);
	return 0;
}


