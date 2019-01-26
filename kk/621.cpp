#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll T,a[5],q[105],maxq,cnt=1;
int main(){
	//freopen("charm.in","r",stdin);
	//freopen("charm.out","w",stdout);
	scanf("%lld",&T);
	for(ll i=1;i<=T;i++) {
		scanf("%lld",&q[i]);
		maxq=max(maxq,q[i]);
	}
	a[3]=a[2]=a[1]=1;
	while(q[cnt]<=3){
		printf("1\n");
		cnt++;
	}
	for(ll i=4;i<=maxq;i++){
		a[(i%4==0?4:i%4)]=(a[((i-1)%4==0?4:(i-1)%4)]+a[((i-3)%4==0?4:(i-3)%4)])%mod;
		if(i==q[cnt]){
			printf("%lld\n",a[(i%4==0?4:i%4)]);
			cnt++;
		}
	}
	return 0;
}
