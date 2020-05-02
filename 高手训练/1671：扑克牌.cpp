#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,b;
priority_queue<ll> ms;
int main(){
	scanf("%lld%lld",&n,&b);
	for(ll i=1,tmp;i<=n;i++){
		scanf("%lld",&tmp);
		ms.push(-tmp);
	}
	ll pt=0;
	while(b--){
		pt++;
		ll tmp=ms.top()-1;
		ms.pop();
		ms.push(tmp);
		if(-ms.top()<=pt){
			printf("%lld\n",-ms.top());
			return 0;
		}
	}
	printf("%lld\n",-ms.top());
	return 0;
}
