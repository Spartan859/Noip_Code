#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
ll n,m,p;
ll sm=1;
int main(){
	ll tmp;
	scanf("%lld",&tmp);
	scanf("%lld%lld%lld",&m,&n,&p);
	if(tmp==0){
		cout<<0<<endl;
		return 0;
	}
	for(ll i=m-n+1,j=1,k=2;j<=n;j++,i--){
		sm=sm*i;
		if(sm>p) sm%=p;
	}
	printf("%lld\n",sm);
	return 0;
}
