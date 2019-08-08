#include<bits/stdc++.h>
#define INF 2e18
#define N 10005
#define ll long long
using namespace std;
ll a[N],b[N];
ll T,n;
ll f[N][2];
ll g[N][2];
ll ans;
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++) scanf("%lld%lld",a+i,b+i);
		//for(ll i=1;i<=n;i++) f[i][0]=-INF,f[i][1]=-INF,g[];
		ans=0;
		for(ll i=1;i<=n;i++){
			if(min(f[i-1][0]+1-a[i],g[i-1][0]-b[i])>min(f[i-1][1]+1-a[i],g[i-1][1]-b[i])){
				f[i][0]=f[i-1][0]+1-a[i];
				g[i][0]=g[i-1][0]-b[i];
			}else{
				f[i][0]=f[i-1][1]+1-a[i];
				g[i][0]=g[i-1][1]-b[i];
			}
			if(min(f[i-1][0]-a[i],g[i-1][0]+1-b[i])>min(f[i-1][1]-a[i],g[i-1][1]+1-b[i])){
				f[i][1]=f[i-1][0]-a[i];
				g[i][1]=g[i-1][0]+1-b[i];
			}else{
				f[i][1]=f[i-1][1]-a[i];
				g[i][1]=g[i-1][1]+1-b[i];
			}
			ans=min(ans,max(min(f[i][0],g[i][0]),min(f[i][1],g[i][1])));
			cout<<f[i][0]<<' '<<f[i][1]<<' '<<g[i][0]<<' '<<g[i][1]<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
