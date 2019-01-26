#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x[10005],ans;
int main(){
	//freopen
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",x+i);
	for(ll i=1;i<=n;i++)
		if(x[i]>0){
			x[i+1]-=x[i];
			ans+=x[i];
			x[i]=0;
		}
	printf("%lld\n",ans);
	return 0;
}
