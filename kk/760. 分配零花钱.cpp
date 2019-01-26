#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=1,n,k;
void dfs(ll x){
	if((x+k)%2!=0) return;
	ll tmp1=(x-k)/2,tmp2=(x+k)/2;
	if(tmp1<=0||tmp2<=0) return;
	ans++;
	dfs(tmp1);
	dfs(tmp2);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout); 
	scanf("%lld %lld",&n,&k);
	dfs(n);
	cout<<ans<<endl;
	return 0;
}
