#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n;
vector<ll> es[N];
int main(){
	scanf("%lld",&n);
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u); 
	}
}

