#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e7;
ll n,a[N]; 
double ans;
void inp(){
	ll A,B,C;
	scanf("%lld%lld%lld%lld%lld",&n,&A,&B,&C,a+1);
	for(ll i=2;i<=n;i++)
		a[i]=(a[i-1]*A+B)%100000001;
	for(ll i=1;i<=n;i++)
		a[i]=a[i]%C+1;
}
int main(){
	inp();
	for(ll i=2;i<=n;i++) ans+=1.0/max(a[i-1],a[i]);
	ans+=1.0/max(a[1],a[n]);
	printf("%.3lf\n",ans);
	return 0;
}

