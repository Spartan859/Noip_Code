#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,x[200005],cnt,ans=-1e9;
int main(){
	freopen("dog.in","r",stdin);
	freopen("dog.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",x+i);
		x[i+n]=x[i];
	}
	for(ll i=1;i<=n*2;i++){
		cnt+=x[i];
		if(i>m){
			cnt-=x[i-m];
			ans=max(ans,cnt);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
