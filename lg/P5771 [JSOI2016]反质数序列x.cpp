#include<bits/stdc++.h>
#define ll long long
const ll N=3005,TP=200000;
using namespace std;
vector<ll> es[N];
ll n;ll a[N];
bool isp[TP+5];
inline void initP(){
	memset(isp,true,sizeof(isp));
	isp[0]=isp[1]=0;
	for(ll i=2;i<=TP;i++)
		if(isp[i])
			for(ll j=i+i;j<=TP;j+=i) isp[j]=0;
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	initP();
	
}

