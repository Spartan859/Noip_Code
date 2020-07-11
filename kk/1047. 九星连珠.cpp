#include<bits/stdc++.h>
#define N 15
#define ll long long
using namespace std;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	ll r=exgcd(b,a%b,x,y);
	ll tmp=y;y=x-(a/b)*y;x=tmp;
	return r;
}
ll n;
ll a[N],m[N];
ll ax,mx;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld%lld",m+i,a+i);
	ax=a[1];mx=m[1];
	for(ll i=2,x,y,gcdx,tmp;i<=n;i++){
		gcdx=exgcd(mx,m[i],x,y);
		if((ax-a[i])%gcdx!=0){
			puts("NO");
			return 0;
		}
		tmp=mx/gcdx*m[i];
		x=(x*(a[i]-ax)/gcdx%m[i]+m[i])%m[i];
		ax=((mx*x+ax)%tmp+tmp)%tmp;
		mx=tmp;
	}
	printf("%lld\n",ax);
	return 0;
}

