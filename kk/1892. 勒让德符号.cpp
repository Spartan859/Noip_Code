#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T;
ll p,n;
inline ll ksm(ll x,ll y,ll m){
	ll re=1,ex=x;
	while(y){
		if(y&1) re=re*ex%m;
		ex=ex*ex%m;
		y>>=1;
	}
	return re;
}
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&p);
		if(p==2){
			if(n&1) printf("%d\n",1);
			else printf("%d\n",0);
			continue;
		}
		if(n%p==0) printf("%d\n",0);
		else if(ksm(n,(p-1)/2,p)==p-1) printf("%d\n",-1);
		else printf("%d\n",1);
	}
	return 0;
}

