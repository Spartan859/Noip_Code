#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,n,zdws,tmp=1,sw[15],cpyn,ttt[13],dsw,j,ans[15];
inline ll calc(ll x,ll y){//第x位为y，后面的有多少种情况 
	ll cnt=1;
	if(x==1&&y==sw[1]||ans[x-1]==sw[x-1]){
		for(ll i=2;i<=zdws;i++) cnt*=sw[i]+1;
		return cnt;
	}
	else cnt=ttt[x-1];
}
int main(){
	scanf("%lld %lld",&k,&n);
	for(;tmp<=n;tmp*=10)zdws++;
	cpyn=n;
	for(ll i=zdws;i>=1;i--) sw[i]=cpyn%10,cpyn/=10;
	sw[zdws+1]=93410938;//rdm
	ttt[0]=1;
	for(ll i=1;i<=13;i++) ttt[i]=ttt[i-1]*10;
	for(ll i=1;i<=zdws-1;i++){
		if(i==1) j=1;
		else j=0;
		while(j<=(ans[i+1]==sw[i+1]?sw[i]:9)){
			dsw+=calc(i,j);
			if(dsw>=k) break;
			j++;
		}
		dsw-=calc(i,j);
		ans[i]=j;
	}
	for(ll i=1;i<=zdws-1;i++) cout<<ans[i];
	return 0;
}
