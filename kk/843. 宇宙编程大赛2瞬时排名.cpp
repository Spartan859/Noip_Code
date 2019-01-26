#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll cnt[10005],bst[10005];
ll n,x;
inline ll low_bit(ll i){
	return (i&(-i));
}
void point_add(ll i,ll z){
	while(i<=10000){
		bst[i]=bst[i]+z;
		i+=low_bit(i);
	}
}
ll query(ll i){
	ll sum=0;
	for(;i;i-=(i&(-i))) sum+=bst[i];
	return sum;
}
int main(){
	//freopen("rank.in","r",stdin);
	//freopen("rank.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&x);
		printf("%lld ",i-query(x+1));
		point_add(x+1,1);
	}
	return 0;
}
