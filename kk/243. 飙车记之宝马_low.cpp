#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,l[100005],r[100005],q,ans,cnt;
int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n-1;i++) scanf("%lld %lld",l+i,r+i);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&q);
		ans=cnt=0;
		for(ll j=1;j<=n;j++){
			if(q>=l[j]&&q<=r[j]) cnt++;
			else{
				ans=max(ans,cnt);
				cnt=0;
			}
		}
		printf("%lld ",ans);
	}
	return 0;
}
