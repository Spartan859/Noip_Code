#include<bits/stdc++.h>
#define N 50005
#define ll long long
using namespace std;
ll n,m,a[N],L,R,maxv=0,minv=50005;
ll cnt[N][N],fz,fm,tmp;
inline ll C_2(ll x){
	return x*(x-1)/2;
}
ll gcd(ll x,ll y){
	ll rt;
	while(y>0){
		rt=x%y;
		x=y;
		y=rt;
	}
	return x;
}
int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i),maxv=max(maxv,a[i]),minv=min(minv,a[i]);
	for(ll i=minv;i<=maxv;i++)
		for(ll j=1;j<=n;j++) cnt[i][j]=cnt[i][j-1]+(a[j]==i);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld",&L,&R);
		fm=C_2(R-L+1);
		for(ll j=minv;j<=maxv;j++) if(cnt[j][R]-cnt[j][L-1]>1) fz+=C_2(cnt[j][R]-cnt[j][L-1]);
		tmp=gcd(fz,fm);
		fm/=tmp;fz/=tmp;
		if(fz==0) cout<<"0/1"<<endl;
		else cout<<fz<<"/"<<fm<<endl;
		fz=0;
	}
	return 0;
}
