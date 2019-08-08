#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll sz[10005];
ll *a;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",sz+i);
	a=unique(sz+1,sz+n+1);
	for(ll i=1;i<=a.size();i++) cout<<sz[i]<<' ';
	return 0; 
}
