#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
ll a,b;
inline ll read(){
	ll res=0,f=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*f;
}
inline ll gcd(ll a,ll b){
	if(a>b) swap(a,b);
	while(b%a){
		b%=a;
		if(a>b) swap(a,b);
	}
	return a;
}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("hide.in","r",stdin);
	freopen("hide.out","w",stdout);
	#endif
	a=read();b=read();
	if(gcd(a,b)>1) puts("INFINITY");
	else
		printf("%lld\n",(a-1)*(b-1)/2);
	return 0;
}
