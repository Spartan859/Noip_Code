#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,s[200005],t[200005],tmp;
int main(){
	freopen("domination.in","r",stdin);
	freopen("domination.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",t+i);
	for(ll i=1;i<=n;i++) scanf("%lld",s+i);
	for(ll i=1;i<=n;i++){
		tmp=0;
		for(ll j=1;j<=n;j++)
			if(s[i]<s[j]&&t[i]>t[j]) tmp++;
		printf("%lld ",tmp);
	}
	return 0;
} 
