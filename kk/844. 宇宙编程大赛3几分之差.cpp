#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll bst[10005];
ll n,x[N],d[N];
const ll ten_thousand=10000,zr=0;
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
	//freopen("score.in","r",stdin);
	//freopen("score.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",x+i);
	for(ll i=1;i<=n;i++) scanf("%lld",d+i);
	
	for(ll i=1;i<=n;i++){
		printf("%lld ",query(min(x[i]+1+d[i],ten_thousand))-query(max(x[i]-d[i],zr)));
		point_add(x[i]+1,1);
	}
	return 0;
}
