#include<bits/stdc++.h>
#define N 1005 
#define INF 2e9
#define ll long long
using namespace std;
ll n=1,d[N],x[N];
int main(){
	/*scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",x+i);*/
	while(cin>>x[n]) n++; 
	fill(d+1,d+n+1,INF);
	for(int i=1;i<=n;i++)
		*lower_bound(d+1,d+n+1,x[i])=x[i];
	ll cnt=lower_bound(d+1,d+n+1,INF)-d-1;
	cout<<cnt<<endl; 
	return 0;
}
