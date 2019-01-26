#include<bits/stdc++.h>
#define N 2005
#define ll long long
using namespace std;
ll n,a,b,x[N][N],y[N],ans;
int main(){
	//freopen("blackshard.in","r",stdin);
	//freopen("blackshard.out","w",stdout);
	scanf("%lld",&n);
	ans=n;
	for(ll i=1;i<=n;i++){
		scanf("%lld %lld",&a,&b);
		if(a+b+1>n) continue;
		x[a][b]++;
		y[a]=max(y[a],x[a][b]);
	}
	for(ll i=0;i<=n;i++){
		ans-=y[i];
	}
	printf("%lld",ans);
	return 0;
}
