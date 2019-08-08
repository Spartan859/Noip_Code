#include<bits/stdc++.h>
#define N 25
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll T,n,x,y,ans=0;
ll P[N],usdx[N],f[N];

void dfs(ll i){
	if(i==n+1){
		ans++;
		if(ans>=mod) ans-=mod;
		return;
	}
	if(i==x){
		usdx[y]=1;
		P[i]=y;
		for(ll j=1;j<=i-1;j++)
			if(P[j]>P[i]){
				f[i]=max(f[i],f[j]+1);
				if(f[i]>2){
					f[i]=1,P[i]=0,usdx[y]=0;
					return;
				}
			}
		dfs(i+1);
		P[i]=0;
		usdx[y]=0;
		f[i]=1;
		return;
	}
	for(ll j=1;j<=n;j++){
		if(!usdx[j]&&j!=y){
			P[i]=j;
			usdx[j]=1;
			for(ll k=1;k<=i-1;k++)
				if(P[k]>P[i]){
					f[i]=max(f[i],f[k]+1);
					if(f[i]>2){
						f[i]=1,P[i]=0,usdx[j]=0;
						return;
					}
				}
			dfs(i+1);
			P[i]=0;
			usdx[j]=0;
			f[i]=1;	
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	scanf("%lld",&T);
	fill(f+1,f+n+1,1);
	while(T--){
		ans=0;
		scanf("%lld%lld%lld",&n,&x,&y);
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
