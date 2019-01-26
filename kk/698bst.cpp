#include<bits/stdc++.h>
#define ll long long
#define MOD 100000007 
using namespace std;
ll bst[100005],t,x,y,n,m;
inline ll low_bit(ll i){
	return (i&(-i));
}
void point_add(ll i,ll z){
	while(i<=n){
		bst[i]=(bst[i]+z)%MOD;
		i+=low_bit(i);
	}
}
ll query(ll i){
	ll sum=0;
	while(i){
		sum+=bst[i];
		sum%=MOD;
		i-=low_bit(i);
	}
	return sum;
}

int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld %lld",&t,&x,&y);
		if(t==1) printf("%lld\n",(query(y)-query(x-1)+MOD)%MOD);
		else point_add(x,y);
	}
	return 0;
}
