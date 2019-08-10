#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
inline ll gcd(ll x,ll y){
	if(x<y) swap(x,y);
	while(x%y){
		x%=y;
		if(x<y) swap(x,y);
	}
	return y;
}
inline void read_mod(){
	char c;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9'){
		m=m*10+c-'0';
		if(m>=n) m%=n;
		c=getchar();
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	//freopen("A.in","r",stdin);
	//freopen("A.ans","w",stdout);
	#endif
	scanf("%lld",&n);
	read_mod();
	if(m) printf("%lld\n",gcd(n,m));
	else printf("%lld\n",n);
	return 0;
}
