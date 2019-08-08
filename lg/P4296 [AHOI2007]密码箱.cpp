#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x;
double tmp;
int main(){
	scanf("%lld",&n);
	printf("%lld\n",1);
	ll k=n+1;
	while(1){
		tmp=sqrt(k);
		if(tmp>=n) break;
		if((int)tmp==tmp) cout<<(int)tmp<<endl;
		k+=n;
	}
	return 0;
}
