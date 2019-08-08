#include<bits/stdc++.h>
#define N 100005
#define Q 100005
#define ll long long
using namespace std;
ll n,ai;
ll q,k[Q];
ll wt[N];
ll ans;
multiset<ll> s;
multiset<ll>::iterator it;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&ai);
		s.insert(ai);
	}
	scanf("%lld",&q);
	for(ll i=1;i<=q;i++)
		scanf("%lld",k+i);
	for(ll i=1;i<=q;i++){
		ll cnt=0,tmp;
		for(ll j=1;j<=k[i];j++){
			it=s.end();
			it--;
			tmp=*it;
			wt[++cnt]=tmp-1;
			ans+=tmp;
			//cout<<tmp<<' ';
			s.erase(it);
		}
		for(ll j=1;j<=cnt;j++) s.insert(wt[j]);
		//cout<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}
