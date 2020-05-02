#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
struct actvt{
	ll s,f;
	bool operator < (const actvt &a)const{
		return f<a.f||f==a.f&&s>a.s;
	}
}a[N];
ll n,ans;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].s,&a[i].f);
	sort(a+1,a+n+1);ans=1;
	for(ll i=2,tmp=a[1].f;i<=n;i++){
		if(a[i].s>=tmp) tmp=a[i].f,ans++;
		//cout<<a[i].f<<endl;
	}
		
	printf("%lld\n",ans);
	return 0;
}

