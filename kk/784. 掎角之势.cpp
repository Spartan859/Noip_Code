#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,rightsp[100005],k2,ans,tmp1,tmp2,sumx[100005],sumfn,sumy[100005];
const ll mdzz=0;
bool dist(ll x,ll y){
	return (x*x+y*y)<=k2;
}
int main(){
	scanf("%lld %lld",&n,&k);
	k2=k*k;
	for(ll i=1;i<=n-1;i++)
		for(ll j=n;j>=0;j--)
			if(dist(i,j)){rightsp[i]=j+1;break;} 
	rightsp[0]=n+1;
	rightsp[n]=1;
	for(ll i=1;i<=n+1;i++) sumx[i]=sumx[i-1]+rightsp[i-1];
	sumfn=sumx[n+1];
	for(ll i=1;i<=n;i++) sumy[i]=sumy[i-1]+rightsp[i];
	for(ll i=0;i<=n;i++)
		for(ll j=0;j<=n;j++){
			tmp1=n+1-i;
			tmp2=n+1-j;
			ans+=max(sumx[tmp1]+sumx[tmp2]-sumfn-1,mdzz);
			if(i>0) ans+=max(sumy[i]-i,mdzz);
			if(j>0) ans+=
			ans%=1000000007;
		}
	cout<<ans<<endl;
	return 0;
}
