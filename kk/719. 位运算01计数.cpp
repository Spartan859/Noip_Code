#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cnto,cntz,cnt;
int main(){
	scanf("%lld",&n);
	while(n!=0){
		if(n&1) cnto++;
		else cntz++;
		n>>=1;
		cnt++;
	}
	printf("%lld %lld %lld",cnt,cnto,cntz);
	return 0;
}
