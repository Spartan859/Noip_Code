#include<bits/stdc++.h>
#define N 505
#define ll long long
using namespace std;
ll n,m,a,b;
ll ck[N][N],sumall;
ll sum[N][N];//第j列的前缀和 

bool check(ll x){
	ll upx=1,hqd=0,dwx=1;
	while(upx<=n){
		for(dwx=upx;dwx<=n;dwx++){
			ll bfx=0,sumx=0;
			for(ll j=1;j<=m;j++){
				sumx+=sum[dwx][j]-sum[upx-1][j];
				if(sumx>=x) sumx=0,bfx++;
				if(bfx>=b) break;
			}
			if(bfx>=b){
				hqd++;
				break;
			}
		}
		
		upx=dwx+1;
		//if(x==3) cout<<upx<<endl;
		if(hqd>=a) return 1;
		
	}
	return 0;
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			scanf("%lld",&ck[i][j]);
			sumall+=ck[i][j];
		}
	}
	for(ll j=1;j<=m;j++)
		for(ll i=1;i<=n;i++) sum[i][j]=sum[i-1][j]+ck[i][j];
		
	ll l=0,r=sumall/(a*b)+1,mid,ans;
	//cout<<r<<endl;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)) ans=l=mid;
		else r=mid-1;
		//cout<<mid<<endl;
	}
	printf("%lld\n",ans);
	return 0;
} 
