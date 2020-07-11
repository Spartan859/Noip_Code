#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x[100005],p[100005],X1,X2,tmp,di,ans=100000005;
int main(){
	freopen("bow.in","r",stdin);
	freopen("bow.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld %lld",&x[i],&p[i]);
	for(ll i=1;i<=n-1;i++)
		for(ll j=i+1;j<=n;j++){
			X1=x[i];
			X2=x[j];
			tmp=0;
			for(ll k=1;k<=n;k++){
				di=min(abs(x[k]-X1),abs(x[k]-X2));
				tmp+=di*p[k];
			}
			ans=min(ans,tmp);
		}
	printf("%lld\n",ans);
	return 0;
} 
