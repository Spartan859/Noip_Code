#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,p,m;
ll quick_pow_mod(ll a,ll p){
	if(p==1) return a%m;
	ll tmp=quick_pow_mod(a,p>>1);
	tmp*=tmp;tmp%=m;
	if(p&1) return (tmp*a)%m;
	return tmp;
}
int main(){
	cin>>x>>p>>m;
	cout<<quick_pow_mod(x,p)<<endl;
	return 0;
}
