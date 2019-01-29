#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n,x[N],a,b,ans;
int main(){
	freopen("enemy.in","r",stdin);
	freopen("enemy.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",x+i);
	for(ll i=2;i<=n-1;i++){
		a=0;b=0;
		for(ll j=1;j<i;j++) if(x[j]<x[i]) a++;
		for(ll j=i+1;j<=n;j++) if(x[j]<x[i]) b++;
		ans+=a*b;
	}
	cout<<ans<<endl;
	return 0;
}
